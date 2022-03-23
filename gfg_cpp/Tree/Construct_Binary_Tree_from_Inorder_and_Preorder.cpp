/*

Construct Binary Tree from Inorder and Preorder :-
    In This, discusses the "Construction of a Binary Tree" from Inorder and Preorder traversal.

Note :- We can only construct inorder/preorder combination and 
            inorder/postorder combination.. mainly inorder is required to construct a tree..

I/p :-      in[] = [20, 10, 30]
            pre[]= [10, 20, 30]

O/p :-      root of the below tree..
                    10
                   /  \
                  20   30

                    0   1  2   3   4   5   6   7
**try :-   in[] = [40, 20, 50, 10, 30, 80, 70, 90]
           pre[]= [10, 20, 40, 50, 30, 70, 80, 90]

    inOrder :- (left, root, right)
    preOrder:- (root, left, right)

    ** We can guess the root of tree, which is first of preorder[]. check the example "10" is root..
    ** We can known the left and right of root by checking the inorder[]. which is index "3" 
            and left of it's is left subtree and right of it's is right subtree..
    ** To known the root of left subtree we need to traverse preoder[]. and find the "20" is next sub-root
            and find in inoder[]. and check its left and right subtree..
    ** We keep traversing till the end root of preoder[].. by using inorder/preorder we can construct binary tree..

                                10
                              /    \
                            20      30  
                           /  \       \ 
                          40   50       70
                                       /   \
                                      80    90
    
    Using Hashing :-        TC -> O(n)..
        1) We Simple preprocesses the Inorder[] and stores the keys of inorder[] and indexs as values..
        2) We uses unorder_set..
    Ref :- https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
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

//      Inorder Traversal :-    or we can any traversal to print..
void inorder(Node *root){
    if (root != NULL){
        inorder(root -> left);
        cout << root -> key << " ";
        inorder(root -> right);
    }
}

//      Construct Binary Tree   :-              TC -> O(N^2).. AS -> O(1).. But using Hashing we can get TC -> O(N)
int preIndex = 0;       //  iterate over the pre[].. 
Node *cTree(int in[], int pre[], int is, int ie){
    // static int preIndex = 0;
    
    if (is > ie)   return NULL;     //  The construction of tree follows preorder traversal..

    Node *root = new Node(pre[preIndex++]);
    int inIndex;
    for (int i=is; i<= ie; i++){
        if (in[i] == root -> key){
            inIndex = i;
            break;
        }
    }
    root -> left = cTree(in, pre, is, inIndex-1);   // Checks each node left subtree and right subtree..
    root -> right = cTree(in, pre, inIndex+1, ie);
}


int32_t main(){
    int in[5] = {20, 10, 40, 30, 50};
    int pre[5] = {10, 20, 30, 40, 50};

    int is = 0, ie = sizeof(in)/sizeof(in[0]) -1;
    Node *root = cTree(in, pre, is, ie);
    inorder(root);
    return 0;
}