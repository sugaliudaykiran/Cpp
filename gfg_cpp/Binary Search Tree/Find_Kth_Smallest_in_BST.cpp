/*

    Find Kth Smallest in BST    :-
In this, we discusses the problem of finding the Kth Smallest Binary Search Tree.

    Ex :-   insert(10), insert(5), insert(1), insert(3), insert(9);
                Kth_smallest(3);
    
            O/p :-  5           //  because we inserts in set which is sorted order..    1  3  5  9  10

    Array, linked list -> linear
    hashing            -> linear
    BST                -> O(k).. using Inorder or any traversal..
    Balanced BST       -> O(h)..

**  Navie solution :-   TC -> O(n) for K th smallest 
            K = 3
        
        // int count = 0;  avoid using global variables..

        void printK_th(root, k, &count){
            if (root is not NULL){
                printK_th(root -> left, k, count);
                count++;

                if (count == k){
                    cout << (root -> key) << endl;
                    return;                         // By adding this line we can improve TC -> O(h+k)..
                }
                printK_th(root -> right, k, count);
            }
        }

**  Efficient Solution :-       TC -> O(h).. for K-th smallest..
    1) We modify the Node struct of BST and add new variable to store each node count nodes of leftsubtree..
         which is called augmented BST..

                                    50    (4)      -> lcount..
                                  /     \
                     (2)         20      100     (3)
                               /   \     /  \
                     (1)     10    40   70   120     70 has (1)     120, 40  has (0)
                            /         /   \
                  (0)      4         60    80        60, 80 has (0) because it is leaf..


    Compare (lcount+1) which is position of tree.. with k   start from the root..
        1) If same, return root.                                //  k = 5..     return 50..
        2) If greater, recur for left subtree with same k.      //  k = 2..     return 10..
        3) If smaller, recur for right subtree with k..
            k as (k - lcount+1) In this we modify the k..      //  k = 7..     return 70..
                k = 7, then root is has (k - lcount+1) = (7-5) = 2 we need find second index in tree..
                k = 2, then node is 100 it's lcount+1 = 4 which greater, we move left, node 70, 
                    it's lcount+1 = 2 == k then return 70.
    
    ** this is similiar to search function.. with addtion k.

    How to maintain lcount during insertion/deletion ?
        1) while add node which is greater than root, we increment the lcount.. similiar which deletion also..
        2) Else, in lesser than root, we do nothing..
    **  3) That is we only increment or decrement when only in case of insert/delete in left subtree nodes..

*/ 

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
    int lcount;     //  count of nodes in the left-subtree of each node..

    Node(int k){
        key = k;
        left = right = NULL;
        lcount = 0;
    }
};

//          Insert  :-
Node *insert(Node *root, int x){
    if (root == NULL){
        return new Node(x); //  for creating the root..
    }

    if (x < root -> key){
        root -> left = insert(root -> left, x);
        root -> lcount++;
    }
    else if (x > root -> key){
        root -> right = insert(root -> right, x);
    }
    return root;
}
//              Kth smallest :-     TC -> O(h)..
Node *kthSmallest(Node *root, int k){
    if (root == NULL){
        return NULL;
    }

    int count = root -> lcount +1;
    if (count == k){
        return root;
    }
    if (count > k){
        return kthSmallest(root -> left, k);
    }
    return kthSmallest(root -> right, k - count);
}
int32_t main(){

    Node *root = NULL;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};

    for (int x: keys){
        root = insert(root, x);
    }

    int k = 4;
    Node *res = kthSmallest(root, k);

    if (res == NULL){
        cout << " There are less than k nodes in the BST " << endl;
    }
    else {
        cout << res -> key << endl;
    }
    return 0;
}