# Exercise 03 - Students and Linked Lists

## Description
A student has:
- a name
- a student ID number
- a dynamically allocated array of homework scores

The number of homework scores is provided to the constructor.

## What This Program Does
- Separates the Student struct declaration (`Student.h`) from its definition (`Student.cpp`)
- Uses a dynamically allocated linked list to store students
- Requests the number of students
- Requests the number of homeworks per student
- Requests input for each student
- Prints all students from the linked list
- Properly cleans up all dynamically allocated memory

## Files
- `Student.h`: struct declaration
- `Student.cpp`: struct definition and linked list functions
- `StudentMain.cpp`: main program
- `TestStudent.cpp`: edge case tests

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