/*

Flattening of a Linked List :- 

    ref :- https://www.geeksforgeeks.org/flattening-a-linked-list/

Given a linked list where every node represents a linked list and contains two pointers of its type: 
    (i) Pointer to next node in the main list (we call it ‘right’ pointer in the code below) 
    (ii) Pointer to a linked list where this node is headed (we call it the ‘down’ pointer in the code below). 
    
    All linked lists are sorted. See the following example  

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45

Write a function flatten() to flatten the lists into a single linked list. The flattened linked list should also be sorted. For example, for the above input list, output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50. 

*/ 

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *right, *down;
};

Node *head = NULL;

Node* merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;   // If first linked list is empty then second is the answer
    if (b == NULL)      
        return a;   // If second linked list is empty then first is the result

    Node* res;  //  Compare the data members of the two linked lists and put the larger one in the result
    if (a -> data < b -> data)
    {
        res = a;
        res -> down = merge(a -> down, b);
    }
    else
    {
        res = b;
        res -> down = merge(a, b -> down);
    }
    res -> right = NULL;
    return res;
}

Node* flatten(Node* root)
{
    if (root == NULL || root -> right == NULL)
        return root;
    // Recur for list on right
    root -> right = flatten(root -> right);
    //  Now Merge
    root = merge(root, root -> right);
    
    // Return the root it will be in turn merged with its left
    return root;
}

Node* push(Node* head_ref, int data)    //  Utility function to insert a node at beginning of the linked list
{
    Node* new_node = new Node();

    new_node -> data = data;
    new_node -> right = NULL;

    new_node -> down = head_ref;        //  Make next of new Node as head
    head_ref = new_node;                //  Move the head to point to new Node
    return head_ref;
}

void printList()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> down;
    }
    cout << endl;
}

int32_t main()
{
     
    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45
    */
    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);
 
    head->right = push(head->right, 20);
    head->right = push(head->right, 10);
 
    head->right->right = push(head->right->right, 50);
    head->right->right = push(head->right->right, 22);
    head->right->right = push(head->right->right, 19);
 
    head->right->right->right = push(head->right->right->right, 45);
    head->right->right->right = push(head->right->right->right, 40);
    head->right->right->right = push(head->right->right->right, 35);
    head->right->right->right = push(head->right->right->right, 20);
 
    // Flatten the list
    head = flatten(head);
 
    printList();
    return 0;
}

/*

Time Complexity: O(N*N*M) – where N is the no of nodes in main linked list (reachable using right pointer) and M is the no of node in a single sub linked list (reachable using down pointer). 

Explaination: As we are merging 2 lists at a time,

After adding first 2 lists, time taken will be O(M+M) = O(2M).
Then we will merge another list to above merged list -> time = O(2M + M) = O(3M).
Then we will merge another list -> time = O(3M + M).

We will keep merging lists to previously merged lists until all lists are merged.
Total time taken will be O(2M + 3M + 4M + …. N*M) = (2 + 3 + 4 + … + N)*M
Using arithmetic sum formula: time = O((N*N + N – 2)*M/2)

Above expression is roughly equal to O(N*N*M) for large value of N
Space Complexity: O(N*M) – because of the recursion. The recursive functions will use recursive stack of size equivalent to total number of elements in the lists, which is N*M.

Exercise: The above approach can be optimized using priority queue/ min heap. Then the time complexity would be O(N*M*Log(N)) and space complexity would be O(N). 
*/ 