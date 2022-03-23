/*

Tree Traversal in Spiral Form   :-  We need to traverse each level in spiral form..
    Ex :-                1          --->
                      /     \          | 
                     2       3      <---
                    / \     / \     |
                   4   5   6   7    --->    
                  / \      /           |
                 8   9    10        <---

    O/p :-  1   3   2   4   5   6   7   10  9   8

This, discusses the method of Tree Traversal in Spiral Form.

Method 1    :-  using lEVEL ORDER traversal additional Using stack..
Method 2    :-  Using two stack and using them alterative time..
    The idea is to use two stacks. We can use one stack for printing 
        from left to right and other stack for printing from right to left. 
        In every iteration, we have nodes of one level in one of the stacks. 
        We print the nodes, and push nodes of next level in other stack. 


    ** Ref :- https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
*/


#include<bits/stdc++.h>
#include<queue>
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

//          Method - 1  :- Using Line By Line lEVEL ORDER traversal additional Using stack..
void printSpiral(Node *root){
    if (root == NULL)   return;         // In this we processing each node four times..
    queue <Node *> q;
    stack <int> s;          //  Purpose is to reverse alternative levels..
    bool reverse = false;

    q.push(root);
    while (q.empty() == false){
        int count = q.size();
        for (int i=0; i<count; i++){
            Node *cur = q.front();
            q.pop();
            
            if (reverse)
                s.push(cur -> key);     //  Here we Push alterative level of nodes_val to stack.
            else                        //  But in each level we push and pop node to queue..
                cout << cur -> key << " ";    //  We print alternative order BY using stack and queue..

            if (cur -> left != NULL)    q.push(cur -> left);
            if (cur -> right != NULL)   q.push(cur -> right);
        }
        if (reverse){
            while (s.empty() == false){
                cout << s.top() << " ";
                s.pop();
            }
        }
    reverse = !reverse;
        // cout << endl;
    }
}

/*             Method - 2 :-            TC -> O(N)... AS -> O(N)..
    1) Push root to the stack s1, 
    2) While any of the two stack is not empty then,
        While s1, is not empty  :-
            (a) Take out a node, print it.
            (b) Push Children of the taken out node into s2.
        While s2, is not empty  :-  
            (a) Take out a node, print it.
            (b) Push Children of the taken out node into s1.. in "reverse order"..

*/

int32_t main(){
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    printSpiral(root);
    return 0;
}