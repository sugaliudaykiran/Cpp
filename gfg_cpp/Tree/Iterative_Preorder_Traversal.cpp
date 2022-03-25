/*
Iterative Preorder Traversal (Simple)   :-
    A O(n) extra space and O(n) time solution is discussed.

    ** In the recursive solution, we first traverse the root, the left and next right..
    ** But in preorder follows (root, left, right)..
    ** In the Iterative Solution :-     Which is similiar to level order traversal..
                    10
                  /    \
                 20     30
               /   \    /  
              40   50  60
            /   \    \
           70   80   90

    ** In this traversal we use stack to store the data which is last in first order..
    ** We push root to stack and pop it, print it and pushing right and left children..
    ** Order of pushing should be right and next left becuase we need to get next the left as first than right..
*/ 
#include<bits/stdc++.h>
#include<stack>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

//          Iterative Preorder Traversal :- TC -> O(n).. AS -> O(n).. 
void printPreorder (Node *root){
    if (root == NULL)   return;
    stack <Node *> s;
    s.push(root);

    while (s.empty() == false){   
        Node *cur = s.top();
        cout << cur -> key << " ";
        s.pop();
        if (cur -> right != NULL)    
            s.push(cur -> right);
        if (cur -> left != NULL)
            s.push(cur -> left);
    }
}
/*
Iterative Preorder Traversal (Space Optimized)  :-
    A O(h) extra space and O(n) time solution is discussed.

** In this from the root node we print, it goes left..left of tree and
    push each node right to stack..
** By this case we can only store the right child of each node in the stack..

*/ 

//          Efficient Solution :-
void printPreorder2(Node *root){
    if (root == NULL)   return;
    stack <Node *> st;
    Node *cur = root;

    while (cur != NULL or st.empty() == false){
        while (cur != NULL){
            cout << cur -> key << " ";
            if (cur -> right != NULL)    st.push(cur -> right);
            cur = cur -> left;
        }
        if (st.empty() == false){
            cur = st.top();
            st.pop();
        }
    }
}


int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right -> left = new Node(60);
    root -> left -> left -> left = new Node(70);
    root -> left -> left -> right = new Node(80);
    root -> left -> right -> right = new Node(90);
    
    printPreorder2(root);
    return 0;
}
