/*
Deletion in BST  :-   We Should follow the BST after the deletion..
In this,  we discuss how to delete a node from a Binary Search There are three posibilities:
    1.Node to be deleted is a leaf node.    
        (In this we can simple to delete, node that has it's next nodes are NULL.. which is a LEAF node..
            and making it parent node next to NULL..)
                         50                                       50
                      /     \                                   /    \
                     30      70      => deletion(40)           30     70
                   /   \    /  \                              /      /   \  
                  20   40  60   80                           20     60    80

    2.Node to be deleted has only one child.
        (In this case, 30 has one left child then replace the node to 20..)
                         50                                       50
                      /     \                                   /    \
                     30      70         deletion(30)           20     70
                   /        /  \                                     /   \  
                  20       60   80                                 60    80

    3.Node to be deleted has two children.
        (We should follow based on closest higher value or closest lower value.. only one.)

                         50                                       60                              20
                      /     \                                   /    \                              \  
                     20      70         deletion(50)           20     70          (or)               70 
                            /  \                                        \                           /   \
                           60   80                                       80                        60    80
                                                            closest higher value           closest lower value

    we also learn, "inorder successor is the closest higher value" and 
                   "inorder predecessor is the closest lower value".    
        
        closest higher value :-  Using Inorder successor..

    ** If in-case "Key is be deleted in not present in tree" then return "no changes"..

About Inorder successor :-
    **  This Inorder successor will only works when it's right child is not empty..
    **  In some of case the key we delete does not have Inoder successor on the right side 
            then in those, case inorder successor will be one of the ancestors..
    ** So, this "inorder Successor will not given generally inorder successor.. only when right child is not empty"..

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

//    Inorder Successor :-  [Left most leaf of the right child]   Works only when right child is non empty..
Node *getSuccessor(Node *cur){
    cur = cur -> right;
    while (cur != NULL and cur -> left != NULL){
        cur = cur -> left;
    }
    return cur;
}

//                  Recursive  Implementation :-    TC -> O(h).. AS -> O(h).. because of function call stack..
Node *delNode(Node *root, int k){
    if (root == NULL)   return root;

    if (root -> key > k){
        root -> left = delNode(root -> left, k);
    }
    else if (root -> key < k){
        root -> right = delNode(root -> right, k);
    }

    else{
        if (root -> left == NULL){      //  while deleting the right child/leaf..
            Node *temp = root -> right;
            delete root;
            return temp;
        }
        else if (root -> right == NULL){    //  while deleting the leaf child/leaf..
            Node *temp = root -> left;
            delete root;
            return temp;
        }
        else{       //  When both children are not NULL..
            Node *Succ = getSuccessor(root);    //  Left most leaf of the right child.
            root -> key = Succ -> key;
            root -> right = delNode(root -> right, Succ -> key);    //  Delete that update node..
        }
    }
    return root;
}

//          Inorder Traversal :-
void inorder(Node *root){
    if (root == NULL)   return;
    inorder(root -> left);
    cout << root -> key << " ";
    inorder(root -> right);
}

int32_t main(){

    Node *root = new Node(50);
    root -> left = new Node(30);
    root -> left -> left = new Node(20);
    root -> left -> right = new Node(40);
    root -> right  = new Node(70);
    root -> right -> left = new Node(60);
    root -> right -> right = new Node(80);
    
    int KEY = 40;
    root = delNode(root, KEY);

    inorder(root);

    return 0;
}