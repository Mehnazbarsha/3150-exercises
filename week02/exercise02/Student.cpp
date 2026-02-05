#include <iostream>
#include "Student.h"

Student::Student()
    : name(""), number(0), hw_grades(nullptr), number_of_homeworks(0) {}

Student::Student(const std::string & name_in, int number_in, int number_of_homeworks_in)
    : name(name_in),
      number(number_in),
      hw_grades(nullptr),
      number_of_homeworks(number_of_homeworks_in) {
    if (number_of_homeworks > 0) {
        hw_grades = new int[number_of_homeworks];
        for (int i = 0; i < number_of_homeworks; i++) {
            hw_grades[i] = 0;
        }
    }
}

Student::Student(const Student & other)
    : name(other.name),
      number(other.number),
      hw_grades(nullptr),
      number_of_homeworks(other.number_of_homeworks) {
    if (other.hw_grades != nullptr && number_of_homeworks > 0) {
        hw_grades = new int[number_of_homeworks];
        for (int i = 0; i < number_of_homeworks; i++) {
            hw_grades[i] = other.hw_grades[i];
        }
    }
}

Student & Student::operator=(const Student & other) {
    if (this == &other) {
        return *this;
    }
    delete [] hw_grades;
    name = other.name;
    number = other.number;
    number_of_homeworks = other.number_of_homeworks;
    hw_grades = nullptr;
    if (other.hw_grades != nullptr && number_of_homeworks > 0) {
        hw_grades = new int[number_of_homeworks];
        for (int i = 0; i < number_of_homeworks; i++) {
            hw_grades[i] = other.hw_grades[i];
        }
    }
    return *this;
}

Student::~Student() {
    delete [] hw_grades;
}

double Student::averageHomework() const {
    if (number_of_homeworks <= 0 || hw_grades == nullptr) {
        return 0.0;
    }
    int sum = 0;
    for (int i = 0; i < number_of_homeworks; i++) {
        sum += hw_grades[i];
    }
    return static_cast<double>(sum) / number_of_homeworks;
}

Student get_student_struct_data(int number_of_homeworks) {
    std::string name;
    int number;

    std::cout << "Enter name: " << std::endl;
    std::cin >> name;

    std::cout << "Enter student ID: " << std::endl;
    std::cin >> number;

    Student student(name, number, number_of_homeworks);

    for (int i = 0; i < number_of_homeworks; i++) {
        std::cout << "Enter homework score " << (i + 1) << ": " << std::endl;
        std::cin >> student.hw_grades[i];
    }

    return student;
}

std::ostream & operator<<(std::ostream & os, const Student & student) {
    os << student.name
       << " (ID " << student.number << ")"
       << " homework scores:";

    for (int i = 0; i < student.number_of_homeworks; i++) {
        os << " " << student.hw_grades[i];
    }

    return os;
}
