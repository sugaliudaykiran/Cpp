/*

Implementation of Huffman coding    :-  

    Ref  :- https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
    Ref2 :- https://www.geeksforgeeks.org/huffman-decoding/
    
*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

// A Huffman tree node
struct Node
{
    char data;      	// One of the input characters
    unsigned freq;      	// Frequency of the character
    Node *left, *right;     	// Left and right child

    Node(char dt, unsigned fq, Node* left = NULL, Node* right = NULL)
    {
        this -> data = dt;
        this -> freq = fq;
        this -> left = left;
        this -> right = right;
    }
};
        // For comparison of two heap nodes (needed in min heap)
struct Mycmp
{
    bool operator()(Node* l, Node* r)
    {
        return (l ->freq > r ->freq);
    }
};
//      Prints huffman codes from the root of Huffman Tree.
void printCode(struct Node* root, string str)
{
    if (!root)
        return;

    if (root -> data != '$')
    {
        cout << root -> data << " " << str << "\n";
    }
    printCode(root -> left, str + "0");
    printCode(root -> right, str + "1");
}
        // The main function that builds a Huffman Tree and print codes by traversing the built Huffman Tree
void printHcodes(char ar[], int freq[], int size)   //  TC -> O(n logn)..   AS -> 0(n)..
{
    priority_queue <Node*, vector<Node*>, Mycmp> h;     // Create a min heap & inserts all characters of data[]

    for (int i=0; i<size; ++i)
    {
        h.push(new Node(ar[i], freq[i]));
    }
    while (h.size() > 1)    	// Iterate while size of heap doesn't become 1
    {
        Node* l = h.top();  h.pop();    // Extract the two minimum freq items from min heap
        Node* r = h.top();  h.pop();

        Node* top = new Node('$', (l->freq + r->freq), l, r);
        h.push(top);
        // Create a new internal node with frequency equal to the sum of the two nodes frequencies. 
        //  Make the two extracted node as left and right children of this new node. 
		//  Add this node to the min heap '$' is a special value for internal nodes, not used
    }
    printCode(h.top(), "");
}

int32_t main()
{
    char arr[] = { 'a', 'd', 'e', 'f' };
	int freq[] = { 30, 40, 80, 60 };

	int size = sizeof(arr) / sizeof(arr[0]);

	printHcodes(arr, freq, size);

    return 0;
}