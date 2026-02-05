# Week 02 - Exercise 02 

## Description
A student has:
- a name
- a student ID 
- a dynamically allocated array of homework scores

The number of homework scores is provided to the constructor.

## What This Program Does
- Separates the Student struct declaration (`Student.h`) from its definition (`Student.cpp`)
- Requests the number of students
- Requests input for each student
- Prints all students
- Prints a simple summary table with each student’s homework average
- Shows the homework average in color (green/yellow/red) based on performance
- Adds a small helper function to compute the homework average

## Files
- `exercise02/Student.h`: struct declaration
- `exercise02/Student.cpp`: struct definition and input/print helpers
- `exercise02/StudentMain.cpp`: main program
- `exercise02/TestStudent.cpp`: edge case tests

## Build and Run
Main program:
```bash
g++ -std=c++17 -Wall -Wextra -pedantic StudentMain.cpp Student.cpp -o student_app
./student_app
```

Test program:
```bash
g++ -std=c++17 -Wall -Wextra -pedantic TestStudent.cpp Student.cpp -o student_tests
./student_tests
```

## Edge Cases Tested
- zero homeworks
- one homework
- two homeworks
- all max scores
- all min scores
