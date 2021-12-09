// Sort an array of 0s, 1s and 2s
// que -> https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// ans -> https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void sortArr(int ar[], int n){
    sort(ar, ar+n);
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >>  ar[i];
    }
    sortArr(ar, n);
    for (int i=0; i<n; i++){
        cout << ar[i] << " ";
    }cout << endl;

    return 0;
}