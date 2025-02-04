#include "List.h"
#include <stdexcept>

List::List() {
    head = NULL;
}

List::List(const List& other) {
    size_t size = other.count();
    Node* temp;
}

List::~List() {
    Node* next_node = head->next;
    while(head != NULL) {
        delete head;
        head = next_node;
        next_node = next_node->next;
    }
    head = NULL;
}

void List::insert(const std::string& value) {
    Node* temp = head;

    if (temp->next == NULL) {
        head = new Node;
        head->data = value;
        head->next = NULL;
        return;
    }
    if (temp->next != NULL && temp->data > value) {
        Node* buffer = new Node;
        buffer->next = head;
        buffer->data = value;
        head = buffer;
        buffer = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        if (temp->next->data < value) {
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
}