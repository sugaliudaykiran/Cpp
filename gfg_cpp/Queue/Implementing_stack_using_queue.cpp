/*

Implementing stack using queue  :-
    This discusses the implementation of the stack using a queue.

    Consider a situation where we have library available for queue and we need stack library..
        How to implement the stack..

    ** We need to create our own stack and by using queue..
    ** There are multiple solution of this problem so, try to check it out..

    1_Idea :- 
        1) Here we use two queue and Q1 for storing and other Q2 for temp/Auxiliary Queue..
        2) In this we Pop the item at the front item of queue..
        3) Generally, in queue when push an item it will on end of queue .. 
                so, to implement the stack we need to push item at the same end of pop takes.. 
        4) Then we need to pop item at front..
        5) so.. by using the Auxiliary queue.. first we need push items present in Q1 to Q2..
        6) While Using Push, then push item to Q1 and move item from Q2 to Q1..
        7) By this we can Follow the LIFO order which Pop/Push will be on same end..
            steps :-
                1) Move all items from Q1 to Q2..
                2) Push item to Q1..
                3) Move all items from Q2 to Q1..
            ***         (or)
                1) Push X to Q2..
                2) Push all remaining items to Q1 to Q2..
                3) swap Q2, Q1..

    More variations :-  (Must try..)
        1) Implement stack using queue by making pop operation costly..
        2) Implement stack using only one queue (we use recursion call stack here)..
        3) Implement Queue using stack.
            a) By making enque() operation costly..
            b) By making deque() operation costly..
            c) By using one stack (And one recursion call stack..)
*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Stack{
    queue <int> q1, q2;
    int cur_size = 0;

    int top(){
        if (q1.empty()){
            return -1;
        }
        return q1.front();
    }

    int size(){
        return cur_size;
    }

    void pop(){
        if (q1.empty()){
            return;
        }

        q1.pop();
        cur_size--;
    }

    void push(int x){
        cur_size++;
        //  Push X first in empty q2..
        q2.push(x);
        
        //  Push all the remaining elements in q1 to q2..
        while (!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap the names of two queues..
        queue <int> q = q1;
        q1 = q2;
        q2 = q;
    }
};

int32_t main(){

    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    
    cout << st.size() << endl;
    st.pop();
    cout << st.top() << endl;
    
    return 0;
}

