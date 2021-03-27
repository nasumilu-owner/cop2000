# COP2000 - Project 8

## Description


## Usage
```bash
$ cd <project dir>
$ g++ project8.cpp -o bin/project8
$ ./bin/project8
```
Expected output:
```bash

  Random Number File Reader and Sorter

+---------------------------------------+
| Total Even Numbers:    99             |
| Total Odd Numbers:     101            |
+-------------------+-------------------+
| Even Numbers      | Odd Numbers       |  
+-------------------+-------------------+
|         8         |         7         |
|        22         |        21         |
|        22         |        31         |
|        32         |        41         |
|        36         |        53         |
 
 ... Omitted for brevity

|       996         |       963         |
|      1000         |       967         |
|        -          |       967         |
|        -          |       987         |
+-------------------+-------------------+
```

## Note
- The project required the use of an OS dependent system command "pause".
If compiled and used on a system which does not support the "pause" command
the program will output the following:
```bash
sh: PAUSE: command not found
```
- Program reads a single file named 'Random.txt' found in the current directory
- Project required a single file so no header files are include.