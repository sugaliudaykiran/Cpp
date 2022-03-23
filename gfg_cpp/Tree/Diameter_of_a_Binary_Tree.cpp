/*
    Diameter of a Binary Tree   :-     
        No of nodes on the longest path between two leaf nodes..
                                10
                              /    \
                             20     30
                                   /  \
                                  40   50
                                 /
                                60
        
        ** In this we can observe that 20 -- 10 -- 30 -- 40 -- 60 is longest path between two leaf node.. is "5".
        ** In case NULL -> "0"    and in case of one node like  10 then diameter is "1".
   
                                    10
                                  /    \
                                20      60
                              /    \
                            30      80
                           /  \       \
                         40    50      90
                        /                \
                       60                 18 

            60 -- 40 -- 30 -- 20 -- 80 -- 90 -- 18    is longest path between two leaf node.. is "7".

    Three method of finding diameter of a Binary Tree are discussed :-
        Navie Solution :-
            Idea :- Find the following value for every node and return the maximum :
                        max(1+lh+rh)
                            lh -> left height
                            rh -> right height 
        
        Better :-       TC -> O(n)  AS -> O(n).. for hashing and take overhead to store each height..
            Idea :- Precompute height of every node and store it in a map..
                        Using unordered_map <Node *, int> m; then we get height in O(1).
                            By using map we can store each node's height. and we can get each height in O(n).. time.
        
        Efficient Solution :-       No overhead of map..
            1) While Find the each node left height and right height by this we can compute (1 + Lh + Rh)..
            2) By checking all nodes and Pick the max of it.. that is max(1 + Lh + Rh)..
            3) return the maximum height..
        ** This Function returns height, but sets the "res" variable to have diameter..
*/ 


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};

int height(Node *root){
    if (root == NULL)   return 0;
    else    return 1+ max(height(root -> left), height(root -> right));
}

//         Navie Solution :-        TC -> O(n^2)..      in worst case T(n) = T(n-1) + 0(n)..
int diameter(Node *root){
    if (root == NULL)   return 0;
    
    int d1 = 1 + height(root -> left) + height(root -> right);
    int d2 = diameter(root -> left);
    int d3 = diameter(root -> right);

    return max(d1, max(d2, d3));
}

//      Efficient Solution :-       TC -> O(n).. AS -> O(h).. for recursive tree functions..    
int res = INT_MIN;
int heights(Node *root){
    if (root == NULL)   return 0;
    int lh = heights(root -> left);
    int rh = heights(root -> right);

    res = max(res, (1 + lh + rh));
    return (1+ max(lh, rh));
}

int32_t main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> left -> left = new Node(50);
    root -> right -> right = new Node(60);
    root -> right -> right = new Node(70);

    cout << diameter(root) << endl;

    cout << "Height : " << heights(root) << endl; 
    cout << "Diameter : "<< res << endl;
    return 0;
}