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

    Node* push_back(std::string_view str_val, int num_val);
    // void remove(std::string_view str_val);
    void remove(Node* pair);
    // Node* find(std::string_view str_val) const;
    Node* Head() const;
    size_t count() const;


};

#endif
