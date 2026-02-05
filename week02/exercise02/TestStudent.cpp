#include <iostream>
#include "Student.h"

int main() {
    Student zero_hw("Zero", 1001, 0);
    std::cout << "Zero homeworks: " << zero_hw << std::endl;

    Student one_hw("One", 1002, 1);
    one_hw.hw_grades[0] = 95;
    std::cout << "One homework: " << one_hw << std::endl;

    Student two_hw("Two", 1003, 2);
    two_hw.hw_grades[0] = 70;
    two_hw.hw_grades[1] = 80;
    std::cout << "Two homeworks: " << two_hw << std::endl;

    Student max_scores("Max", 1004, 3);
    max_scores.hw_grades[0] = 100;
    max_scores.hw_grades[1] = 100;
    max_scores.hw_grades[2] = 100;
    std::cout << "All max: " << max_scores << std::endl;

    Student min_scores("Min", 1005, 3);
    min_scores.hw_grades[0] = 0;
    min_scores.hw_grades[1] = 0;
    min_scores.hw_grades[2] = 0;
    std::cout << "All min: " << min_scores << std::endl;

    return 0;
}
