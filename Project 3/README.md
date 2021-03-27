# COP2000 - Project 3

## Description
Lists the freezing and boiling points of several substances

## Usage
```bash
$ cd <project dir>
$ g++ project3.cpp -o bin/project3
$ ./bin/project3
```
Expected output
```bash
Freezing and Boiling Points

Enter a temperature in Fahrenheit: -370

Freezing:       Ethyl Alcohol; Oxygen; Mercury; Water; 

Boiling:        None Found!
```

## Note
The project required the use of an OS dependent system command "pause".
If compiled and used on a system which does not support the "pause" command
the program will output the following:
```bash
sh: PAUSE: command not found
```