/*

Ceil in BST :-  We need to find out the value which is equal (or) greater than the val and which is closest greater.. than x.

In this, deals with the concept and working of the ceiling of a key in Binary Search Tree.
    Ex :-                   10
                          /    \
                         5      15                 
                              /     \
                             12      30
    
    If X = 14, then we check with root which is smaller than, we move it's right.. 15 is 
        greater than X, so we take the previous greater one. and moves it left..
        then 12 is smaller than X, then we move it's right.. then we see NULL..  then
         we return previous greater one.. which is 15 and it's closest greater..

    If X = 3, we check with root which is greater so, we take prev_greater one .. and move to left of it,
        which is 5, it is greater than X then we update prev_greater one.. and we move left of it.
        then it's NULL then we return the prev_greater one..
    
    If X = 40, then we check with root and which is smaller, then we move it's right side..
        15 is smaller than X then we move right of it.. we see 30 which is smaller than 40 then 
        check it's right of it.. then we see NULL then we return NULL because, we never see greater/equal one to X.

        Navie Solution :-   TC -> O(n).. AS -> O(h).. In Recursive and iterative using stack will take O(n).. extra-space..   
            ** We can use Inorder, Preorder, Postorder, Level order traversal.. 
            ** We check every key and check if it is greatest so far.. and keep updating the clostest greater one/ equal one..
    
        Efficient Solution :-   TC -> O(h).. AS -> O(1).. 
            ** We Initialize result as NULL and traverse from root to the leaf using three steps:-
            1) If root's key is same as X, we return root.
            2) If root's key is smaller than X, then change root to root's -> right.
            3) If root's key is greater than X, then update the result as root and change root to root's -> left.
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

//          Ceil in BST :-         TC -> O(h).. AS -> O(1)..
Node *ceil(Node *root, int k){
    Node *res = NULL;
    
    while (root != NULL){
        if (root -> key == k){
            return root;
        }
        else if (root -> key < k){      // If root's key is smaller than X, then change root to root's -> right.
            root = root -> right;
        }
        else{                           
            res = root;         //  If root's key is greater than X, then update the result as root and change root to root's -> left.
            root = root -> left;
        }
    }
    return res;
}

int32_t main(){

    Node *root = new Node(50);
    root -> left = new Node(30);
    root -> left -> left = new Node(20);
    root -> left -> right = new Node(40);
    root -> right = new Node(70);
    root -> right -> left = new Node(60);
    root -> right -> right = new Node(80);
    root -> right -> left -> left = new Node(55);
    root -> right -> left -> right = new Node(65);

    Node *res = ceil(root, 51);
    cout << res -> key << endl;

    return 0;
}