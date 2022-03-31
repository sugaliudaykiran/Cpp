/*

Fix BST with Two Nodes Swapped  :-
    Given a binary search tree with two swapped nodes, the task is to fix the binary search tree
         by swapping them back.

    Ex:-             20                                         20
                  /     \                                     /    \
                 60      80             ->                   8      80
               /   \    /  \                               /   \   /   \
              4    10  8  100                             4    10  60   100

    ** In above tree by swapping 60 and 8 we get balanced BST..
    ** By using inorder traversal and check the prev item and checking which we need to change..
    ** The inorder traversal of above tree is   
            4  60  10  20  8  80  100       ->      4  8  10  20  60  80  100
               --------------
                    60                                           20
                  /    \                                       /     \ 
                 8     80               ->                    8      80
               /  \   /  \                                  /  \     /  \
              4   10  20  100                               4   10  60   100

    ** In above tree by swapping 60 and 20 we get balanced BST..
    ** By using inorder traversal and check the prev item and checking which we need to change..
    ** The inorder traversal of above tree is   
            4  8  10  60  20  80  100      ->       4  8  10  20  60  80  100
                      ------ 
    **** There are two case which we need defind one is adjacent in the inorder traversal..
            another one is no-adjacent ones..

    ** we can missing order in first tree that 4 > INF_MIN, 60 > 4, 10 is NOT greater than 60, and another one is
            8 is NOT greater than 20..
        
    ** In 2nd tree we can missing order is 20 is NOT greater than 60..

    ** By assuming that we given array, we need to missing order/violation then we check swap those two nodes..


    prev = INT_MIN, first = NIL, second = NIL;

    for (int i=0; i<n; i++){
        if (ar[i] < prev){
            if(first == NIL){   //  only changes when first is NIL..
                first = prev;
            }
            second = ar[i];     //  changes on second violation..
        }
        prev = ar[i];
    }
*/ 


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *right, *left;

    Node(int k){
        key = k;
        right = left = NULL;
    }
};
    //      Inorder Traversal   :-
void inorder(Node *root){
    if (root == NULL)   return;
    if (root != NULL){
        inorder(root -> left);
        cout << root -> key << " ";
        inorder(root -> right);
    }
}

Node *prevs = NULL, *first = NULL, *second = NULL;
void fixBST(Node *root){
    if (root == NULL){
        return;
    }

    fixBST(root -> left);
    if (prevs != NULL and root -> key < prevs -> key){
        if (first == NULL){
            first = prevs;
        }
        second = root;
    }
    prevs = root;
    fixBST(root -> right);
}


int32_t main(){
    Node *root = new Node(18);
    root -> left = new Node(60);
    root -> left -> left = new Node(4);
    root -> right = new Node(70);
    root -> right -> left = new Node(8);
    root -> right -> right = new Node(80);

    inorder(root);
    cout << endl;

    fixBST(root);
    int temp = first -> key;
    first -> key = second -> key;
    second -> key = temp;
    inorder(root);

    return 0;
}