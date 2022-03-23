/*
Level Order Traversal Line by Line (Part 2) :-

In Level Order Traversal Line by Line, we print the nodes at each level seperately in a new line.
In this, we discuss:
    A function that takes root as a parameter, doesn’t return anything and prints the level order traversal line by line by using method-2.
    In method-2, we implement this function using nested loops.
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
    1) In this we store each level size of queue and run inner loop upto size.. and print items in level..
    2) after each level we print new line..
    3) By this we traverse each level at ones and enque and deque is O(n)..
            TC  -> O(n).. AS -> 0(w)..  or O(N)..

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
    //      LOT_line by line_2      TC -> 0(n)..  AS  -> O(n) (or) 0(w).. where w is width of binary tree..
void printLOL2(Node *root){
    if (root == NULL)   return;
    queue <Node *> q;
    q.push(root);

    while (q.empty() == false){
        int count = q.size();   //  store each level size and iterator upon it..

        for (int i=0; i<count; i++){
            Node *cur = q.front();
            q.pop();
            cout << cur -> key << " ";

            if (cur -> left != NULL) {
                q.push(cur -> left);
            }
            if (cur -> right != NULL){
                q.push(cur -> right);
            }
        }cout << "\n";
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

    printLOL2(root);
    return 0;
}


