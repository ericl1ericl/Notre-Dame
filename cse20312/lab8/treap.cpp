// treap.cpp: Treap Map

#include "map.h"

#include <climits>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototypes - helper functions ------------------------------------------------------------------

Node *insert_t(Node *node, const std::string &key, const std::string &value, int priority);
Entry search_t(Node *node, const std::string &key);
extern void dump_r(Node *node, std::ostream &os, DumpFlag flag); 
Node *RotateRight(Node *node);
Node *RotateLeft(Node *node);
int maxHeight(Node *node);
int minHeight(Node *node);
void preOrder(Node *node);
int get_random();

// Methods ---------------------------------------------------------------------

void            TreapMap::insert(const std::string &key, const std::string &value) {
    //TODO
    int randval = get_random();
//    std::cout << randval << std::endl;
    root = insert_t(root, key, value, randval); 
}

const Entry     TreapMap::search(const std::string &key) {
    //TODO
    Entry x = search_t(root, key);
    return x;
}

void            TreapMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r(root, os, flag);
}

int             TreapMap::getMaxTreeHeight(){
    //TODO
    int h = 0;
    h = maxHeight(root);
    return h;
}


int             TreapMap::getMinTreeHeight(){
    //TODO
    int h = 0;
    h = minHeight(root);
    return h;
}

void            TreapMap::preOrderTraversal(){
    //TODO
    preOrder(root);
}

Node *insert_t(Node *node, const std::string &key, const std::string &value, int priority) {
    if (node == nullptr) { // if node is empty, create new Entry
        return new Node{Entry(key, value), priority, nullptr, nullptr};
    } 
    if (key == node->entry.first) { // if node matches key, update value
        node->entry.second = value;
        return node;
    }
    if (key <= node->entry.first) { // if key is less than or equal to node's key...
        node->left = insert_t(node->left, key, value, priority); // ...insert node...
        if (node->left->priority > node->priority) { // ... and rotate if necessary
            node = RotateRight(node);
        }
    }
    else {
        node->right = insert_t(node->right, key, value, priority);
        if (node->right->priority > node->priority) {
            node = RotateLeft(node);
        }
    }
    return node; 
} 

Entry search_t(Node *node, const std::string &key) {
    while(1) { // continuous loop
        if (node == nullptr) { // if node is empty, return NONE
            return NONE;
        }
        else if (node->entry.first == key) { // return entry if search matches
            return node->entry;
        }
        else if (node->entry.first > key) { // if entry is greater than search, look left
            node = node->left;
        }
        else { // if entry is less than search, look right
            node = node->right;
        }
    }
}

Node *RotateRight(Node *p) {
    Node *c = p->left; // c is parent's left child
    Node *T2 = c->right; // T2 is left child's right child
    c->right = p; // set c's right child as parent
    p->left = T2; // set parent's left child as T2
    return c; // new "root"
}

Node *RotateLeft(Node *p) {
    Node *c = p->right; // c is parent's right child
    Node *T2 = c->left; // T2 is right child's left child
    c->left = p; // set c's left child as parent
    p->right = T2; // set parent's right child as T2
    return c; // new "root"
}

int maxHeight(Node *x) {
    if (x == nullptr) { // return 0 if end of left or right branch
        return 0;
    }
    else {
        int Lh = maxHeight(x->left); // recursively go down left branch
        int Rh = maxHeight(x->right); // recursively go down right branch
        if (Rh < Lh) { // return the greater of the two branches
            return(Lh + 1); // add one for current node
        }
        else {
            return(Rh + 1);
        }
    }
}

int minHeight(Node *x) {
    if (x == nullptr) { // return 0 if end of branch
        return 0;
    }
    if (x != nullptr && x->right == nullptr && x->left == nullptr) { 
    // return one if final full node
        return 1;
    }
    if (x->left == nullptr) { // if node's left child DNE, check right
        return(minHeight(x->right) + 1);
    }
    if (x->right == nullptr) { // if node's right child DNE, check left
        return(minHeight(x->left) + 1);
    }
    if (minHeight(x->right) < minHeight(x->left)) { // return lesser height
        return minHeight(x->right);
    }
    else {
        return minHeight(x->left);
    }
/*    else {
        int Lh = minHeight(x->left);
        int Rh = minHeight(x->right);
        if (Rh < Lh) {
            return(Rh + 1);
        }
        else {
            return(Lh + 1);
        }
    } */
}

void preOrder(Node *x) {
    if (x != nullptr) { 
        std::cout << x->entry.first << ' ';
        preOrder(x->left);
        preOrder(x->right);
    }
    else {
        return;
    }
}

int get_random() {
    // srand implementation
    srand(time(NULL));
    int randval = rand() % 100000;
    return randval; 
    // given implementation
/*    static std::random_device rd;
    static std::default_random_engine g(rd());
    static std::uniform_int_distribution<> d(1, INT_MAX);
    return d(g); */
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
