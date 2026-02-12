#include <iostream>
#include "Student.h"

int main() {
    std::cout << "=== Edge Case Tests ===" << std::endl;

    // Test 1: Zero homeworks
    std::cout << "\n1. Zero homeworks:" << std::endl;
    Student s1("Alice", 1001, 0);
    std::cout << s1 << std::endl;

    // Test 2: One homework
    std::cout << "\n2. One homework:" << std::endl;
    Student s2("Bob", 1002, 1);
    s2.hw_grades[0] = 95;
    std::cout << s2 << std::endl;

    // Test 3: Two homeworks
    std::cout << "\n3. Two homeworks:" << std::endl;
    Student s3("Charlie", 1003, 2);
    s3.hw_grades[0] = 70;
    s3.hw_grades[1] = 80;
    std::cout << s3 << std::endl;

    // Test 4: All max scores
    std::cout << "\n4. All max scores:" << std::endl;
    Student s4("Max", 1004, 3);
    s4.hw_grades[0] = 100;
    s4.hw_grades[1] = 100;
    s4.hw_grades[2] = 100;
    std::cout << s4 << std::endl;

    // Test 5: All min scores
    std::cout << "\n5. All min scores:" << std::endl;
    Student s5("Min", 1005, 3);
    s5.hw_grades[0] = 0;
    s5.hw_grades[1] = 0;
    s5.hw_grades[2] = 0;
    std::cout << s5 << std::endl;

    std::cout << "\n=== All Tests Complete ===" << std::endl;
    return 0;
}