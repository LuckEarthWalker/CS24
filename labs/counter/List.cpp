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

Node* List::push_back(const std::string& str_val, int num_val) {
    if (size == 0) {
        head = new Node;
        tail = head;
        head->before = nullptr;
        head->next = nullptr;
        head->str = str_val;
        head->num = num_val;
        size++;
        return head;
    }

    tail->next = new Node;
    tail->next->before = tail;
    tail = tail->next;
    tail->next = nullptr;
    tail->str = str_val;
    tail->num = num_val;
    size++;
    return tail;
}

// Node* List::find(const std::string& str_val) const {
//     Node* temp = head;
//     while (temp != nullptr && temp->str != str_val) {
//         temp = temp->next;
//     }
//     return temp;
// }

// void List::remove(const std::string& str_val) {
//     Node* temp = find(str_val);
//     if (temp == nullptr) {
//         return;
//     }
//     if (temp->before == nullptr) {
//         head = temp->next;
//         if (head != nullptr){
//             temp->next->before = nullptr;
//         }
//         delete temp;
//         temp = nullptr;
//     } else if (temp->next == nullptr) {
//         tail = temp->before;
//         temp->before->next = nullptr;
//         delete temp;
//         temp = nullptr;
//     } else {
//         temp->before->next = temp->next;
//         temp->next->before = temp->before;
//         delete temp;
//         temp = nullptr;
//     }
//     size--;
// }

void List::remove(Node* pair) {
    if (pair == nullptr) {
        return;
    }
    if (pair->before == nullptr) {
        head = pair->next;
        if (head != nullptr){
            pair->next->before = nullptr;
        }
        delete pair;
        pair = nullptr;
    } else if (pair->next == nullptr) {
        tail = pair->before;
        pair->before->next = nullptr;
        delete pair;
        pair = nullptr;
    } else {
        pair->before->next = pair->next;
        pair->next->before = pair->before;
        delete pair;
        pair = nullptr;
    }
    size--;
}

size_t List::count() const {
    return size;
}

Node* List::Head() const {
    return head;
}