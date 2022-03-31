/*

Check for BST   :-
In this, we discusses the problem of checking whether a binary tree is a binary search tree or not.
                
                10                              20
               /  \                            /  \                     NULL                10
              8    20                         8    30               
                  /  \                            /  \                   Yes                Yes
                 13   24                         18   35    

                YES..                            NO..   because 18 is lesser than 20, but lies on right subtree of root..

Method 1(A simple way but wrong solution)  :-
    Do any traversal..  For every node, check if its left child is smaller and righe is greater..
        1) assuming that we only check that left node should be lesser than it's root and right
            node should be greater than it's root..
        2) Which failures the BST conditions by which the Internal node will not be checked..

Method 2(Correct but not efficient) :-      TC -> O(N^2).. 
    For each "Every node", 
        1) Find the maximum in left subtree,
        2) Find the minimum in right subtree,
        3) Check if the current node is greater than the maximum and smaller than the minimum..
    ** In wrost case like squaie tree the time complexity is around O(N^2)..

Code :-

#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left;
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int maxValue(Node *root){
    if (root == NULL) 
        return INT_MIN; 
  
    int res = root->key; 
    int lres = maxValue(root->left); 
    int rres = maxValue(root->right); 
    if (lres > res) 
        res = lres; 
    if (rres > res) 
        res = rres; 
    return res; 
}

int minValue(Node* root) 
{ 
    if (root == NULL) 
      return INT_MAX; 
  
    int res = root->key; 
    int lres = minValue(root->left); 
    int rres = minValue(root->right); 
    if (lres < res) 
      res = lres; 
    if (rres < res) 
      res = rres; 
    return res; 
} 
int isBST(Node* root)  
{  
  if (root == NULL)  
    return 1;  
      
  if (root->left!=NULL && maxValue(root->left) > root->key)  
    return 0;  
      
  if (root->right!=NULL && minValue(root->right) < root->key)  
    return 0;  
    
  if (!isBST(root->left) || !isBST(root->right))  
    return 0;  
      
  return 1;  
}

int main() {
	
	Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
      
    if(isBST(root))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
          
    return 0;  
	
}
----------------------------------------------------------->
Method 3(Correct and Efficient) :-
    ** In this we maintain a range, and we keep updating while move left subtree and right subtree..
    For each every node,
        1) pass a range for every node,
        2) For root, range is -INF to +INF,
        3) For left child of a node, in range we change "Upper bound as the node's value"..
        4) For right child of a node, in range we change "Lower bound as the node's value"..

Method 4(Better Efficient Solution) :-      TC -> O(n)..     AS -> O(h)..
    ** Using inorder traversal.. result should sorted order..
    ** A binary tree is BST if "inorder traversal" of it is "in increasing order"..
        1) we do inorder traversal and maintain prev = INT_MAX, initially..
            check root's left and compare root with prev which should be greater than cur node..
        2) update prev to cur node..
        3) on call for right subtree..

*/      

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *right, *left;

    Node(int k){
        key = k;
        right = left = NULL;
    }
};

//      Check for BST :-        TC -> O(n).. By maintaining range..
bool isBST(Node *root, int min, int max){       //  It's a Pre-Order traversal..
    if (root == NULL)   return true;
                                //  In leftsubtree we change the range on root as maximum,   In rightsubtree we changes the range on root as minimum..
    return (root -> key > min and root -> key < max 
                and isBST(root -> left, min, root -> key) 
                and isBST(root -> right, root -> key, max));
}

//      Efficient Solution :-       TC -> O(n).. AS -> O(h)..
int prevs = INT_MIN;        //  take min value and compare with root -> key..
bool isBST2(Node *root){
    if (root == NULL){
       return true;
    }
    if (isBST2(root -> left) == false){
        return false;
    }
    if (root -> key <= prevs){   //  root -> key should be greater than prevs then return true..
        return false;
    }
    prevs = root -> key; //  updating the prevs..
    return isBST2(root -> right);
}

int32_t main(){
    Node *root = new Node(80);
    root -> left = new Node(70);
    root -> left -> left = new Node(60);
    root -> left -> right = new Node(75);
    root -> right = new Node(90);
    root -> right -> left = new Node(85);
    root -> right -> right = new Node(95);

    // cout << isBST(root, INT_MIN, INT_MAX) << endl;
    cout << isBST2(root) << endl;
    return 0;
}