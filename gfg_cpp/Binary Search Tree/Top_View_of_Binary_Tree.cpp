/*

Top View of Binary Tree     :-
    A Vertical Traversal based approach on vertical traversal based first occurances on each line..

** The top node of each vertical line, that we need to print top node of each horizontal distances..

           10          10 - (0)
         /    \
        20     30       20 - (-1),  30 - (1)
              /  \
            40    50    40  - (0),  50 - (2)..

    O/p :-   20  10  30  50     //  Need to print top view of each vertical line..

            10          10 - (0)
           /    
        20              20 - (-1)
           \ 
            30          30 - (0)
        
    O/p :-  20  10      //  In this prefered the last occuring left child when there on same order.. or root..

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

void Topview(Node *root){        //  In this we follow Level order traversal.. and print top view nodes..
    if (root == NULL){
        return;
    }
    map <int, int> mp;
    queue <pair <Node *, int>> q;
    q.push({root, 0});

    while (q.empty() == false){
        auto p = q.front();
        Node *cur = p.first;
        int hd = p.second;
        if (mp.find(hd) == mp.end()){
            mp[hd] = cur -> key;
        }
        q.pop();

        if (cur -> left != NULL){
            q.push({cur -> left, hd-1});
        }
        if (cur -> right != NULL){
            q.push({cur -> right, hd+1});
        }
    }
    for (auto x : mp){
        cout << x.second << " ";
    }cout << endl;
}

int32_t main(){   
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);
    Topview(root);

    return 0;
}