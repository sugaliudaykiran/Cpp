#include<bits/stdc++.h>
using namespace std;

// Navie_solution :-                O(N_square)..
bool is_sort(int ar[], int n){
    for(int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (ar[j] < ar[i]){
                return false;
            }
        }
    }return true;
}

// Efficient-solution  :-   TC  --> O(N)..
bool if_sort(int ar[], int n){
    for (int i=1; i<n; i++){
        if (ar[i] < ar[i-1]){
            return false;
        }
    }return true;
}

int32_t main(){
    int n;
    cin >> n;
    
    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << is_sort(ar, n) << endl;
    cout << if_sort(ar, n) << endl;

    return 0;
}