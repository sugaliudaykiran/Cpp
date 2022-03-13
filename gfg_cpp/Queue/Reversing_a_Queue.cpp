/*

         Reversing a Queue :-
    This discusses the efficient approach of Reversing a Queue.
    
    Iterative Code :-
        1) We use an Stack for reversing the queue..
        2) First create a empty stack and stores all item from the queue..
        3) traverse all items of stack and push it to the queue..
        
    Recursive Code :-
        ** In this, we need assuming that we are handled (n-1) of the queue..
            and where n is total items and "how to handle the n_th item"..
        {12, 5, 15, 20}
          ^  ----------
        front   |
                assuming we reverse the n-1 item of queue and we need to handle front item now..
        ** We can remove/Pop item from the queue and store a variable..
        ** and push the item after reversing the remaining part..
        {5, 15, 20} => {20, 15, 5} => {20, 15, 5, 12}..
    
    *** Here we using Functional call stack to store the calls..
*/ 

#include<bits/stdc++.h>
#include<queue>
#include<stack>
using namespace std;

void printQueue(queue <int> &q){
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }cout << endl;
}


//      Iterative - Solution :- 
void reverse(queue <int> &q){
    stack <int> s;
    while (!q.empty()){         //  for Queue front is similiar top in stack..
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

//     Recursive - Solution :-      TC -> O(N)..
void revs(queue <int> &q){
    if (q.empty()){         //  Base case.. simple return..
        return;
    }
    int it = q.front(); 
    q.pop();
    
    revs(q);
    q.push(it);
}

int32_t main(){

    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    // reverse(q);
    revs(q);

    printQueue(q);
    
    return 0;
}