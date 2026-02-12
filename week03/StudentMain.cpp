#include <iostream>
#include "Student.h"

int main() {
    StudentNode * head = nullptr;
    int number_of_students;
    int number_of_homeworks;

    std::cout << "How many students will be entered? ";
    std::cin >> number_of_students;

    std::cout << "How many homeworks per student? ";
    std::cin >> number_of_homeworks;

    // Input students and add to linked list
    for (int i = 0; i < number_of_students; i++) {
        Student student = get_student_struct_data(number_of_homeworks);
        
        // Create new node and add to list
        StudentNode * newNode = new StudentNode{student, nullptr};
        
        if (head == nullptr) {
            head = newNode;
        } else {
            StudentNode * current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Print all students
    std::cout << "\nAll Students:" << std::endl;
    printAllStudents(head);

    // Clean up memory
    deleteList(head);

    return 0;
}
