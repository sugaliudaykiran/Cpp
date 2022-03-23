/*
Serialize and Deserialize a Binary Tree
    In this, talks about serialize and deserialize a binary tree.
         It discusses on preorder traversal based approach.

    Serialize means which we need to convert binary tree into string/Array..
    Deserialize means convert back Array/string into a binary tree and return root of tree..

    Applications :-
        1) Data should be serialize to pass through the network..
        2) While creation of binary tree, while test case be in deserialize way..
    
*** In these we "avoid using string operations".. /   We can construct tree using "Inorder and preoder/postorder/level order traversal"..

Code(Serialize) :-      void serialize(Node *root, vector <int> &arr){}

    1) We use special mark as "-1" for NULL representation..  assumption that "-1" is not present in tree as data..
    2) In these use "preorder traversal" (root, left, right).. and then Constructs array.. how ?
    3) We check root and its left subtree and right subtree and it's left and right. if any of them is NULL then 
        we mark it as "-1".. and check another node..

            Ex :-               10
                               /                => 10  20  -1  -1  -1   
                              20                
            Ex2:-
                              10
                            /   \
                           20    30             => 10  20  -1  -1  30  -1  -1

Code(Deserialize)  :-   Node *deserialize(vector <int> &arr){}
    1) We again need to use "preorder traversal" (root, left, right) and travers the array one by one..
    2) When we see "-1" we insert NULL in that place..

        Ex :-   10  20  30  -1  40  -1  -1  -1  -1  

                            10
                           /   \ 
                          20    NULL
                         /   \   
                        30    NULL  
                       /  \
                (-1)NULL   40
                          /  \
                        NULL  NULL

*/ 

#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};

//              Serialize of Binary Tree :-     TC -> 0(n)..
const int Empty = -1;

void ser(Node *root, vector <int> &v){
    if (root == NULL){
        v.push_back(Empty);
        return;
    }

    v.push_back(root -> key);
    ser(root -> left, v);
    ser(root -> right, v);
}

//            Deserialize of Binary tree :-     TC -> 0(n)..
int index = 0;
Node *deser(vector <int> &v){
    if (index == v.size())  return NULL;

    int val = v[index];
    index++;

    if (val == Empty){
        return NULL;
    }
    Node *root = new Node(val);
    root -> left = deser(v);
    root -> right = deser(v);
    return root;
}

int32_t main(){
//              Deserialize :-
    vector <int> v1 = {10, 20, -1, -1, -1};
    Node *r1 = deser(v1);
    cout << r1 -> key <<" "<< r1 -> left -> key << endl;

//              Serialize   :-
    Node *root = new Node(10);
    root -> left = new Node(20);

    vector <int> v;
    ser(root, v);

    for (auto x: v){
        cout << x << " ";
    }cout << endl;

    return 0;
}