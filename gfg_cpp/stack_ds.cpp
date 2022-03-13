/*
    Ref1  ->  https://www.geeksforgeeks.org/stack-data-structure/
    Ref2 ->  https://www.geeksforgeeks.org/stack-in-cpp-stl/

    Stack :-    Stack is a linear data structure which follows a particular order 
                    in which the operations are performed. 
                
                In Stack, Insertion and Deletion, will be on one - side..
                The order may be LIFO(Last In First Out) or FILO(First In Last Out)..

    Operations :-
        1) isEmpty() -> Return true, if stack is empty, else false. { empty() }
        2) push(x)   -> Insert an item to the top of the stack.
        3) pop()     -> Removes an item from the top.
        4) peek()    -> Returns the top item.   { top() }
        5) size()    -> Returns the size of stack.

    Underflow :-  When pop() and peer() called the empty stack. {Un-define in cpp..}
    Overflow  :-  When push called on a full stack. {Using Vectors and Linked list we can avoid this issues..}

** Array Implementation of Stack :- 
    |-> Using Arrray :-     TC -> O(1)..  AS -> O(1)..
         Problems with this code :-
            1) Does not handles overflow and underflow.
            2) we need to provide capacity initially. No dynamic resizing..
    
    |-> Using Vector :- {Dynamically Resizable stack..} TC -> O(1).. AS -> O(1).. And insertion and deletion amounted O(1).. average time O(1).
            {Using Underline Vector..}
        .back()  => which return the last item in vector..
        .front() => which return the first item in vector..
        .push_back, .pop_back, .empty(), .size()..

    |-> Using Linked List :- {Using constant operations..}
            TC -> O(1).. AS -> O(1)..
*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

//      Using Linked List  :-   Tc -> O(1).. AS -> O(1)..
struct Node{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

struct Mystack{
    Node *head;
    int sz;         //  Size variable for reduce the traversal..

    Mystack(){
        head = NULL;
        sz = 0;
    }

    void push(int x){
        Node *temp = new Node(x);
        temp -> next = head;
        head = temp;
        sz++; 
    }

    int pop(){
        if(head==NULL){cout<<"Stack is Empty"<<endl;return INT_MAX;}
        int ds = head-> data;
        Node *temp = head;
        head = head -> next;
        delete (temp);
        sz--;
        return ds;
    }
    int size(){
        return (sz);
    }

    int peek(){
        if(head==NULL){cout<<"Stack is Empty"<<endl;return INT_MAX;}
        return head -> data;
    }
    int isEmpty(){
        return head == NULL;
    }
};



//      Using Vectors :-    TC -> O(1).. AS -> O(1).. And insertion and deletion amounted O(1).. average time O(1).
struct mystack2{
    vector <int> v;
    
    void push(int x){
        v.push_back(x);  
    }
    int pop(){
        int res = v.back();
        v.pop_back();
        return  res;
    }

    int size(){
        return (v.size());
    }
    
    bool isEmpty(){
        return (v.empty());
    }

    int peek(){
        return (v.back());
    }
};


//          Using Arrays :-      TC -> O(1)..  AS -> O(1)..
struct mystack{     
    int *ar;    //  pointing to array..
    int cap;    //  Here size of stack..
    int top;    //  index of top items in a stack..
    
    mystack(int c){
        cap = c;
        ar = new int [cap];
        top = -1;
    }
    void push(int x){
        if ((cap-1) == top){ cout << "Stack is Full" << endl; return; }
        top++;          // ar[++top] = x;
        ar[top] = x;   
    }

    int pop(){
        if (top == -1){ cout << "Stack is Empty" << endl; return INT_MIN; }
        int res = ar[top];
        top--;
        return res;    
    }
    int peek(){
        if (top == -1){ cout << "Stack is Empty" << endl; return INT_MIN; }
        return (ar[top]);
    }

    int size(){
        return (top +1); 
    }

    bool isEmpty(){
        return (top == -1);
    }
};

int32_t main(){

    Mystack ss;
    ss.push(10);
    ss.push(20);
    ss.push(30);
    cout << ss.pop() << endl;
    cout << ss.size() << endl;
    cout << ss.peek() << endl;
    cout << ss.isEmpty() << endl;
    cout << endl;
    
    mystack st(5);
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.pop() << endl;
    cout << st.size() << endl;
    cout << st.peek() << endl;
    cout << st.isEmpty() << endl;
    cout << endl;
    
    mystack2 s;
    s.push(10);
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    cout << endl;

    return 0;
}