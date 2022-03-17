/*
    Height of Binary Tree :-
        is the number of nodes between the longest path from root to leaf node(including the root 
            and leaf node).
            
    In this, we discuss about a recursive function that takes root of the tree and 
        returns the height of the Binary Tree.

    ** Height = Max (Edge from root to leaf +1)

    ** It checks from the root is NUll or not if not NULL check its
         left subtree and checks the root right subtree.. and increment as count of level..
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

//      Height of Binary tree   :-      TC -> O(N)... AS -> O(h)..     in wrost case O(h+1) fuctional calls..
int height(Node *root){
    if (root == NULL){
        return 0;
    }
    return max(height(root -> left), height(root -> right))+1;
}



int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);

    cout << height(root) << endl;

    return 0;
}