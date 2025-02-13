#include "Set.h"
#include <iostream>

Set::Set() {
    mRoot = NULL;
    mCount = 0;
}

Set::Set(const Set& other) {}

Set::Set(Set&& other) {}

Set::~Set() {}

size_t Set::count() const {
    return mCount;
}

size_t Set::insert(const std::string& value) {
    if (mRoot == NULL) { // inserting into an empty tree
        mRoot = new Node;
        mRoot->data = value;
        mRoot->left = NULL;
        mRoot->right = NULL;
        mCount++;
        return 1;
    }
    Node* temp = mRoot;
    while (temp != NULL) {
        if (temp->data == value) {
            return 0;
        } else if (value < temp->data && temp->left == NULL) {
            temp->left = new Node;
            temp->left->data = value;
            temp->left->left = NULL;
            temp->left->right = NULL;
            mCount++;
            return 1;
        } else if (temp->data < value && temp->right == NULL) {
            temp->right = new Node;
            temp->right->data = value;
            temp->right->left = NULL;
            temp->right->right = NULL;
            mCount++;
            return 1;
        } else if (value < temp->data && temp->left != NULL) {
            temp = temp->left;
        } else if (temp->data < value && temp->right != NULL) {
            temp = temp->right;
        }
    }
    return 0;
}

void print_tree(Node* temp) {
    std::cout << "(";
    //print left side
    if (temp->left == NULL) {
        std::cout << "-";
    } else if (temp->left->left == NULL && temp->left->right == NULL) {
        std::cout << temp->left->data;
    } else {
        print_tree(temp->left);
    }

    //print middle
    std::cout << " " << temp->data << " ";

    //print right side
    if (temp->right == NULL) {
        std::cout << "-";
    } else if (temp->right->left == NULL && temp->right->right == NULL) {
        std::cout << temp->right->data;
    } else {
        print_tree(temp->right);
    }

    std::cout << ")";
    return;
}

void Set::print() const {
    if (mRoot == NULL) {
        std::cout << "(-)\n";
        return;
    }
    if (mRoot->left == NULL && mRoot->right == NULL) {
        std::cout << "(" << mRoot->data << ")\n";
        return;
    }
    print_tree(mRoot);
    std::cout << "\n";
}