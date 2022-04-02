/*

Pair Sum with given BST     :-
    The problem discusses finding the pair of the sum in given Binary Search Tree.
    Ex :-                    10
                           /    \
                          8      20
                        /  \    /   \
                       4    9  11    30
                                   /
                                  25
                Sum = 33
            O/p :-  Yes..   there is a pair (8, 25) with sum 33..

                            20
                          /    \
                         8     40
                              /
                             35
                Sum = 49
            O/p :-  No..    no pair..

    Method 1(Inorder Traversal) :-      TC -> 0(n)..    AS -> 0(n)..
        1) Do an Inorder traversal of the given BST and store it in an array..
        2) Use two pointer approach to find if array has a pair with the given sum..

    Method 2(Hashing)   :-          TC -> O(n)..  AS -> O(n)..
        1) In this we find pair while traversal the given BST.. when we find the pair then we return immediately..
        2) We do inorder traversal and check the (sum - node) is present in the "set" if not present then push item to set..
            and if present then return.. 
        3) This Approach will work for Normal BST also..

*/

#include<bits/stdc++.h>
#include<set>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};

//      PairSum :-  TC -> O(n).. AS -> O(n)..   recursive call stack 
bool pairSum(Node *root, int sum, unordered_set <int> &s){
    if (root == NULL){
        return NULL;
    }

    if (pairSum(root -> left, sum, s) == true){
        return true;
    }
    if (s.find(sum - root -> key) != s.end()){
        return true;
    }
    s.insert(root -> key);

    return pairSum(root -> right, sum, s);
}

int32_t main(){

    Node *root = new Node(10);
    root -> left = new Node(5);
    root -> right = new Node(20);
    root -> right -> left = new Node(16);
    root -> right -> right = new Node(40);

    int sum = 30;
    unordered_set <int> s;
    cout << pairSum(root, sum, s) << endl;

    return 0;
}
