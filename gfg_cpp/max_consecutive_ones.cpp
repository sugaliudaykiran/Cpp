#include<bits/stdc++.h>
using namespace std;
// Navie-Solution   :- 
int MCO(int ar[], int n){           // TC --> O(N_square).. and AS --> 0(1)..
    int res = 0;
    for (int i=0; i<n; i++){
        int count = 0;
        for (int j=i; j<n; j++){
            if (ar[j] == 1){
            count++;
            }
            else{
                break;
            }
        }
        res = max(res, count);
    }
    return res;
}
//  Efficient-Solution     :-       // TC --> O(N) and AS --> O(1)..
int MCOs(int ar[], int n){
    
    int res = 0, count = 0;
    for (int i=0; i<n; i++){
        if (ar[i] == 0){
            count = 0;
        }
        else{           // then it is '1'..
            count++;
            res = max(res, count);  
        }
    }
    return res;
}


int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << MCO(ar, n);
    cout << MCOs(ar, n);
    return 0;
}