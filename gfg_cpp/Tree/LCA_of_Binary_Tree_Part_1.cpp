/*
    LCA of Binary Tree (Part 1) :-
        Introduction to LCA (Lowest Common Ancestor) problem and a O(n) solution to the problem.

    Ex :-                    10
                           /    \
                          20     30 
                               /    \
                              40    50
                             /     /   \
                            60   70     80  
    
    Were given, a binary tree and n1 = 60 and n2 = 70.. and we need to find the lowest common ancestor 
        ancestor means for example..  60 has 60, 40, 30, 10..  70 has 70, 50, 30, 10.. are ancestor..
        common ancestor of 60 and 70 is 10, 30.. and we need to find the LCA then 30 is the LCA..
    More ex:-
        1) LCA(20, 80)  ->  10
        2) LCA(80, 30)  ->  30
        3) LCA(70, 80)  ->  50

             Navie Solution :-          TC -> 0(n)..      and takes 3 traversal.. to find..
    1) First we fill the path of both n1 and n2..
    2) Now check lowest commom one among it..
        n1 = 70,  n2  = 80
        path_1 = [10, 30, 50, 70]
        path_2 = [10, 30, 50, 80]
    3) We can see that "50" is LCA..

    Part (2) :-
            Efficient Solution :-       TC -> 0(n)..  AS -> 0(h)..
    1) Requires one traversal and 0(h) extra space for the recursive traversal..
    2) Assumes that both n1, n2 exist in the tree. Does not give correct result when only one (n1 or n2) exits.

        Idea :- We do normally recursive traversal. we have the following cases for every node.
        1) If it is same as n1 or n2.
        2) If one of its subtrees contains n1 and other contains n2.
        3) If one of its subtrees contains both n1 and n2.
        4) If none of its subtrees contain any of n1 and n2.

                10
              /    \
             20    30 
                 /    \
                50     60
               /     /    \
              70    80     90
                             \
                              40
    Example for above cases :-
        1) n1 = 10, n2 = 40, cur_node = 10.. then return 10..
        2) n1 = 80, n2 = 40, cur_node = 60.. then return root of n1 and n2..
        3) n1 = 80, n2 = 40, cur_node = 30.. or 10.. then return, what it's subtree return..
        4) n1 = 80, n2 = 40, cur_node = 20.. then return NULL.. in case of 50 and 70 also return NULL..

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

bool path(Node *root, vector <Node *> &p, int n){
    if (root == NULL)   return false;
    p.push_back(root);
    if (root -> key == n)   return true;

    if (path(root-> left, p, n) || path(root -> right, p, n)){
        return true;
    }
    p.pop_back();
    return false;
}
//         Navie Solution  :-   TC -> 0(n).. and takes 3 traversal..
Node *lca(Node *root, int n1, int n2){
    vector <Node *> p1, p2;

    if ((path(root, p1, n1) == false) or (path(root, p2, n2) == false)){
        return NULL;
    }

    for (int i=0; (i<p1.size()-1 and i<p2.size()-1); i++){
        if (p1[i+1] != p2[i+1]){
            return p1[i];
        }
    }
    return NULL;
}
//      Part - 2    Efficient Solution :-   TC -> 0(n).. AS -> 0(h).. takes one traversal..
Node *lca2(Node *root,int n1,int n2){
    if (root == NULL)   return NULL;
    if (root -> key == n1 or root -> key == n2) return root;

    Node *lca_1 = lca2(root -> left, n1, n2);
    Node *lca_2 = lca2(root -> right, n1, n2);

    if (lca_1 != NULL && lca_2 != NULL) return root;
    if (lca_1 != NULL)  return lca_1;   // means lca_2 is NULL..
    else    return lca_2;   //  lca_1 be NULL (or) it's pointing to a node..
}

int32_t main(){

    Node *root = new Node(10);
    root -> left = new Node(50);
    root -> right = new Node(60);
    root -> left -> left = new Node(70);
    root -> left -> right = new Node(20);
    root -> left -> left -> left = new Node(40);
    root -> left -> right -> left = new Node(90);
    root -> left -> right -> right = new Node(80);
    root -> left -> right -> left -> left = new Node(30);

    int n1 = 30, n2 = 80;
    // Node *ans = lca(root, n1, n2);
    Node *ans = lca2(root, n1, n2);
    cout << "LCA : " << ans -> key << endl;
    
    return 0;   
}
