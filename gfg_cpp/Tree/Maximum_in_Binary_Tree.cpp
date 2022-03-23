/*
Maximum in Binary Tree  :-
    Largest node(key) in a Tree is the maximum of the Tree.
    In this, we discuss a recursive function that takes 
        the root of a binary Tree and returns the maximum of the Tree.

    ** In recursive solution we check if root is NULL then if it's return -INF.
    ** else check compare the root value with max (left subtree and right subtree)..
    ** Finally check with the root which is max then return the value..

    ** In iterative solution, we doesn't need the recursion call overahead..

    In which is best ?
        ** In case of height is large then iteration/level order traversal is best way to solve..
        ** In case of complete/Perfect tree then recusive is best way to solve..

*/ 

#include<bits/stdc++.h>
#include<stack>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};

//          Using Recursive :-      TC  -> O(n)..  AS -> O(h).. height of tree..
int get_max(Node *root){
    if (root == NULL)   return INT_MIN;       // Basic case when root, root -> left, root -> right becomes NULL then return 0 to its functioncall..
    else    
        return max(root -> key, max(get_max(root -> left), get_max(root -> right)));    //  checking root val with max(left and right) and overall max including root val.
}

//           Using Iteration :-        TC -> 0(n)..  AS  -> O(n) (or) 0(w).. where w is width of binary tree..
int get_max2(Node *root){
    if (root == NULL)   return INT_MIN;
    queue <Node *> q;
    q.push(root);
    int maxs = INT_MIN;    
    
    while (q.empty() == false){
        int count = q.size();

        for (int i=0; i<count; i++){
            Node *cur = q.front();
            maxs = max(maxs, cur -> key);
            // cout << cur ->key << " ";
            q.pop();
            if (cur -> left != NULL){
                q.push(cur -> left);
            }
            if (cur -> right != NULL){
                q.push(cur -> right);
            }
        }
    }
    return maxs;
}

int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(15);
    root -> right = new Node(20);
    root -> left -> left = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);
    root -> right -> left -> left = new Node(60);
    root -> right -> left -> right = new Node(70);

    cout << get_max(root);
    return 0;
}


