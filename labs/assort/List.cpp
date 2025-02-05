#include "List.h"
#include <stdexcept>
#include <iostream>

const std::string str = "hello";

List::List() {
    head = NULL;
}

List::List(const List& other) {
    Node* temp = other.head;

    Node* buffer = NULL;
    if(temp != NULL) {
        buffer = new Node;
        buffer->data = temp->data;
        buffer->next = NULL;
        head = buffer;
    } else { // case of trying to copy empty list
        head = NULL;
        return;
    }
    while (temp->next != NULL) {
        buffer->next = new Node;
        buffer->next->data = temp->next->data;
        buffer->next->next = NULL;

        buffer = buffer->next;
        temp = temp->next;
    }
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
    size_t size = 0;
    Node* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    temp = NULL;
    return size;
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
    if (index > this->count()-1 || this->count() == 0) {
        throw std::out_of_range("out of range index");
    }
    Node* temp = head;
    size_t i = 0;
    while (temp != NULL && i < index) {
        temp = temp->next;
        i++;
    }
    return temp->data;
}

void reverse_print(Node* current) {
    if (current == NULL) {
        return;
    } else {
        reverse_print(current->next);
        std::cout << current->data << ", ";
    }
}

void List::print(bool reverse) const {
    if (reverse && head != NULL) {
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
    if (index > this->count()-1 || this->count() == 0) {
        throw std::out_of_range("out of range index");
    }

    if (index == 0) {
        std::string return_str = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        return return_str;
    }
    Node* temp = head;

    size_t i = 1;
    while (temp->next != NULL && i < index) {
        temp = temp->next;
        i++;
    }
    Node* buffer = temp->next;
    std::string return_str = buffer->data;
    temp->next = temp->next->next;
    delete buffer;
    buffer = NULL;
    temp = NULL;

    return return_str;
}

size_t List::remove(const std::string& value) {
    size_t num_rm = 0;
    Node* temp = head;
    if (temp == NULL) {
        return num_rm;
    }
    if (temp->data == value && temp != NULL) {
        head = head->next;
        delete temp;
        num_rm++;
    }
    while (temp->next != NULL) {
        if (temp->next->data == value) {
            Node* buffer = temp->next;
            temp->next = temp->next->next;
            delete buffer;
            num_rm++;
        } else {
            temp = temp->next;
        }
    }
    return num_rm;
}