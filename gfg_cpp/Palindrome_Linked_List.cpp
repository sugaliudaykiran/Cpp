/*
    Palindrome Linked List  :=
        
        Naive Code  :-  Using stack     TC -> 0(N).. AS -> 0(N)..
            1) we use stack to store the item of node one by one.. and again traverse the list again to check..
            2) compare the top of stack with each node and if it doesn't match we return false..
            3) if match then return true..

        Efficient Code  :-      TC -> 0(N).. AS -> 0(1)..
            1) First we find the mid node of the linked list..
            2) Reverse the secound half of the list..
            3) check the head to middle node with the middle +1 node to end of the list (which is reversed one..)


*/ 
#include<bits/stdc++.h>
#include<stack>
using namespace std;

struct Node{
    
    char data;   // data
    Node *next; //  Pointer
    Node(char x){    // constructor
        data = x;
        next = NULL;
    }
};

void printList(Node *head){
    // Node *cur = head;        (or) Using direct head instead cur..
    while (head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }cout << endl;
}

//       Navie - Solution :-    TC -> 0(N).. AS -> 0(N)..
bool isPalindrom(Node *head){
    if (head == NULL){
        return false;
    }
    stack <char> st;

    Node *cur;
    for (cur = head; cur != NULL; cur = cur -> next){
        st.push(cur -> data);
    }

    for (cur = head; cur != NULL; cur = cur -> next){
        if (st.top() != cur -> data){
            return false;
        }
        st.pop();
    }return true;
}

//      Reverse the half part..
Node *revList(Node *head){
    if (head == NULL || head -> next == NULL)return head;
    
    Node *rest_head = revList(head -> next);
    Node *rest_tail = head -> next;
    rest_tail -> next = head;
    head -> next = NULL;
    return rest_head;
}
//   Efficient - Solution :-     TC -> 0(N).. AS -> 0(1)..
bool isPal(Node *head){
    if (head == NULL)return NULL;

    Node *fast = head, *slow = head;
    while (fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node *rev = revList(slow -> next);
    Node *cur = head;
    while (rev != NULL){
        if (cur -> data != rev -> data){
            return false;
        }
        cur = cur -> next;
        rev = rev -> next;
    }
    return true;
}

int32_t main(){    
                                    //  try for R A D A R 
    Node *a = new Node('g');
    a -> next = new Node('f');
    a -> next -> next = new Node('g');
    
    printList(a);
    cout << isPalindrom(a); cout << endl;

    printList(a);   //  Here the output which is reversed the secound half..
    cout << isPal(a);
    return 0;
}