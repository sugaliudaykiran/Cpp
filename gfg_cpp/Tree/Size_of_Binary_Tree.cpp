/*
    Size of Binary Tree is the total numbers of nodes present in that Tree.
        In this, we discuss a recursive function that takes root as a parameter 
            and is supposed to return the size of the Tree whose nodes are given.

    **  In Recursive we check the root is NULL or not then if not check the root left
             subtree and check root right subtree..
    **  And increment the 1 + functioncall_of(root -> left) + fuctioncall_of(root -> right)
    Ex :-
                
                    10          //  1 + 3 + 2  = 6.. size of tree.
                  /    \ 
        1+1+1    /      \       1+0+1
               20        30           
    1+0+0    /   \ 1+0+0   \   1+0+0
           40     50        70        


** In iteration we simple add the count of each level of stack to res.. by we can get size of hole tree..
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
int print_size(Node *root){
    if (root == NULL)   return 0;       // Basic case when root, root -> left, root -> right becomes NULL then return 0 to its functioncall..
    else    
        return (1 + print_size(root -> left) + print_size(root -> right));
}


//           Using Iteration :-        TC -> 0(n)..  AS  -> O(n) (or) 0(w).. where w is width of binary tree..
int print_size2(Node *root){
    if (root == NULL)   return -1;
    queue <Node *> q;
    q.push(root);
    int size = 0;    
    
    while (q.empty() == false){
        int count = q.size();
        size += count;
        for (int i=0; i<count; i++){
            Node *cur = q.front();
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
    return size;
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

    cout << print_size(root);
    return 0;
}


