# COP2000 - Project 2

## Description
Program performs some simple calculates from user input to find
the area of a circle, parallelogram, and triangle.

## Usage

```bash
$ cd <project dir>
$ g++ project2.cpp -o bin/project2
$ ./bin/project2
```
Expected output
```bash
Find the Area!

Circle:

Enter the radius value in inches: 25

The area of a circle with a radius of 25.00 inches is: 1963.49

Rectangle:

Enter the length in inches: 25

Enter the width in inches: 25

The area of a rectangle with a length of 25.00 inches and a width of 25.00 is: 625.00

Triangle:

Enter the base in inches: 15

Enter the height in inches: 10

The are of a triangle with a base of 15.00 and a height of 15.00 inches is: 75.00
```
## Note
The project required the use of an OS dependent system command "pause".
If compiled and used on a system which does not support the "pause" command
the program will output the following:
```bash
sh: PAUSE: command not found
```