#include <iostream>
#include "linked_list.h"

int main() {
    LinkedList test_list;

    // Test push_front and create list
    test_list.push_front(7);
    test_list.push_front(8);
    std::cout << "After push_front: ";
    test_list.display();

    // Test push_back
    test_list.push_back(47);
    test_list.push_back(5);
    std::cout << "After push_back: ";
    test_list.display();

    // Test pop_front
    test_list.pop_front();
    test_list.pop_front();
    std::cout << "After pop_front: ";
    test_list.display();

    // Test pop_back
    test_list.pop_back();
    std::cout << "After pop_back: ";
    test_list.display();

    // Test remove
    test_list.remove(3);
    std::cout << "After remove: ";
    test_list.display();

    // Test is_empty and size
    std::cout << "Is list empty? " << (test_list.is_empty() ? "Yes" : "No") << std::endl;
    std::cout << "List size: " << test_list.size() << std::endl;

    // Test clear
    test_list.clear();
    std::cout << "After clear: ";
    test_list.display();
    std::cout << "Is list empty? " << (test_list.is_empty() ? "Yes" : "No") << std::endl;

    return 0;
}