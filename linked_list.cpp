#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push_front(int value) {
    //create a new newNode with the value 
    Node* newNode = new Node(value);
    //begin by instering the newNode infront of the head
    newNode->next = head;
    //now update so that the new node becomes the head by having the head pointer point to the newNode
    head = newNode;
   
}

void LinkedList::push_back(int value) {
    //create a newNode with the value and name head current
    Node* newNode = new Node(value);
    Node* current = head;

    //check if the list is empty
    if(is_empty() == true){
        head = newNode;
    }
    //scootch your way down the list until you reach the end
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::pop_front() {
    //name the original head
    Node* ogHead = head;
    //whatever the original head points to becomes the new head
    head = ogHead->next;
    //get rid of the original 
    delete ogHead;
}

void LinkedList::pop_back() {
    Node* current = head;
    //scootch your way down the list until you are at the second to last node which points to the tail
    while(current->next->next != nullptr){
        current = current->next;
    }

    //change the pointer of the second to last, so that it now points to null
    current->next = nullptr;

    //name the pointer to the original tail so that it can be deleted
    Node* ogTail = current->next;
    delete ogTail;
}

bool LinkedList::is_empty() const {
    return head == nullptr;
}

int LinkedList::size() const {
    int count = 0;
    Node* current = head;
    //loop through the list adding one to count for each node that isnt nullptr
    while(current != nullptr){
        count ++;
        current = current->next;
    }
    return count; 
}

void LinkedList::remove(int value) {
    Node* current = head;
    Node* beGone;

    if(head->data == value){
        Node* ogHead = head;
        head = ogHead->next;
        delete ogHead; 
    }
    else{
    //scootch through list until you reach the key value which is then nammed beGone
        while(current->next != nullptr){
            if(current->next->data == value){
            beGone = current->next;
            //stiches the list back together before deleting the node with the value
            current->next = current->next->next;
            delete beGone;
            }
        current = current->next;
        }
    }
}

void LinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

LinkedList::Node* LinkedList::get_head() const {
    return head;
}