/*
Count nodes in a Complete Binary Tree   :-
    Given a binary tree, our task is to count total nodes.  
        Two methods are discussed here, naive method which is O(n).
        And an efficient method which is O(Log n * Log n)

    ** A binary tree which should fill completly and except the possible the last level and
         this last level should be filled from "left to right"..
    Ex  :-                      10
                              /    \
                             20    30
                           /   \
                         40     50          
            O/p :-  5             
    ** In this we need to return count of nodes in complete binary tree..

                Efficient Solution :-   
    1) In case above Ex. left subtree is complete binary tree and we can use the height of left of left upto root
         and height of right of right upto root.. if count of node is equal then using left height or right height,
            pow(2, height of left(or)right) -1..    and it takes 0(h)..
    2) In this case we skip the middle nodes of complete binary tree..
    3) In case of left subtree of root we can use navie apporach.. which take 0(n)..

            In wrost case :-
   ** In this case we can find the height any of left or right in efficient way.. if another subtree takes navie approach..

                    Recursion Time Complexity :-
        T(c) < T(2n/3) + 0(h)   for n nodes..

    Using Upper boundend on complete binary tree :- 
        T(c) = T(2n/3) + 0(log_base(2)_n)

                log n               --
                log (2n/3)            |
                log (4n/9)            |     O(log_base(3n/2)_n  * log_base(2)_n)    which is O(log n * log n).. 
                ...                   | 
            upto log(1)               |
                                    --
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

//              Navie Solution :-       TC -> 0(n)..
int count(Node *root){
    if (root == NULL)   return 0;
    else 
        return 1 + count(root -> left) + count(root -> right);
} 

//          Efficient Solution :-       TC -> O(logn) * O(logn)..   
int count2(Node *root){
    int lh = 0, rh = 0;
    Node *cur = root;
    while (cur != NULL){
        lh++;
        cur = cur -> left;              //   0(h)
    }
    
    cur = root;
    while (cur != NULL){            
        rh++;
        cur = cur -> right;         //  0(h)
    }
    if (lh == rh){
        return pow(2, lh) -1;       //  In best case 0(h)..
    } 
    else
        return 1 + count2(root -> left) + count2(root -> right);       // In wrost case one of its 0(h)..
}

int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);

//    cout << count(root) << endl;
   cout << count2(root) << endl;
    return 0;
}