#include<bits/stdc++.h>
using namespace std;

int linearsearch(int ar[], int n, int k){   // TC --> O(N).. and better one is Binary_search -> O(logN)..
    for (int i=0; i<n; i++){
        if (ar[i] == k){
            return i;
        }
    }return -1;
}


int32_t main(){
    int n, k;
    cin >> n >> k;

    int ar[n];

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    cout << linearsearch(ar, n, k) << endl;
    return 0;
}