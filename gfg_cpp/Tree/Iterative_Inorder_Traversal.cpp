/*
    Iterative Inorder Traversal :-
        ** In the recursive solution, we first traverse the left, the root and next right..
        ** But in inorder follows (left, root, right)..
        ** In the Iterative Solution :-
                    10
                  /    \
                 20     30
               /   \    /  
              40   50  60
            /   \    \
           70   80   90
    ** In this traversal we goes upon left.. left upto leaf.. and we move to parent and goes to right and repate it..
    ** We use stack to store the data.. first we push left..left..  left upto leaf. and pop one by one and print it and check it's 
        right if any left if there then push to stack..
*/ 
#include<bits/stdc++.h>
#include<stack>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

//          Iterative Inorder Traversal :-      TC -> 0(n).. AS -> O(h).. never go over the height of the binary tree..
void printInorder(Node *root){
    if (root == NULL)   return;
    stack <Node *> s;
    Node *cur = root;
    while (cur != NULL or s.empty() == false){
        while (cur != NULL){
            s.push(cur);
            cur = cur -> left;
        }
        cur = s.top();
        s.pop();
        cout << cur -> key << " ";
        cur = cur -> right;
    }
}


int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right -> left = new Node(60);
    root -> left -> left -> left = new Node(70);
    root -> left -> left -> right = new Node(80);
    root -> left -> right -> right = new Node(90);
    
    printInorder(root);
    return 0;
}