#!/usr/bin/python
import os
import sys
from shutil import copyfile


usage = """
Encrypt all python files in a directory

Usage: python pycryptor_dir.py <input-dir> <ouput-dir>

All the python files in input-dir will be encrypted. All non-python files
will be copied to the output-dir. Diretories and filenames of the output-dir
are same with the input-dir.
"""

def pyencrypt(source_file, target_file):
    path = os.path.split(os.path.realpath(__file__))[0]
    pycryptor = path + '/pycryptor'
    command = "%s %s %s" % (pycryptor, source_file, target_file)
    os.system(command)


def is_python_source(file):
    if not file.endswith('.py'):
        return 0

    fp = open(file, 'r')
    buf = fp.read(4)
    fp.close
    if buf == 'pye_':
        return 0

    return 1


def encrypt_all(input_dir, output_dir):
    if not os.path.exists(output_dir):
        os.mkdir(output_dir)

    files = os.listdir(input_dir)
    for file in files:
        inf = input_dir + '/' + file
        out = output_dir + '/' + file
        if os.path.isfile(inf):
            if is_python_source(inf):
                #print("encrpyt %s" % inf)
                pyencrypt(inf, out)
            else:
                #print("copy %s" % inf)
                copyfile(inf, out)

        if os.path.isdir(inf):
            encrypt_all(inf, out)


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print(usage)
        sys.exit(1)

    input_dir = sys.argv[1].strip('/')
    output_dir = sys.argv[2].strip('/')

    if not os.path.isdir(input_dir):
        print("__error__: %s is not a directory" % input_dir)
        sys.exit(1)

    """
    if os.path.isdir(output_dir) and os.listdir(output_dir):
        print("__error__: %s is not an empty dir" % output_dir)
        sys.exit(1)
    """
    path = os.path.split(os.path.realpath(__file__))[0]
    pycryptor = path + '/pycryptor'
    if not os.path.exists(pycryptor):
        print("__error__: pycryptor does not exist")
        sys.exit(1)

    encrypt_all(input_dir, output_dir)
