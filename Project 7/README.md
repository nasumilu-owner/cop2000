# COP2000 - Project 7

## Description
Decrypts a message from a file in a very deterministic manner. The code
includes example of c++ inheritance.

## Usage
```bash
$ cd <project dir>
$ g++ project7.cpp -o bin/project7
$ ./bin/project7
```
Expected output:
```bash
Decryption of file contents:

imagination
```

## Note
- The project required the use of an OS dependent system command "pause".
If compiled and used on a system which does not support the "pause" command
the program will output the following:
```bash
sh: PAUSE: command not found
```

- Project required a single file so no header files are include.
- The `BitMaskEncryptor` class is not used but was added to test 
and practice extending c++ classes.