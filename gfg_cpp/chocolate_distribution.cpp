/*
        The famous Chocolate Distribution Problem based on a few rules :-
        Rules :-  
        1) In this Question we are Given an array..
        2) and "M" is the No of Childrens need to Distributed..
        3) Each Children get One Chocolate.. and Based on "M" we need to Solve the Minimum Distribution..are required..

        Idea to Solve :-        TC --> O(N_logN).. and AS --> O(N_logN)..
        1) In this we need to Sort the Array.. by this we Get the minimum Ordered elements in the array..which follows the conditions..
                 if the Question reqiures the Maximum then we will Sort the array in Descending..order..
        2) Then assumes the First "M" elements are Minimum..as res..
        3) Iterating "j" loop from 1 to { j+M-1 < N } which is lesser than N..
        4) And Check the --> min(res, ar[j+m-1] - ar[j])..which check any min is Exists..
        5) It Finally the Result is res..
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int Cho_d(int ar[], int n, int m){
    sort(ar, ar+n);
    int res = ar[m-1] - ar[0];
    for (int j = 1; (j+m-1) < n; j++){
        res = min(res, ar[j+m-1] - ar[j]);
    }
    return res;
}

int32_t main(){
    
    int n, m;
    cin >> n >> m;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    cout << Cho_d(ar, n, m);
    return 0;
}
