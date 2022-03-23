/*
Children Sum Property :-
    is a property in which the "sum of values of the left child and right child
     should be equal to the value of their node" if both children are present. 
     Else if only one child is present then the value of the child should 
     be equal to its node value.

In this, we discuss a recursive function that takes the root node
 as a parameter and returns TRUE if the Tree follows C.S.P. and 
 FALSE if the Tree does not follow C.S.P.

    Ex  :-              10
                       /  \              //  It children sum is 8 + 2 = 10 which is equal to parent..
                      8    2                
                            \           //  It children sum is 0 + 2 = 2 which is equal to parent..
                             2
        O/p :-  True.
    
    Ex2 :-           NULL       //  In case of NULL node, property is true..

            O/p :- True.
    
    Ex3 :-          10      //  In case of leaf node, property is true..

            O/p :-  True.    

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

//      Using Recursive :-      TC  -> O(n).. AS -> O(h).. height of tree and it requires for recursion call stack..
bool CSP(Node *root){
    if (root == NULL)   return true;    //  In case of NULL/"leaf node", property is true..
    if (root -> left == NULL and root -> right == NULL) return true;    

    int sum = 0;
    if (root -> left != NULL){
        sum += root -> left -> key;
    }
    if (root -> right != NULL){
        sum += root -> right -> key;
    }

    return (root -> key == sum && CSP(root -> left) && CSP(root -> right));
}

int32_t main(){

    Node *root = new Node(20);
    root -> left = new Node(8);
    root -> right = new Node(12);
    root -> right -> left = new Node(3);
    root -> right -> right = new Node(9);

    cout << CSP(root);
    return 0;
}
