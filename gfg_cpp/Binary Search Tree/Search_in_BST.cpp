/*
Search in BST (Introduction)    :-
    In this video we discuss about search operation in Binary Serach Tree.
        The basic idea is that we end up with a leaf note if the key is not 
            present in the BST.

    ** In this case, we are given binary search tree and key is be search.. and return true (or) false..
            and values should be distinct..
    ** How it works ?
                                    15
                                  /    \
                                 5      20
                               /      /   \
                              3      18    80
                                    /
                                   16
        and key = 16..
        1) We compare key with root and if equal then return true.. if root is lesser than key then
              we move right subtree of root.. else., we move left subtree of root..
        2) In above case..  "16" greater than root now we move towards right then compare with "20" which is greater than "16"..
                then we move towards it's left and compare with "18" and this also greater than "16".. so we move left of it..
                finally, "16" is equal to "16" then we return true..
        3) "In any we reached NULL then we return false"..


Search in BST C++   :-
In this, we discuss two methods (recursive and iterative) to implement a 
    function in C++ that takes root and key as parameters and return True..
    if the key is present in the BST and returns False if the key is not present in BST.

    ** In case of Binary tree which is not balanced then it takes almost TC -> O(n)..
            in the case of "Skewed tree"..
    ** In case of self balanced tree TC -> O(log n).. 
    ** In case of BST TC -> O(h)..

    Skewed tree :-              10
                                   \ 
                                    12
                                      \
                                       15
                                         \ 
                                          19
*/ 
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};

//                  Recursive  Implementation :-    TC -> O(h).. AS -> O(h).. because of function call stack..
bool search(Node *root, int k){
    if (root == NULL)   return false;   //  To handle the base case and Empty case..
    
    if ((root -> key) == k)  return true;
    else if (root -> key > k){
        return search(root -> left, k);
    }
    else{
        return search(root -> right, k);
    }
}

//                   Iterative  Implementation :-   TC -> O(h).. AS -> O(1).. 
bool search2(Node *root, int k){
    while (root != NULL){
        if (root -> key == k){
            return true;
        }
        else if (root -> key > k){
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }return false;
}

int32_t main(){

    Node *root = new Node(15);
    root -> left = new Node(5);
    root -> left -> left = new Node(3);
    root -> right  = new Node(20);
    root -> right -> left = new Node(18);
    root -> right -> right = new Node(80);
    root -> right -> left -> left = new Node(16);
    
    int KEY = 16;
    cout << search2(root, KEY);
    return 0;
}