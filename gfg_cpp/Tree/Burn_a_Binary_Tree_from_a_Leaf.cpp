/*
Burn a Binary Tree from a Leaf  :-
    We are given a binary tree and a leaf node, we need to find time to burn the 
        Binary Tree if we burn the given leaf at 0-th second. 

    Ex :-                 10
                       /     \
                     20       30
                   /   \        \
                 40     50       60
    
    Leaf = 50   O/p :-  4

    ** 50 which burns in 0's then its adjacent 20 burns in 1's then its adjacent 40 
            and 10 burns in 2's then its adjacent 30 burns in 3's and 60 burns in 4's..
    ** So it takes 4's to burn entirly tree..

    Try :-              10
                       /
                      20
                    /
                   30   
                  /  \
                 40   50
    
    Leaf = 50   O/p :- 3 
    
    ** 50 -> 30 -> 20 -> 10 takes 3 longest links..

    Idea :- Farthest node from the given leaf.. in above ex. 50 to 10 is farthest node..

    The "farthest" node must  be reachable through one of the ancestors (50, 30, 20, 10) for leaf "50"..
        Distance through 50 = 0 (leaf itself..)   
        Distance through 30 = 4 (left height + distance from root)   => 3 + 1 => 4
        Distance through 20 = 3 (distance from root + right height)  => 2 + 1 => 3
        Distance through 10 = 3 (distance from root + right height)  => 3 + 0 => 3


        Ex :-
                                     10        (2, 5)
                                   /    \
                      (1, 4)     20      30    (-1, 1)          //  Leaf = 50    
                               /    \ 
                (-1, 3)      40     50         (0, 1)  
                            /
            (-1, 2)      60             (-1, 2)
                        /       
            (-1, 1)   70                (-1, 1) 
                                         |   |->   Height
                                         |->  Distance from 50 if it's a descendant else -1.. 
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

//      Similiarity of Diameter of tree :-  
int res = 0;
int burnTime(Node *root, int leaf, int &dist){
    if (root == NULL)   return 0;
    if (root -> key == leaf){
        dist = 0;
        return 1;
    }

    int ldist = -1, rdist = -1;
    int lh = burnTime(root -> left, leaf, ldist);
    int rh = burnTime(root -> right, leaf, rdist);

    if (ldist != -1){
        dist = ldist + 1;
        res = max(dist + rh, res);
    }
    else if (rdist != -1){
        dist = rdist + 1;
        res = max(dist + lh, res);
    }
    return max(lh, rh) +1;
}

int32_t main(){

	Node *root=new Node(10);
	root -> left=new Node(20);
	root -> right=new Node(30);
	root -> left -> left=new Node(40);
	root -> left -> right=new Node(50);
	root -> left -> left -> left=new Node(60);
	root -> left -> left -> left -> left=new Node(70);
	
    int dist=-1, leaf=50;

	burnTime(root,leaf,dist);
    cout << res << endl;

    return 0;   
}