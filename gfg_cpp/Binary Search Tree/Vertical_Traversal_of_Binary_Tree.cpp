/*

Vertical Traversal of Binary Tree  :-

Given a binary tree, we need to print nodes in all vertical lines
     starting from leftmost line to rightmost. By using horizontal distance and print them based on it..

           10          10 - (0)
         /    \
        20     30       20 - (-1),  30 - (1)
              /  \
            40    50    40  - (0),  50 - (2)..

    O/p :-   20  10  40  30  50

            10          10 - (0)
           /    
        20              20 - (-1)
           \ 
            30          30 - (0)

    O/p :-   10  30  20

** This is similiar to Vertical sum implementation..

Approach :-
    1) Create an empty map "map in cpp"
    2) Do level order traversal and put nodes into the map..
    3) On basics of horizontal distances of each node..
    4) Now traverse the map and print contents..

** In this we uses the queue DS to store the pair of (Node -> key) and horizontal distance.. and maintain the 
    map which store the nodes based on the horizontal distances..
    
*/ 

#include<bits/stdc++.h>
#include<map>
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

void vTraversal(Node *root){        //  In this we follow Level order traversal.. 
    if (root == NULL){
        return;
    }
    map <int, vector<int>> mp;
    queue <pair <Node *, int>> q;
    q.push({root, 0});

    while (q.empty() == false){
        auto p = q.front();
        Node *cur = p.first;
        int hd = p.second;
        mp[hd].push_back(cur -> key);
        q.pop();

        if (cur -> left != NULL){
            q.push({cur -> left, hd-1});
        }
        if (cur -> right != NULL){
            q.push({cur -> right, hd+1});
        }
    }
    for (auto p : mp){
        vector <int> res = p.second;
        for (int x : res){
            cout << x << " "; 
        }cout << endl;
    }
}

int32_t main(){   
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);
    vTraversal(root);

    return 0;
}