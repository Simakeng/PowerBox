'''
This script is used to run some code generation scripts before building.

Author:                     Simakeng (simakeng@outlook.com)
Date:                       2023-10-17
Version(of this script):    0.0.1
'''
import os
import sys
import traceback
import subprocess
import os.path as path


def get_project_path(search_dir=path.dirname(__file__)):
    """get the project path by seaching for the .git folder

    Args:
        search_dir (str, optional): the directory to start searching from. Defaults to path.dirname(__file__).

    Returns:
        str: the project path
    """
    search_dir = path.abspath(search_dir)
    if '.git' in os.listdir(search_dir):
        return search_dir
    else:
        return get_project_path(path.dirname(search_dir))


PROJ_PATH = get_project_path()

SCRIPT_PATH = path.join(PROJ_PATH, "Scripts")


# def run_python_script(script_path: str, args: list = None, timeout=100.0) -> (int, str, str):
#     """Run a python script in PROJ_PATH using current interpreter

#     Args:
#         script_path (str): The relative path from the SCRIPT_PATH to the script
#         args (list, optional): The arguments to pass to the script. Defaults to [].
#         timeout (float, optional): The timeout in seconds. Defaults to 100.0.

#     Returns:
#         (int, str, str): the return code, stdout, stderr
#     """
#     if args is None:
#         args = []
#     script_path = path.join(PROJ_PATH, script_path)
#     args = [sys.executable, script_path] + args
#     proc = subprocess.Popen(
#         args,
#         stdout=subprocess.PIPE,
#         stderr=subprocess.PIPE,
#         shell=True,
#         cwd=PROJ_PATH)
#     try:
#         stdout, stderr = proc.communicate(timeout=timeout)
#     except subprocess.TimeoutExpired:
#         proc.kill()
#         stdout, stderr = proc.communicate()
#     return proc.returncode, stdout.decode('utf-8'), stderr.decode('utf-8')

def run_python_script(script_path: str, args: list = None, timeout=100.0) -> None:
    """Run a python script in PROJ_PATH using current interpreter.

    Note:
        Print the stdout and stderr. 
        Returns when retcode is 0,
        Raise an exception when retcode is not 0.

    Args:
        script_path (str): The relative path from the SCRIPT_PATH to the script
        args (list, optional): The arguments to pass to the script. Defaults to [].
        timeout (float, optional): The timeout in seconds. Defaults to 100.0.
    """
    if args is None:
        args = []
    script_path = path.join(SCRIPT_PATH, script_path)
    args = [sys.executable, script_path] + args
    proc = subprocess.Popen(
        args,
        shell=True,
        cwd=PROJ_PATH)
    try:
        proc.communicate(timeout=timeout)
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.communicate()
    retcode = proc.returncode
    if retcode != 0:
        raise Exception(f"Failed to run {script_path}\nReturn code: {retcode}")


def read_version_file(version_file_path: str = "VERSION") -> str:
    version_file_path = path.join(PROJ_PATH, version_file_path)
    with open(version_file_path, 'r') as f:
        version = f.read().strip()

    return version


def main():
    version = read_version_file()

    run_python_script('auto_version.py', [
                      "-o", "Generated/Version.h", "-v", version])

    run_python_script('logo_art.py', ["-o", "Generated/logo.h"])
    return


if __name__ == "__main__":
    orig_cwd = os.getcwd()
    try:
        main()
    except Exception as _:
        os.chdir(orig_cwd)
        _, _, tb = sys.exc_info()
        traceback.print_tb(tb)
        sys.exit(0)
