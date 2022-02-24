#include<bits/stdc++.h>
using namespace std;
// Naive - Solution :-        
int Max_len(int ar[], int n){   // TC --> O(N_square)..
    int res = 1;
    for (int i=0; i<n; i++){
        int curr = 1;
        for (int j=i+1; j<n; j++){  // Here the element may be Even and Odd or Odd and Even..
            if ((ar[j] % 2 == 0 and ar[j-1] % 2 != 0) || (ar[j] % 2 != 0 and ar[j-1] % 2 == 0)){
                curr++;
            }
            else{
                break;
            }
        }
        res = max(res, curr);
    }
    return res;
}

// Using Kandane's Algorithm :-     TC --> O(N)..
int Maxs_len(int ar[], int n){
    int res = 1, curr = 1;
    for (int i=1; i<n; i++){
        if ((ar[i] % 2 != 0 && ar[i-1] % 2 == 0)||(ar[i] % 2 == 0 && ar[i-1] % 2 != 0)){
            curr++;
            res = max(res, curr);
        }
        else{       // If condition is false then curr = 1..
            curr = 1;
        }
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << Max_len(ar, n);
    cout << Maxs_len(ar, n);
    return 0;
}