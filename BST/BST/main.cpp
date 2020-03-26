  //
//  main.cpp
//  BST
//
//  Created by 鍾安 on 2018/1/26.
//  Copyright © 2018年 鍾安. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

class Node {
public:
    Node() { }
    Node(int input_val, Node* Lc, Node* Rc) { val = input_val; Lptr = Lc; Rptr = Rc;}
    ~Node() { delete Lptr; delete Rptr;}
    
    int val;
    Node *Lptr = NULL;
    Node *Rptr = NULL;
    Node *parant = NULL;
};

class BST {
public:
    BST() { }
    ~BST() { }
    
    bool Insert(int val);
    Node* Find(int val);
    bool Delete(int val);
    void Clear(void);
    
    void PreOrder(void);
    void PostOrder(void);
    void PreOrderFOR(void);
private:
    Node* rootPtr = NULL;
    void Clear(Node* ptr);
    void PreOrder(Node* ptr);
    void PostOrder(Node* ptr);
};

void BST::PreOrderFOR(void) {
    stack<Node*> sta;
    
    sta.push(rootPtr);
    while (!sta.empty()) {
        Node* newPtr = sta.top(); sta.pop();
        
        if ( newPtr != NULL) {
            printf("%d\n", newPtr->val);
            sta.push(newPtr->Rptr);
            sta.push(newPtr->Lptr);
        }
    }
}

void BST::PreOrder(Node* ptr) {
    if ( ptr == NULL) return;
    printf("%d\n", ptr->val);
    PreOrder(ptr->Lptr);
    PreOrder(ptr->Rptr);
}
void BST::PreOrder() {
    PreOrder(rootPtr);
}

void BST::PostOrder(Node* ptr) {
    if (ptr == NULL) return;
    PostOrder(ptr->Lptr);
    PostOrder(ptr->Rptr);
    printf("%d\n", ptr->val);
}
void BST::PostOrder() {
    PostOrder(rootPtr);
}

void BST::Clear(Node* ptr) {
    if ( ptr->Lptr != NULL) Clear(ptr->Lptr);
    if ( ptr->Rptr != NULL) Clear(ptr->Rptr);
    if ( ptr->parant != NULL) {
        ptr->parant->Lptr = NULL;
        ptr->parant->Rptr = NULL;
    }
    delete ptr;
}
void BST::Clear() {
    Clear(rootPtr);
}

Node* BST::Find(int val) {
    Node* ptr = rootPtr;
    while (ptr != NULL && ptr->val != val) {
        if (ptr->val < val) ptr = ptr->Rptr;
        if (ptr->val > val) ptr = ptr->Lptr;
    }
    return ptr;
}

bool BST::Insert(int val) {
    if ( rootPtr == NULL) {
        Node* temp = new Node;
        temp->val = val;
        rootPtr = temp;
        return true;
    }
    else {
        Node* ptr = rootPtr;
        Node* parent = NULL;
        
        while (ptr != NULL) {
            if ( ptr->val == val) return false;
            parent = ptr;
            if ( ptr->val < val)
                ptr = ptr->Rptr;
            else if ( ptr->val > val)
                ptr = ptr->Lptr;
        }
        
        Node* temp = new Node;
        temp->val = val;
        temp->parant = parent;
        if ( val > parent->val ) {
            parent->Rptr = temp;
        }
        else {
            parent->Lptr = temp;
        }
        return true;
    }
}

bool BST::Delete(int val) {
    Node* target = Find(val);
    if ( target == NULL ) return false;

    Node* ptr = target->Rptr;
    for (; ptr->Lptr != NULL; ptr = ptr->Lptr);
    
    target->val = ptr->val;
    if ( ptr->Rptr != NULL) ptr->parant->Lptr = ptr->Rptr;
    
    delete ptr;
    return true;
}

int main(int argc, const char * argv[]) {
    BST tempT;

    //build BST
    /*
         10  <-- rootPtr
        /  \
       3   14
      / \
     2   7
        / \
       5   8
      / \   \
     4  6    9
     */
    tempT.Insert(10);
    tempT.Insert(3);
    tempT.Insert(14);
    tempT.Insert(2);
    tempT.Insert(7);
    tempT.Insert(5);
    tempT.Insert(4);
    tempT.Insert(6);
    tempT.Insert(8);
    tempT.Insert(9);

    //preOrder and postOrder
    printf("pre_order:\n");
    tempT.PreOrder();
    printf("pre_order(stack):\n");
    tempT.PreOrderFOR();
    printf("post_order:\n");
    tempT.PostOrder();

    //Delete
    tempT.Delete(3);
    printf("preOrder:\n");
    tempT.PreOrder();
    
    //Find
    Node *tempPtr = tempT.Find(1);
    Node *tempPtr2 = tempT.Find(5);
    printf("1 is in BST:%d\n", tempPtr != NULL);
    printf("5 is in BST:%d\n", tempPtr2 != NULL);

    //Clear
    tempT.Clear();
    
    return 0;
}




