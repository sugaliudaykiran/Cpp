/*
    Binary Tree :-
       In Binary Tree every node has at most two children.
            In thiS we further discuss the implementation to represent a Binary Tree.

    ** Degree of every node at most two children, (or) a node has 0 child, 1 child, 2 children..
    ** every node to represent with three fields there are data/key, left_child, right_child.. over linking structure..
    ** for leaf left and right are always NULL..

    *** There are array representation is also possible of binary tree, there 
            in mostly for ex.  Binary heap and Segment tree.
    **  Binary Search tree is mostly used binary tree and it also a various of Binary tree.
    ** Binary heap for Priopty queue.. uses binary tree.
    ** Segment tree for range queries uses binary tree.


    "Tree Traversal" is basically going through "every node(key) exactly once".
        In this we briefly discuss:
            Types of Tree Traversal i.e. 
             |->   Breadth-First Search(BFS).  //  In this we visit every node level-wise.. first root and next its left and right childrens.. soon.
             |->   Depth First Search(DFS).   //   In this we traverse the one side complete and moves to other side..
                    **  We process the root node and process left node as "left sub tree" as we process root node.
                    ** Similiar we process the "right sub tree" and this we can implement "using recursive ":-
                            Traverse root, 
                            Traverse left subtree,
                            Traverse right subtree.
                    ** There are many ways to traverse tree and there are 3! = 6 ways we can traverse..
                    ** The most (3) famous permutation/traversal are Inorder, preorder and postorder traversals.
                    ** All this famous permutation/traversal follows that is we visit "left subtree before right subtree".
        
        In inorder  :-  (left, root, right)     were left means hole left subtree.. and right means hole right subtree..
           preorder :-  (root, left, right)
         postorder  :-  (left, right, root)

                                       10           --> root
                                      /  \
                                    20    30
                                   /  \     \
                                  40   50    60
                                       / \
                                      70  80    
            
            Inorder :-  40 20 70 50 80 10 30 60     //  left, root, right 
           preorder :-  10 20 40 50 70 80 30 60     //  root, left, right
          postorder :-  40 70 80 50 20 60 30 10     //  left, right, root
    
    ** note :- when we recursive call the subtree, if subtree is single node we print and move to next node.
*/      

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

    Node(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
};

int32_t main(){

    Node *root = new Node(5);   //  Node *root = NULL; then tree has nothing..
    root -> left = new Node(10);
    root -> right = new Node(15);
    root -> left -> left = new Node(20);

    return 0;
}