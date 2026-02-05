#include <iostream>
#include <vector>
#include "Student.h"

int main() {
    std::vector<Student> all_students;

    int number_of_students;
    int number_of_homeworks;

    std::cout << "Enter the number of students: " << std::endl;
    std::cin >> number_of_students;

    std::cout << "Enter the number of homeworks: " << std::endl;
    std::cin >> number_of_homeworks;

    for (int i = 0; i < number_of_students; i++) {
        Student student = get_student_struct_data(number_of_homeworks);
        all_students.push_back(student);
    }

    for (const auto & student : all_students) {
        std::cout << student << std::endl;
    }

    const char * green = "\033[32m";
    const char * yellow = "\033[33m";
    const char * red = "\033[31m";
    const char * reset = "\033[0m";

    std::cout << "\nSummary\n";
    std::cout << "Name (Number) | Homework Avg | Scores\n";
    std::cout << "--------------------------------------\n";

    for (const auto & student : all_students) {
        double avg = student.averageHomework();
        const char * color = red;
        if (avg >= 85.0) {
            color = green;
        } else if (avg >= 70.0) {
            color = yellow;
        }

        std::cout << student.name << " (" << student.number << ")"
                  << " | " << color << avg << reset << " |";
        for (int i = 0; i < student.number_of_homeworks; i++) {
            std::cout << " " << student.hw_grades[i];
        }
        std::cout << std::endl;
    }

    return 0;
}