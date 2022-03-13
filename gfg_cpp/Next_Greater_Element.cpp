/*
            Next Greater Element    :-
The below problem:
    Given an array of distinct integers, 
    find the NextGreater(position-wise closest and on the right side) of every array elements.

*/ 

#include<bits/stdc++.h>
#include<stack>
using namespace std;
//          Navie - Solution :-
void printNextGreat(int ar[], int n){   //  TC -> O(N^2).. AS -> O(1)..
    for (int i=0; i<n; i++){
        int j;
        for (j=i+1; j<n; j++){
            if (ar[i] < ar[j]){
                cout << ar[j] << " ";
                break;
            }
        }
        if (j == n){
            cout << -1 << " ";
        }
    }
}

//          Efficient - Solution :-     TC -> O(N)..    AS -> O(N)..
vector <int> printNextGreat2(int ar[], int n){
    vector <int> v;
    stack <int> st;         //      In this output is prints in reverse order..
    st.push(ar[n-1]);       //  so, we use vector, and reverse it..
    // cout << -1 << " ";
    v.push_back(-1);
    for (int i=n-2; i>=0; i--){ //  push one and pop ones.. so 2N stack push and pop operations..
        while (st.empty() == false && st.top() <= ar[i]){
            st.pop();
        }

        int nextGre = (st.empty())? -1: st.top();
        v.push_back(nextGre);
        // cout << nextGre << " ";
        st.push(ar[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int32_t main(){
    int n = 8;
    int ar[n] = {5, 15, 10, 8, 6, 12, 9, 18};
    
    printNextGreat(ar, n);
    cout << endl;

    for (int z : printNextGreat2(ar, n)){
        cout << z << " ";
    }cout << endl;

    return 0;
}