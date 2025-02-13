#include "Set.h"
#include <iostream>

Set::Set() {
    mRoot = NULL;
    mCount = 0;
}

Node* copy_tree(const Node* other) {
    if (other == NULL) {
        return NULL;
    } 

    Node* temp = new Node;
    temp->data = other->data;
    temp->left = copy_tree(other->left);
    temp->right = copy_tree(other->right);

    return temp;
}

Set::Set(const Set& other) {
    if (other.mRoot == NULL) {
        mRoot = NULL;
        mCount = 0;
    } else {
        mRoot = copy_tree(other.mRoot);
        mCount = other.mCount;
    }
}

Set::Set(Set&& other) {
    this->mRoot = other.mRoot;
    other.mRoot = NULL;
}

void del_tree(Node* temp) {
    if (temp == NULL) {
        return;
    }
    //delete left
    if (temp->left != NULL) {
        del_tree(temp->left);
    }

    // delete right
    if (temp->right != NULL) {
        del_tree(temp->right);
    }
    delete temp;
    return;
}

Set::~Set() {
    del_tree(mRoot);
}

size_t del_tree(Node* temp, int count) {
    if (temp == NULL) {
        return count;
    }
    //delete left
    if (temp->left != NULL) {
        count = del_tree(temp->left, count);
    }

    // delete right
    if (temp->right != NULL) {
        count = del_tree(temp->right, count);
    }
    delete temp;
    count++;
    return count;
}

size_t Set::clear() {
    size_t num_node = del_tree(mRoot, 0);
    mRoot = NULL;
    mCount = 0;
    return num_node;
}

bool Set::contains(const std::string& value) const {
    if (mRoot == NULL) {
        return false;
    }
    Node* temp = mRoot;
    while (temp != NULL) {
        if (temp->data == value) {
            return true;
        } else if (value < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}

size_t Set::count() const {
    return mCount;
}

void Set::debug() {
    return;
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
        std::cout << "-\n";
        return;
    }
    if (mRoot->left == NULL && mRoot->right == NULL) {
        std::cout << "" << mRoot->data << "\n";
        return;
    }
    print_tree(mRoot);
    std::cout << "\n";
}

static Node* get_parent(Node* root, Node* child) {
    if (root == child)
        return NULL;

    Node* parent = NULL;
    Node* current = root;
    while (current != NULL && current != child) {
        parent = current;
        if (child->data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return parent;
}

bool Set::swivel(const std::string& value) {
    if (mRoot == NULL)
        return false;

    Node* current = mRoot;
    Node* last = mRoot;

    while (current != NULL) {
        last = current;
        if (value == current->data)
            break;
        else if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
        current = last;
    bool found = (current->data == value);

    while (mRoot != current) {
        Node* parent = get_parent(mRoot, current);
        if (parent == NULL)
            break;  

        if (parent->left == current) {
            // Right rotation.
            parent->left = current->right;
            current->right = parent;
        } else {
            // Left rotation.
            parent->right = current->left;
            current->left = parent;
        }

        Node* grandparent = get_parent(mRoot, parent);
        if (grandparent == NULL)
            mRoot = current;
        else {
            if (grandparent->left == parent)
                grandparent->left = current;
            else
                grandparent->right = current;
        }
    }
    return found;
}

size_t Set::remove(const std::string& value) {
    if (mRoot == NULL)
        return 0;

    bool found = swivel(value);
    if (!found)
        return 0;  

    Node* toDelete = mRoot;

    // at most one child.
    if (mRoot->left == NULL || mRoot->right == NULL) {
        mRoot = (mRoot->left != NULL) ? mRoot->left : mRoot->right;
        delete toDelete;
        mCount--;
        return 1;
    }

    // two children.
    Node* leftSubtree = mRoot->left;
    
    // Promote the right subtree.
    mRoot = mRoot->right;
    delete toDelete;
    mCount--;

    // find smallest node in new tree
    Node* smallest = mRoot;
    while (smallest->left != NULL)
        smallest = smallest->left;

    // smallest node -> new root.
    swivel(smallest->data);

    mRoot->left = leftSubtree;

    return 1;
}