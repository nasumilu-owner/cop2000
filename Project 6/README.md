# COP2000 - Project 6

## Description
Simple program that introduces OOP with C++ by creating a 
`Rectangle` class. The class is then initalized with user 
inputted values.

## Usage
```bash
$ cd <project dir>
$ g++ project6.cpp -o bin/project6
$ ./bin/project6
```
Expected output:
```bash
Please enter the rectangles length: 10
Please enter the rectangles width: 10
The rectangle has a length of 0.00 & a width of 0.00 making it's perimeter equal to 0.00 and an area of 0.00.
THe length has been set to 10.00 using the private setLength member function!
The width has been set to 10.00 using the private setWidth member function!
The rectangle now has a length of 10.00 & a width of 10.00 making it's perimeter equal to 40.00 and an area of 100.00.
```

## Note
- The project required the use of an OS dependent system command "pause".
If compiled and used on a system which does not support the "pause" command
the program will output the following:
```bash
sh: PAUSE: command not found
```

- Project required a single file so no header files are include.