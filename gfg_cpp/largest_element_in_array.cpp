#include<bits/stdc++.h>
using namespace std;

void largest_ele(int ar[], int n){      // TC --> 0(N)..
    int lar = INT_MIN;
    int i;
    for (i=0; i<n; i++){
        if (lar < ar[i]){
            lar = ar[i];
        }
    }cout << lar  << endl;
}


int lar(int ar[], int n){       // TC --> 0(N_square)
    
    for (int i=0; i<n; i++){
        bool flag = true;
        for (int j=0; j<n; j++){
            if (ar[j] > ar[i]){
                flag = false;
                break;
            }
        }
        if (flag){
            return i;
        }
    }
    return -1;  // It could n't be reached..here -1..
}

/* Efficient-Solution :-
    A_i <= A_largest ---> Ignore..
    A_i > A_largest  ---> largest = A_i..
*/

int get_lar(int ar[], int n){           // TC --> 0(N)..
    int res = 0;
    for (int i=1; i<n; i++){
        if (ar[res] < ar[i]){
            res = i;
        }
    }return res;
}

int32_t main(){         
    int n;
    cin >> n;

    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }

    // largest_ele(ar, n);
    // cout << lar(ar, n)<< endl;  // Index is start from the i=0..
    cout << get_lar(ar, n) << endl;
    return 0;
}