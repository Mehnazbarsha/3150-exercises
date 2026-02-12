#ifndef SIMPLE_STUDENT_H
#define SIMPLE_STUDENT_H

#include <string>
#include <ostream>

struct Student {
    std::string name;
    int number;
    int * hw_grades;
    int number_of_homeworks;

    Student(const std::string & name, int number, int number_of_homeworks);
    Student(const Student & other);
    ~Student();
};

struct StudentNode {
    Student student;
    StudentNode * next;
};

std::ostream & operator<<(std::ostream & os, const Student & student);
Student get_student_struct_data(int number_of_homeworks);
void printAllStudents(StudentNode * head);
void deleteList(StudentNode *& head);

#endif
