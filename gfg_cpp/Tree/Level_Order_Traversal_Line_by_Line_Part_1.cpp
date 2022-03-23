/*
    Level Order Traversal Line by Line (Part 1) :-      //  BFS

In Level Order Traversal Line by Line, we print the nodes at each level separately in a new line.
In this, we discuss:
    A function that takes root as a parameter, doesn’t return anything and prints the level order 
        traversal line by line by using method-1.
        In method-1, we implement this function using a single loop.

    Ex:-
        ------------10----------------          L0 -> 10
                   /  \
        -------- 20 -- 30 -------------         L1 -> 20  30
                /  \     \          
        ------ 8 -- 7 --- 6---------            L2 -> 8  7  6
                   / \
        ----------9 - 15------------            L3  -> 9  15

    O/p :-
                10
                20  30
                8   7    6
                9   15
Idea :-
    1) In these we need to print each level in new line..
    2) When we reaches the last node of level and its next level is already in the queue.
    3) while traverse the cur_level completely we pass NULL to the queue..
    4) when we poping item from the queue, if item is NULL then we print new line and add NULL to the queue..
    5) By this after completion each level NULL is add to queue and new line is printed..

    TC -> O(n)..  AS -> 0(w)
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
    //      LOT_line by line      TC -> 0(n)..        AS  -> O(n) (or) 0(w).. where w is width of binary tree..
void printL_by_L(Node *root){
    if (root == NULL)   return;
    queue <Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1){
        Node *cur = q.front();
        q.pop();

        if (cur == NULL){   //  check the cur is NULL then push NULL to queue and print new line..
            cout << "\n";
            q.push(NULL);
            continue;
        }

        cout << cur -> key << " ";

        if (cur -> left != NULL){
            q.push(cur -> left);
        }
        if (cur -> right != NULL){
            q.push(cur -> right);
        }
    }
}
            // (or)
void printLevel(Node *root){
    if (root == NULL)   return;
    queue <Node *> q;
    q.push(root);

    while (q.empty() == false){
        Node *cur = q.front();
        q.pop();
        cout << cur -> key << " ";
        
        if (cur -> left != NULL){
            q.push(cur -> left);
            
        }
        if (cur -> right != NULL){
            q.push(cur -> right);
            cout << endl;           //  just by adding it.. to the level order traversal..
        }
    }
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

    printL_by_L(root);
    return 0;
}
