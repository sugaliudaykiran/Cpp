/*
Check for Balanced Binary Tree :-

In a Balanced Binary Tree for every node, "the difference between heights
    of left subtree and right subtree should not be more than one". it should be true for every node..
    In this, we discuss two solutions (one with time complexity of O(n^2) 
        and another with time complexity of O(n) ) to check whether a Tree is Balanced or not.

    Ex :-           18 
                  /   \
                 4     20 
                      /  \ 
                     13   70
        O/p :-      true

    Ex2 :-          3
                  /   \
                 4     8
                / \     \ 
               5   9     7
                          \
                           6
        O/p :-     false                   

        Navie Solution :-       TC -> O(N^2).. 
    1) We start with the root and compute height of left subtree and height of right subtree if there are balanced then..
    2) then we call recursive left subtree check it is balanced and calls recursive right subtree and check it is balanced..
    3) When this conditions are true then it is balanced.. takes O(N^2)..
    code :-             

    bool isBalanced(Node *root){
        if (root == NULL)   return true;
        int lh = height(root -> left);
        int rh = height(root -> right);
        return (abs(lh - rh) <= 1 && isBalanced(root -> left) && isBalanced(root -> right));
    }       
        //  We have write height() function..

        Efficient Solution :-       TC -> O(N)..
    ** Check each node that it's subtree(L/R) is balanced or not else return -1.. if balanced then return height..
    1) We begin with root and to it height we check its left-Subtree and right-Subtree..
    2) We recursive call left and right and check..
    3) If hole is balance then we return height else -1..

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

//      Efficient Solution :-       TC -> O(N)..
int isbal(Node *root){
    if (root == NULL)   return 0;

    int lh = isbal(root -> left);   //  Check for "left Subtree" Also get the left height..
    if (lh == -1) return -1;        //  If left Subtree is -1 then return -1 without checking right.. 

    int rh = isbal(root -> right);  //  Check for "right Subtree" Also get the right height..
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;
    else    return (max(lh, rh) +1);
}


int32_t main(){

    Node *root = new Node(20);
    root -> left = new Node(8);
    root -> right = new Node(12);
    root -> right -> left = new Node(3);
    root -> right -> right = new Node(9);

    cout << isbal(root);
    return 0;
}


