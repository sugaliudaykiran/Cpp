/*
Maximum Width of Binary Tree    :-  
    is the maximum number of nodes present in a level of the Tree.
    In this, we discuss a function that takes the root of a Binary Tree 
        and returns the maximum width of the Binary Tree.
    Hint:- we use "level order traversal line by line logic" to find maximum width of the Binary Tree.
*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};

//      Iterative Solution :-   Which checks Width..    "level order traversal line by line logic"
int width(Node *root){
    if (root == NULL)   return 0;       //  TC -> 0(n).. AS -> 0(w)..  (or) O(n)..
    queue <Node *> q;       //  Here we create the Queue to store the Address of each node..
    q.push(root);
    int w = INT_MIN;

    while (q.empty() == false){     //  Only when stack is not empty..
        int count = q.size();       //  Here we check each level of width and update the width..
        w = max(count, w);
        
        for (int i=0; i<count; i++){
            Node *cur = q.front();
            q.pop();
            // cout << cur -> key << " ";
            if (cur -> left != NULL)    q.push(cur -> left);
            if (cur -> right != NULL)    q.push(cur -> right);
        }
    }return w;
}

int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right = new Node(30);
    root -> right -> left = new Node(60);
    
    cout << width(root) << endl;
    return 0;
}