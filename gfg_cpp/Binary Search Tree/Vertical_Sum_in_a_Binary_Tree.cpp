/*

Vertical Sum in a Binary Tree   :-
Given a binary tree, we need to find sum of nodes in all vertical lines starting from 
    leftmost line to rightmost.

    ** We print the sum of same vertical lines.. it means the horizontal distance from the root should be same.. 
    ** in term, horizontal distance of root is 0..  when it's child on left is (horizontal distances of it's parent -1)..
    ** when it's child on right is (horizontal distances of it's parent -1)..
    ** That for right child we add "+1", for left child we subtract "-1"..
    
    Ex :-                       10      (0)
                              /    \
                      (-1)   20     30   (1)
                           /   \     
                    (-2)  5     15  (0)

            ** We have only one node on horizontal distance(hd) at "-2".. and one node on hd at "-1"..
            ** We have two nodes on hd at "0".. and one at hd "1"..
    ** NOTE :- we do sums items which has same hd..
            
            O/p :-   5  20  25  30

    Ex2 :-                              10                  10 - (0)            
                                      /    \    
                                    15      25              15 - (-1),      25 - (1)
                                  /    \
                                35      20                  35 - (-2),      20 - (0)
                                           \    
                                            75              75 - (1)
                                              \
                                               80           80 - (2)

            O/p :-  35  15  30  100 80      (we traverse on bases of hd (horizontal distance..))

    1) Create a map that store sum for a given Horizontal distance 
            mp[-2] = 35
            mp[-1] = 15
            mp[0] = 30
            mp[1] = 100
            mp[2] = 80
    2) Traverse the mp and print values..
            35  15  30  100  80
*/ 
#include<bits/stdc++.h>
#include<map>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};

//creating recursive function :-
void vsumr(Node *root, int hd, map <int, int> &mp){
    if (root == NULL){
        return;
    }
    
    vsumr(root -> left, hd-1, mp);
    mp[hd] += root -> key;              //  update if it has same hd..
    vsumr(root -> right, hd+1, mp);                     
}
//  creating wrapper function   :-      TC -> O(n loghd) + O(hd)..  => O(n loghd)..   AS -> O(hd)
void vsum(Node *root){               // where hd is total no. of possible horizontal distances..
    map <int, int> mp;
    int hd = 0;                 // horizontal distance for root is Zero..

    vsumr(root, hd, mp);

    for (auto sum: mp){
        cout << sum.second << " ";
    }cout << endl;
}


int32_t main(){

    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> left -> left = new Node(30);
    root -> left -> right = new Node(40);
    root -> right = new Node(50);

    vsum(root);
    return 0;
}
