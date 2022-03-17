/*

        Design a Data Structure with Min and Max operations :-

    This about designing a data structure that supports the following operations in O(1) time.

    ** Here in this we assums that one end as Min values and another end as Max values.. so insertion/delection 
                on the both the ends will be takes O(1).. in the deque..

Some of the Operations..    
    1) Get Minimum
    2) Get Maximum
    3) Insert Minimum
    4) Insert Maximum
    5) Delete/extract Minimum
    6) Delete/extract Maximum
*/ 

#include<bits/stdc++.h>
#include<deque>
using namespace std;

struct Deque{
    deque <int> dq;

    void insertMin(int x){
        dq.push_front(x);
    }
    void insertMax(int x){
        dq.push_back(x);
    }

    int getMin(){
        return dq.front();
    }
    int getMax(){
        return dq.back();
    }

    int deleteMin(){
        dq.pop_front();
        return dq.front();
    }
    int deleteMax(){ 
        dq.pop_back();
        return dq.back();
    }
};


int32_t main(){
    
    Deque dq;
    dq.insertMax(10);
    dq.insertMin(5);
    dq.insertMax(15);
    dq.insertMin(3);

    cout << dq.getMin() << endl;
    cout << dq.getMax() << endl;

    cout << dq.deleteMax() << endl;

    return 0;
}