#ifndef LIST_H
#define LIST_H

#include <string>

struct Node {
    Node* next;
    Node* before;
    std::string str;
    int num;
};

class List {
private:
    Node* head;
    Node* tail;
    size_t size;

public:
    List();
    ~List();

    void push_back(const std::string& str_val, int num_val);
    void remove(const std::string& str_val);
    Node* find(const std::string& str_val) const;
    Node* Head() const;
    size_t count() const;


};

#endif
