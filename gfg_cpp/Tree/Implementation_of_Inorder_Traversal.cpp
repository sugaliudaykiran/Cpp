/*

Implementation of Inorder Traversal :-
    In this, we discuss a function that takes root as a parameter, whose return type is void 
        and is supposed to print inorder traversal of the Tree whose nodes are given.

    ** Inorder Traversal :- (left, root, right)..
    ** In this we calls the recursive of left subtree check the left as root and call its
             left's left subtree and print the root and check the left's right subtree..
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
};                                                                                  //   (X+1)
    //  Inorder traversal   :-      TC -> O(n)..  AS -> O(h) where in wrost case (height of root +1) takes functional callstack..
void inorder(Node *root){       
        if (root != NULL){               // Here we skips the root is NULL case..
            inorder(root -> left);
            cout << root -> key << " ";
            inorder(root -> right);
        }
    }

int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);

    inorder(root);

    return 0;
}