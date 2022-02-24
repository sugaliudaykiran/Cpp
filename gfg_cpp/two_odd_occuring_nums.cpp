#include<bits/stdc++.h> 
using namespace std;
// Navie-Solution -> 0(n_square)
void two_odd_occuring(int ar[], int n){
    for (int i=0; i<n; i++){
        int count = 0;
        for (int j=0; j<n; i++){
            if (ar[i] == ar[j]){
                count++;
            }
        }
        if (count % 2 != 0){
            cout << ar[i] << endl;
        }
    }
}
// Efficient-Solution :-                    0(N)..
void twos(int ar[], int n){
    int xors = 0, res1 = 0, res2 = 0;
    for(int i=0; i<n; i++){
        xors ^= ar[i];
    }
    int rm = xors & (~(xors - 1));  // Right-Most-Set-bit..
    for (int i=0; i<n; i++){
        if ((ar[i] & rm) != 0){      // It check array with the rm .. and xor with odd one..
            res1 = res1 ^ ar[i];
        }
        else{
            res2 = res2 ^ ar[i];
        }
    }
    cout << res1 << " " << res2 << endl;

}

int32_t main(){
    int n;
    cin >> n;
    
    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    // two_odd_occuring(ar, n);
    twos(ar, n);
    return 0;
}