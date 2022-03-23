/*
        Convert Binary Tree to Doubly Linked List   :-
In this, we discuss:
    Inorder conversion of Binary Tree to Doubly Linked List.
    A function that takes root of a Binary Tree and converts it into a Doubly linked list.

Hint:- we need to do the inorder traversal of the Tree and while doing inorder traversal 
        we can simply maintain a previous pointer or reference of the previously traversed node.
        And change right child of the previous node to current node and left child of current node as previous.

    1) This is an inplace which means which out using extra space..
    2) We need to return DLL and it's head so order which DLL is "inorder traversal" of tree..
    3) inorder means (left subtree, root, right subtree)..
    4) In this "left be prev, right will be next".. 

*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};

//          Print Linked List :-
void printLL(Node *head){
    if (head == NULL){
        return;
    }
    while (head != NULL){
        cout << head -> key << " ";
        head = head -> right;
    }cout << endl;
}

//         BT to DLL :-     Inorder Traversal  TC -> O(n).. AS -> O(h)..
Node *BTtoDLL(Node *root){
    if (root == NULL)   return root;
    static Node *prev = NULL;      //  To acessing prev in each functional calls.. 

    Node *head = BTtoDLL(root -> left);
    if (prev == NULL)   head = root;    //  for identify the head of DLL..
    else {
        root -> left = prev;
        prev -> right = root;
    }
    prev = root;    //  update prev in every node..
    BTtoDLL(root -> right);

    return head;
}


int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right = new Node(30);
    root -> right -> left = new Node(60);
    
    Node *head = BTtoDLL(root);
    printLL(head);
    return 0;
}