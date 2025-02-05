#include "List.h"
#include <stdexcept>
#include <iostream>

const std::string str = "hello";

List::List() {
    head = NULL;
}

List::List(const List& other) {
    // size_t size = other.count();
    // Node* temp = NULL;
}

List::~List() {
    while(head != NULL) {
        Node* next_node = head->next;
        delete head;
        head = next_node;
    }
    head = NULL;
}

size_t List::count() const {
    return 1;
}

void List::insert(const std::string& value) {
    Node* temp = head;

    if (temp == NULL) { //List empty
        head = new Node;
        head->data = value;
        head->next = NULL;
        return;
    }
    if (temp->data > value) { //if insert at front
        Node* buffer = new Node;
        buffer->next = head;
        buffer->data = value;
        head = buffer;
        buffer = NULL;
        return;
    }
    while (temp->next != NULL) {
        if (temp->next->data > value) {
            Node* buffer = new Node;
            buffer->data = value;
            buffer->next = temp->next;
            temp->next = buffer;
            buffer = NULL;
            return;
        } else {
            temp = temp->next;
        }
    }
    if (temp->next == NULL) {// if at back
        Node* buffer = new Node;
        buffer->data = value;
        buffer->next = NULL;
        temp->next = buffer;
        buffer = NULL;
    }
}

const std::string& List::lookup(size_t index) const {
    return str;
}

void reverse_print(Node* current) {
    if (current->next == NULL) {
        std::cout << current->data << ", ";
        return;
    } else {
        reverse_print(current->next);
        std::cout << current->data << ", ";
    }
}

void List::print(bool reverse) const {
    if (reverse) {
        std::cout << "[";
        reverse_print(head->next);
        std::cout << head->data << "]\n";
    } else {
        Node* temp = head;
        std::cout << "[";
        while (temp != NULL) {
            if (temp->next == NULL) {//if last element
                std::cout << temp->data;
            } else {
                std::cout << temp->data << ", ";
            }
            temp = temp->next;
        }
        std::cout << "]\n";
    }
}

std::string List::remove(size_t index) {
    return "Hello";
}

size_t List::remove(const std::string& value) {
    return 1;
}