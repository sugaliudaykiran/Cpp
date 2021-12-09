#include<bits/stdc++.h>
using namespace std;

int Subarray_pattern(int ar[], int n){
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            for (int k=i; k<=j; k++){
                cout << ar[k] << " ";
            }cout << endl;
        }
    }
}


int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    Subarray_pattern(ar, n);
    return 0;
}