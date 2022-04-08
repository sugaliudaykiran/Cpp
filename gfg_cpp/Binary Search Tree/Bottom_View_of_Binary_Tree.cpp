/*

Bottom View of Binary Tree  :-
    A solution using Vertical Traversal is discussed in the video

** The bottom node of each vertical line, that we need to print bottom node of each horizontal distances..

           10          10 - (0)
         /    \
        20     30       20 - (-1),  30 - (1)
              /  \
            40    50    40  - (0),  50 - (2)..

    O/p :-   20  40  30  50     //  Need to print bottom view of each vertical line..

            10          10 - (0)
           /    
        20              20 - (-1)
           \ 
            30          30 - (0)
        
    O/p :-  20  30      //  In this we prefered the last occuring right child when there on same order.. or root..

** In this we over writes the existing values on same order level..

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

void Bottomview(Node *root){        //  In this we follow Level order traversal.. and print bottom view nodes..
    if (root == NULL){
        return;
    }
    map <int, int> mp;          // Here we using int, int order..
    queue <pair <Node *, int>> q;
    q.push({root, 0});

    while (q.empty() == false){
        auto p = q.front();
        Node *cur = p.first;
        int hd = p.second;
        mp[hd] = cur -> key;    //  updating the value if, it already existing..
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
    Bottomview(root);

    return 0;
}