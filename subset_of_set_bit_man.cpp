#include<bits/stdc++.h>
using namespace std;

int subset(int ar[], int n){
    for (int i=0;i < (1 << n); i++){  // 1 << n => 2 pow (n);  
        for (int j=0; j<n; j++){
            if (i & (1 << j)){
                cout << ar[j] << " ";
            }
        }cout << endl;
    }
    
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    subset(ar, n);
    return 0;
}