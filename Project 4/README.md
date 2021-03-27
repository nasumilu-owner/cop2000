# COP2000 - Project 4

## Description
Console style population histogram for five inputed values.

## Usage
```bash
$ cd <project dir>
$ g++ project4.cpp -o bin/project4
$ ./bin/project4
```
Expected output
```bash
POPULATION BAR CHART
(Each * = 1000000)
Country 1: *
Country 2: **
Country 3: ***
Country 4: ****
Country 5: ******
```

## Note
- The project required the use of an OS dependent system command "pause".
If compiled and used on a system which does not support the "pause" command
the program will output the following:
```bash
sh: PAUSE: command not found
```
- Program's output is formated using colorized text