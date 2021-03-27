# COP2000 - Project 5

## Description
Payroll report for the fictitious company XYZ, Inc.

## Usage
```bash
$ cd <project dir>
$ g++ project5.cpp -o bin/project5
$ ./bin/project5
```
Expected output:
```bash
XYZ Corporation
Weekly payroll report

1111    $  747.77
2222    $  592.19
3333    $ 1039.14
4444    $  540.00
5555    $  419.25
6666    $  255.96
7777    $ 2427.54
8888    $ 1622.40
9999    $ 1306.98

Total:  $ 8951.23
```

## Note
- The project required the use of an OS dependent system command "pause".
If compiled and used on a system which does not support the "pause" command
the program will output the following:
```bash
sh: PAUSE: command not found
```
- Program's expects input file to be in the current working directory and is
named 'weeklyMar9.txt'. 