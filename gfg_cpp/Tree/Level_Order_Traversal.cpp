/*
    //      BFS -> Breadth first search :-

Level order traversal of a tree is breadth first traversal of binary tree.
    In this, we will discuss about a function that takes root as a parameter, doesn’t returns .
     anything and prints the level order traversal in a single line.we implement this function 
     using queue datastructure.


           ---------10----------------          L0 -> 10
                   /  \
         ------- 20 -- 30 -------------         L1 -> 20  30
                /  \     \          
        ------ 8 -- 7 --- 6---------            L2 -> 8  7  6
                   / \
        ----------9 - 15------------            L3  -> 9  15

        O/p ->  10  20  30  8   7   6   9   15

    ** A Simple Solution is Using two functions that are height of binary tree and print the K th from the root..
            in this we first check the height of tree and call the K from 0 to height of tree by this it Print the values
            But this apporach takes     O(n) + 0(h) * O(n)  => 0(h) * O(n)
    
    ** Efficient Apporach is using queue..
        In this we uses the queue for storing the each level of tree and remove and store the children of each node..
        By these we avoid the recursion call of each node..
            **  TC  -> 0(n)..  AS -> O(n).. we can say that effective that 0(w).. where w is width of the tree..
*/ 

#include<bits/stdc++.h>
#include<stack>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};
    //      Level order Traversal           TC -> 0(n)..        AS  -> O(n) (or) 0(w).. where w is width of binary tree..
void printLevel(Node *root){
    if (root == NULL)   return;
    queue <Node *> q;
    q.push(root);

    while (q.empty() == false){
        Node *cur = q.front();
        q.pop();
        cout << cur -> key << " ";
        if (cur -> left != NULL){
            q.push(cur -> left);
        }
        if (cur -> right != NULL){
            q.push(cur -> right);
        }
    }
}

int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(15);
    root -> right = new Node(20);
    root -> left -> left = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);
    root -> right -> left -> left = new Node(60);
    root -> right -> left -> right = new Node(70);

    printLevel(root);
    return 0;
}
