/*  
    Insert in BST   :-
      In this video we learn how to insert a node in a BST, the basic idea is that wefirst search
          for the key and if the key is not present in the BST then we insert the key with the leaf node.
          Else if the key is already present in the BST then we do nothing.

    ** In this, we are given a BST, and key to be insert, we uses the search function to find the key is present or NOT..
        in case the key is not present in tree.. then we insert key, on the leaf is NULL
         then create a node to it and insert..
    ** In the case of key is already present in tree, then we does nothing..
    ** In case of root is NULL then we create node and insert key and return root as the new key..

                            10                                                  10
                          /    \                                              /    \
                         5      15              Insert(20)..                 5      15
                               /  \                                                /   \
                              12   18                                             12    18
                                                                                          \
                                                                                           20
    
    **** NOTE :- We alway insert the key at the Bottom of the tree (or) level of leaf.. and
                     in one case of NULL case we insert new node and return root..

                    NULL                insert(10)..                            10      -> root of tree..

                    10                                                          10
                  /    \                insert(12)..                          /    \     -> does no changes..
                 8      12                                                   8      12
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

//                  Recursive  Implementation :-    TC -> O(h).. AS -> O(h).. because of function call stack..
Node *insert(Node *root, int k){
  if (root == NULL) return new Node(k);

  if (root -> key == k){
    return root;
  }
  else if (root -> key > k){
    root -> left = insert(root -> left, k);   // check that we are "linking previous node".. root -> left which be the previous link..
  }                                               //  In this we over writings the added link to the previous links..
  else if (root -> key < k){
    root -> right = insert(root -> right, k);   // Similiar on root -> right..
  }
}

//                   Iterative  Implementation :-   TC -> O(h).. AS -> O(1).. 
Node *insert2(Node *root, int k){
  Node *temp = new Node(k);
  Node *parent = NULL, *cur = root;   //  We taken "parent" as previous node to link the inserted node..
  
  while (cur != NULL){
    parent = cur;
    if (cur -> key == k) return root;
    else if (cur -> key > k){
      cur = cur -> left;
    } 
    else if (root -> key < k){
      cur = cur -> right;
    }
  }
        //  After the above conditions completed cur while be NULL.. and using parent we link the new node..
  if (parent == NULL) return temp;  // in-case NULL in the tree create a node and return it..
  else if (parent -> key > k){
    parent -> left = temp;
  }
  else if (parent -> key < k){
    parent -> right = temp;
  }
  return root;
}

int32_t main(){

    Node *root = new Node(10);
    root -> left = new Node(5);
    root -> right  = new Node(15);
    root -> right -> left = new Node(12);
    root -> right -> right = new Node(18);
    
    int KEY = 20;
    Node *Updatedroot = insert2(root, KEY);
    cout << Updatedroot -> right -> right -> right -> key << endl;

    return 0;
}