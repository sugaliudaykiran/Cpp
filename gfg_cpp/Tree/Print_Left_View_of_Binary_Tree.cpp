/*
Print Left View of Binary Tree  :-
    To Print Left View of Binary Tree we need to print the leftmost node at every level of the Binary Tree.
    In this, we discuss two methods to print left view of a given Binary Tree.In Method-1 we use Recursive 
        method whereas in Method-2 we use the Iterative method approach by using queue datastructure.
    Ex  :-
                    10                  --> level is 1
                  /    \
                20      30              --> level is 2
               /  \       \ 
              40   50      60           --> level is 3
    
    O/p :-  10  20  40  //  on each level print the left view of tree..

    Ex2 :-              10              -> L0
                       /   \        
                      50    60          -> L1
                           /   \
                          70    20      -> L2
                           \
                            8           -> L3
        
        O/p :-  10  50  70  8   //  on each level print the left view of tree..

    In recursive solution   :-      Using preorder traversal..
        1) While do preorder we take two var as max_lvl  = 0 and cur_lvl..
        2) root and its cur_lvl is 1.. and check the condition that max_lvl < cur_lvl if
             it's true then print key and update max_lvl to cur_lvl..
        3) Now check the cur_root left subtree and right subtree.. along increment its cur_lvl..
        4) By this on each level left node comes before right node.. using max_lvl 
            because on same lvl it print left node only.. 

    In iterative solution :-        Using level order traversal and print line by line..
        1) In this we add a condition is if (i == 0) then print cur_key..
        2) we push first node to queue and check if queue is empty then take the size of queue.
        3) Now iterate the loop upto size of queue and print first val of queue on basics of condition..
        4) after this we check the left and right side of key..

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

int maxlevel = 0;   //  declare globally for case each functional call it will change..

void printLeft(Node *root, int lvl){    //  Recursive Solution :-   TC -> 0(n)..  AS -> 0(h)..
    if (root == NULL)   return;

    if (maxlevel < lvl){
        cout << root -> key << " ";
        maxlevel = lvl;
    }                               //  Using PreOrder traversal..
    printLeft(root -> left, lvl+1);
    printLeft(root -> right, lvl+1);
}

void printleftView(Node *root){
    printLeft(root, 1);
}

//      Iterative - Solution :-     Using Line by Line level order traversal..
void PLV(Node *root){           
    if (root == NULL)   return;         //  TC -> 0(n)..    AS -> 0(w) width of tree or O(n)..
    queue <Node *> q;
    q.push(root);

    while (q.empty() == false){
        int count = q.size();

        for (int i=0; i<count; i++){
            Node *cur = q.front();
            q.pop();
            if (i == 0){
                cout << cur -> key << " ";
            }

            if (cur -> left != NULL){
                q.push(cur -> left);
            }
            if (cur -> right != NULL){
                q.push(cur -> right);
            }
        }
    }
}

int32_t main(){

    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);

    // printleftView(root);
    PLV(root);
    return 0;
}