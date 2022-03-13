/*
                            // It is an varition of stock span problem..
Previous Greater Element :-     
    Given an array of distinct integers, find the closest (positive wise) greater on left of every element.
        If there is no greater element on left, then print -1

*/ 

#include<bits/stdc++.h>
#include<stack>
using namespace std;
//          Navie - Solution :-              //  TC -> O(N^2).. 
void printPrevGreater(int ar[], int n){
    // int z = -1;
    // cout << z << " ";

    // for (int i=1; i<n; i++){
    //     int j;
    //     for (j=i; j>=0; j--){
    //         if (ar[j] > ar[i]){
    //             cout << ar[j] << " ";
    //             break;
    //         }
    //     }
    //     if (j == z)
    //         cout << z << " "; 
    // }

    // ** V.IMP another way..

    for (int i=0; i<n; i++){        //  TC -> O(N^2).. 
        int j;
        for (j=i-1; j>=0; j--){
            if (ar[j] > ar[i]){
                cout << ar[j] << " ";
                break;
            }
        }
        if (j == -1){
            cout << j << " ";
        }
    }
}

//      Efficient - Solution :-     TC -> O(N).. 
void printPrevGreater2(int ar[], int n){
    stack <int> st;
    st.push(ar[0]);
    cout << -1 << " ";

    for (int i=1; i<n; i++){
        while (st.empty() == false && ar[i] >= st.top()){
            st.pop();
        }

        int pg = (st.empty())? -1: st.top();
        cout << pg << " ";
        st.push(ar[i]);
    }
}



int32_t main(){
    int n = 8;
    int ar[n] = {15, 10, 18, 12, 4, 6, 2, 8};
    printPrevGreater(ar, n);
    cout << endl;

    printPrevGreater2(ar, n);
    return 0;
}