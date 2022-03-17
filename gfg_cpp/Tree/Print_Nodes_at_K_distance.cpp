/*

Print Nodes at K distance   :-
    Nodes at distance k from the root are basically the nodes at (k+1)th level of the Binary Tree.
        In this, we discuss a function that takes root and k as a parameter, whose return type is void and is supposed to print the nodes at distance k from the root.

    Ex :-        K = 2

                10              -> k = 0
               /  \
              20   30           -> k = 1
            /   \    \   
           40   50    70        -> k = 2

    O/P ->   40  50  70
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

//      Print Nodes at K distance :-    TC -> O(n).. AS -> O(h)
void print_K(Node *root, int K){
    if (root == NULL)   return;
    if (K == 0) cout << (root -> key) << " ";
    print_K(root -> left, K-1);
    print_K(root -> right, K-1);
}

int32_t main(){

    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);

    int k = 2;

    print_K(root, k);
    return 0;
}


