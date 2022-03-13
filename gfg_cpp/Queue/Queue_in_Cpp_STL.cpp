/*
    Queue in C++ STL    :-
        This discusses the implementation of Queue in C++ STL.
           We will also learn various operations that the Queue STL libraries have to provide.

    Queue follows FIFO.. which best examples of First comes First serves..
    
    some of operations are in STL like.. take O(1)..
        push()  :- similiar to enqueu().. insert item at next rear/back..
        pop()   :- similiar as deque().. removes item of front and update the front..
        front() :- return front of queue.. and modifies when we call deque()..
        back()  :- return rear of queue.. and modifies when we call enque()..
        empty() :- if stack is empty return true..
        size()  :- return size of queue..

    ** Queue can implemented on any underlying Container that Provides 
            the following Functions like..
                empty(), size(), front(), back(), "push_back"(), "pop_front"()..
    
    ** There are two Container which Provides Queue.. and they are "list, dequeue"..
    ** dequeue is by default Implemented queue..
    ** Queue is an Container Adapter like stack which works on top of Other Containers..
    
*/  

#include<bits/stdc++.h>
#include<queue>
using namespace std;

int32_t main(){
    queue <int> qu;

    qu.push(10);
    qu.push(20);
    qu.push(30);

    // cout << qu.front() << " " << qu.back() << endl;
    // qu.pop();
    // cout << qu.front() << " " << qu.back() << endl;


    // while (qu.empty() == false){
    //     cout << qu.front() << " " << qu.back() << endl;
    //     qu.pop();
    // }

    cout << qu.size() << endl;

    return 0;
}