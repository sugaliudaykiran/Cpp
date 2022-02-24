#include<bits/stdc++.h>
using namespace std;
    //                          TC --> O(N) and AS --> O(N) because of temp[N]..
int rem_Dup(int ar[], int n){
    int temp[n];
    temp[0] = ar[0];
    int res = 1;

    for (int i=1; i<n; i++){
        if (temp[res-1] != ar[i]){
            temp[res] = ar[i];
            res++;
        }
    }
    for (int i=0; i<res; i++){
        ar[i] = temp[i];
    }
    return res;
}

// For less 'AS' -> O(1) and TC -> O(N)..
int remove(int ar[], int n){
    int res = 1;
    for (int i=1; i<n; i++){
        if (ar[res-1] != ar[i]){
            ar[res] = ar[i];
            res++;
        }
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;
                            // Array Should be Sorted..
    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    // Count of  Distinct Element in the Array is ..
    cout << rem_Dup(ar, n);
    // For Less 'AS'..
    cout << 
    return 0;
}