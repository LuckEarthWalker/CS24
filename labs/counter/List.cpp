#include "List.h"

List::List() {
    head = nullptr;
    tail = head;
    size = 0;
}

List::~List() {
    while (head != nullptr) {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
    tail = nullptr;
    size = 0;
}

void List::push_back(const std::string& str_val, int num_val) {
    if (size == 0) {
        head = new Node;
        tail = head;
        head->before = nullptr;
        head->next = nullptr;
        head->str = str_val;
        head->num = num_val;
        size++;
        return;
    }

    tail->next = new Node;
    tail->next->before = tail;
    tail = tail->next;
    tail->next = nullptr;
    tail->str = str_val;
    tail->num = num_val;
    size++;
}

Node* List::find(const std::string& str_val) const {
    Node* temp = head;
    while (temp != nullptr && temp->str != str_val) {
        temp = temp->next;
    }
    return temp;
}

void List::remove(const std::string& str_val) {
    Node* temp = find(str_val);
    temp->before->next = temp->next;
    temp->next->before = temp->before;
    delete temp;
    temp = nullptr;
}

size_t List::count() const {
    return size;
}

Node* List::Head() const {
    return head;
}