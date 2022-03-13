/*
    Stack with getMin() in O(1) :-
        Design a stack that supports normal stack operatiosn in O(1) and also supprots getMin() in O(1).

*/ 

#include<bits/stdc++.h>
#include<stack>
using namespace std;

struct Mystack{
    stack <int> ms; //  Main stack..
    stack <int> as; //  Auxiliary stack..

    void push(int x){       //  TC -> O(1).. AS -> O(N)..overall extra space..
        if (ms.empty()){
            ms.push(x);     //  If in case of empty stack..
            as.push(x);
            return;
        }

        if (as.top() >= x){
            as.push(x);
        }
        ms.push(x);
    }

    void pop(){
        if (ms.top() == as.top()){
            as.pop();
        }
        ms.pop();
    }
    int getMin(){   
        return as.top();
    }
};


int32_t main(){

    Mystack st; //  In this always return the min of stack.. after every push and pop..
    st.push(3);
    st.push(5);
    st.push(10);
    st.pop();
    st.push(1);
    // st.pop();
    st.push(2);
    st.pop();

    cout << st.getMin() << endl;
    return 0;
}