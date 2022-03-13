/*

Design a Stack with getMin() in O(1) Space

    Code(Assuming all Elements Positive) :-
        1) we maintain and extra variable to store the min value..
        2) If in case, stack has the min item and stored in min value if any item greater the min then we push, without changes..
        3) In case, of min item than min value is push then we store the item in difference of "cur_value - min_value".. and update the min..
        4) Here, Advantage of only positive by add negaitive item to stack, while pop we can idenitify the item.. and its value by min_value..

    Code(Handles Negatives) :-
        How does this works ?
        1) We push 2*X - Min_v only when X <= Min_v..
        2) So, 2*X - Min_v is always going to be less than (or) equal to X, 
                and X is going to be cur new  Min_v..
    **  2*X - Min_v = X + (X - Min_v)..      and (X-Min_v) will smaller or equal to zero..
    ** By this,    2*X - Min_v = X is smaller or equal to X.. so which push into the stack.. 

        3) In pop,  t = 2*Min_v - Prev_Min_v;
                    Prev_Min_v = 2*Min_v - t;   Here we use previous min..
*/ 

#include<bits/stdc++.h>
#include<stack>
using namespace std;

//          Assuming all Elements Positive :-
struct Mystack{
    stack <int> st;
    int min_v = INT_MAX;

    void push(int x){
        if (st.empty()){
            st.push(x);
            min_v = x;
            return;
        }

        if (x <= min_v){
            st.push(x - min_v);
            min_v = x;
        }
        else{
            st.push(x);
        }
    }

    int pop(){
        int t = st.top(); 
        st.pop();
        if (t <=0){ 
            int res = min_v;
            min_v = min_v - t;
            return res;     
        }
        else{
            return t;
        }
    }

    int top(){
        int t = st.top();
        return (t <= 0)? min_v: t;
    }

    int getMin(){
        return min_v;
    }
};

//          Handles Negatives :-    Little changes from the above code..
struct Mystack2{
    stack <int> st;
    int min_v = INT_MAX;

    void push(int x){
        if (st.empty()){
            st.push(x);
            min_v = x;
            return;
        }

        if (x <= min_v){
            st.push(2*x - min_v);   //  Here we take 2*x - cur_Min_v;
            min_v = x;
        }
        else{
            st.push(x);
        }
    }//           In pop,        t = 2*Min_v - Prev_Min_v;
       //               Prev_Min_v = 2*Min_v - t;   Here we use previous min..
    int pop(){
        int t = st.top(); 
        st.pop();
        if (t <= min_v){    //  Comparing with cur_min_v.. to handle negative value..
            int res = min_v;
            min_v = 2*min_v - t;    //  updating the min_v as 2*cur_Min_v - pop_val..
            return res;     
        }
        else{
            return t;
        }
    }

    int top(){
        int t = st.top();   
        return (t <= min_v)? min_v: t;  //  check with the min_v value.. to handle negative value..
    }

    int getMin(){
        return min_v;
    }
};


int32_t main(){

    Mystack2 st;
    st.push(4);
    st.push(7);
    st.push(9);
    st.push(1);
    
    cout << st.getMin() << endl;
    st.pop();
    cout << st.getMin() << endl;

    return 0;
}