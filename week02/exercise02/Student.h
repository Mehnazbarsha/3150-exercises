#ifndef SIMPLE_STUDENT_H
#define SIMPLE_STUDENT_H

#include <string>
#include <ostream>

struct Student {
    Student();
    Student(const std::string & name, int number, int number_of_homeworks);
    Student(const Student & other);
    Student & operator=(const Student & other);
    ~Student();

    std::string name;
    int number;
    int * hw_grades;
    int number_of_homeworks;

    double averageHomework() const;
};

std::ostream & operator<<(std::ostream & os, const Student & student);
Student get_student_struct_data(int number_of_homeworks);

#endif
