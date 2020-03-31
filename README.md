### About pycryptor
**pycryptor** is a commercial solution for the encryption of python code file. pycryptor encrypt python source code using RC4, which is a fast and highly secure data encryption algorithm. The encrypted python file can not be executed by the offical python interpreter. To enable the execution of the encypted python file, we embedded the decryption code in the python interpreter so that it can execute both the source code and the encrypted code.

**pycryptor is very secure.**   
Using pycryptor, your source code files are encrypted with your own key (64 bytes). Without the leak of your own key, it's almost impossible for anyone else to decrypt your code files.

**pycryptor is easy to use.**  
You do not need to consider how to protect your code in the development process. To deliver your python app to your customers or deploy your python app on a server or a public cloud, you only need to encrypt your python app by pycryptor and replace the python interpreter of the host computer with the python interpreter provide by us.

**pycryptor supports both python2 and python3**  
You can use pycryptor to encrypt your python2 source code and python3 source code. We provide both python2 and python3 interpreters so you are free to choose python2 or python3 in your projects.

### Install pycryptor
**Step1:** Download pycryptor.
```
git clone https://github.com/pycryptor123/pycryptor.git
```
**Step2:** Build your own version of pycryptor.  
Replace the key in the pycrpt.h (line 12) with your own key, then make:

```
cd /path/to/pycryptor
make
```
You will find two execuable binary files `pycryptor` and `pydecrypt` in the current directory, which is your own pycryptor program.

Please keep these two binary files private. Your own key is included in these binary files and it's not a hard work for a cracker to extract your own key from these two files.

**Step3:** Install new Python2 and Python3 interpreter 
We will provide our new versions of python2 and 3 to you (rpm/deb package). It's very easy to install them on your computer.

### Encrypt/decrypt your python code file
Encryte a python code file:
```
pycryptor <hello.py> <hello_enc.py>
```
The encrypted python file MUST have suffix .py. Do not use .pye or other suffix.


Decrypt a encrypted python code file:
```
pydecrypt <enc.py>
```

Encrypt a python project:
```
python pycryptor_dir.py <input-dir> <output-dir>
```
Using this command, you can encrypt all python files in a directoy. The directory structure and filenames of the output directory are same with the input directory.  

### Run the encrypted python code files
The way to run the encrypted code files is completely same as the way we execute the python source files.


### Format of the encrypted python file
```
[byte 1-4]      pye_
[byte 5-8]      key sn (4-digits)
[byte 9-32]     random numbers
[byte 33- end]  encrypted python code
```

### Python interpreters we provide
```
  Python-2.7.17
  Python-3.7.6
```

### Contact us
Please contact us if you intend to build your own pycryptor to encrypt your python code.

Email: pycrypt@163.com

QQ: 120017171
