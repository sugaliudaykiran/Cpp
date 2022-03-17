
/*
Implementation of Preorder Traversal    :-
    In this, we discuss a function that takes root as a parameter, whose return type is void 
        and is supposed to print Preorder traversal of the Tree whose nodes are given.

    Preorder Traversal  - (root, left, right)..

*/ 


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

    Node(int k){
        key = k;
        right = left = NULL;
    }
};                                                                                  

//      Preorder Traversal  :-  (root, left, right)
void preorder(Node *root){      //  TC -> O(N)..        AS -> O(h).. recursive function_calls.
    if (root != NULL){
        cout << root -> key << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);

    preorder(root);

    return 0;
}