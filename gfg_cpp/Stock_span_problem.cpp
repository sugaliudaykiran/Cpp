/*
            Stock span problem :-
    The problem of Stock span problem along with few variations.

    Navie - Solution :-
        ** On the Current item, it previous item should be smaller or equal than item (Including the item), it's condition..
    
    Efficient - Solution :-
        1) Observeration :-
            ** If there is a greater element on left side 
                Span = (Index of cur_element) - (Index of closest greater element on left side);
            ** Other - wise
                Span = (Index of cur_element) +1;
*/ 

#include<bits/stdc++.h>
#include<stack>
using namespace std;

//      Navie - Solution :-         TC -> O(N^2).. AS -> O(1)..
void printSpan(int ar[], int n){
    for (int i=0; i<n; i++){
        int c = 1;
        for (int j=i-1; (j>=0 && ar[j] <= ar[i]); j--){
            c++;
        }cout << c << " ";
    }cout << endl;
}

//      Efficient - Solution :-     TC -> 0(N).. AS -> O(N)..
void printSpan2(int ar[], int n){
    stack <int> st;
    st.push(0);
    cout << 1 << " ";   //  Here always the first item is span is '1'..

    for (int i=1; i<n; i++){    // In case of non empty and arr's stack's top item is smaller than cur_item then pop() the index out..
        while (st.empty() == false && ar[st.top()] <= ar[i]){   
            st.pop();
        }
                    // In case of empty stack then insert the cur_item (index+1) in stack..
        int span = (st.empty() == true)? i+1: i-st.top();
        cout << span << " ";  //  else.. (cur_item index - previous closest greater item index..) 
        st.push(i); //      Finally push item into the stack..
    }
    cout << endl;
}

int32_t main(){

    int n = 6;
    int ar[n] = {18, 12, 13, 14, 11, 16};
    printSpan(ar, n);

    printSpan2(ar, n);
    return 0;
}