/*
Implementation of Postorder Traversal   :-
    In this video, we discuss a function that takes root as a parameter, 
        whose return type is void and is supposed to print Postorder traversal of the Tree
        whose nodes are given.

    Postorder :- (left, right, root)..

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

//  Postorder traversal     :-      TC -> O(n).. AS -> O(h).. we can say that 0(n) and 0(h)..
void postorder(Node *root){
    if (root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> key  << " ";
    }
}

int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);

    postorder(root);
    return 0;
}