/*

Floor in BST    :-
In this, discusses the concept of Floor in Binary Search Tree along with the discussion 
    on time complexity.

    Floor in BST :- 
        1) In this we are given BST and Key to find the node which should be equal 
            to key (or) "Largest value smaller than Key."
        2) Means find the clostest smaller, equal to key.. if "key is not found then return NULL".

    Ex :-                   10
                          /    \
                         5      15                 
                              /     \
                             12      30

    X = 14, we check with root which is smaller the X then we move right, 
        15 is greater then move left, 12 is smaller then we check it right, 
        it is NULL then we return "12".. because 12 is closest smaller..

    X = 4, we check with root which is greater, than we move left 5 is greater than X, 
        then we move left which is NULL then we return NULL.. because we are not found the
        closest smaller.. than X or equal to X.

    X  = 30, we check with root which is smaller then we move right of it, 15 is smaller than, 
        we move right of it which is 30 which is equal to X then we return 30.

    X = 100, Which is similiar to X = 30, but the greater value of BST is 30 then we move upto 30 then 
        we return 30 because, 30 is the closest smaller to X.

        Navie Solution :-       TC -> O(n).. AS -> O(h).. In Recursive and iterative using stack will take O(n).. extra-space..   
            ** We can use Inorder, Preorder, Postorder, Level order traversal.. 
            ** We check every key and check if it is clostest so far.. and keep updating the clostest one..
    

        Efficient Solution :-   TC -> O(h).. AS -> O(1).. 
            ** In this, We faces three types, and there are :-
                1) If root == x then we return root.
                2) If root > x then sure that X, will be on left sub-tree of root..
                3) If root < x then we take clostest node as root, and check the right of root.. if any case 
                    the x has equal to any node then return node..else if any node is smaller the x then 
                    we compare with clostest node and take the largest value which is smaller than x.
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

//          Floor in BST :-         TC -> O(h).. AS -> O(1)..
Node *floor(Node *root, int k){
    Node *res = NULL;

    while (root != NULL){
        if (root -> key == k){
            return root;
        }
        else if (root -> key > k){
            root = root -> left;
        }
        else{       //  In case of right side we update res and move to right..
            res = root;
            root = root -> right;
        }
    }
    return res;
}

int32_t main(){

    Node *root = new Node(50);
    root -> left = new Node(30);
    root -> left -> left = new Node(20);
    root -> left -> right = new Node(40);
    root -> right = new Node(70);
    root -> right -> left = new Node(60);
    root -> right -> right = new Node(80);
    root -> right -> left -> left = new Node(55);
    root -> right -> left -> right = new Node(65);

    Node *res = floor(root, 40);
    cout << res -> key << endl;

    return 0;
}