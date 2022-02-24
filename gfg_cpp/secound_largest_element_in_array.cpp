#include<bits/stdc++.h>
using namespace std;

int lar(int ar[], int n){
    int res = 0;
    for (int i=1; i<n; i++){
        if (ar[res] < ar[i]){
            res = i;
        }
    }
    return res;
}
// Navie_Solution :-
int sec_lar(int ar[], int n){
    int largest = lar(ar, n);
    int res = -1;
    
    for (int i=0; i<n; i++){
        if (ar[largest] != ar[i]){
            if (res == -1){         // Nothing have started..
                res = i;            // And started assign..the index at 0..
            }
            else if (ar[res] < ar[i]){
                res = i;
            }
        }
    }
    return res;
}

/* Efficient_Approach :-
if A[i] > A[lar] --> res = lar, lar = i..
   A[i] == A[lar] --> Ignore..
   A[i] < A[lar] --|    # Here "res is lar"..
                   |--> if res == -1, res = i..
                        A[i] <= A[res] -> Ignore..
                        A[i] > A[res]  -> res = i..
*/
                                    // Tc --> 0(N).. AS --> 0(1)..
int sec_larg(int ar[], int n){
    int res = -1, lar = 0;
    
    for (int i=1; i<n; i++){
        if (ar[lar] < ar[i]){
            res = lar;
            lar = i;
        }
        else if (ar[i] != ar[lar]){
            if (res == -1 || ar[i] > ar[res]){
                res = i;
            }
        }
    }return res;
}

int32_t main(){
    int n;
    cin >> n;
    
    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    
    // cout << sec_lar(ar, n) << endl;
    cout << sec_lar(ar, n) << endl;

    return 0;
}