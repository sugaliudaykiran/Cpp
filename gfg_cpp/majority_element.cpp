#include<bits/stdc++.h>
using namespace std;
// Navie_Solution :-        // TC --> O(N_square)..
int majority_ele(int ar[], int n){
    for (int i=0; i<n; i++){
        int freq = 1;
        for (int j=i+1; j<n; j++){
            if (ar[i] == ar[j]){
                freq++;
            }
        }
        if (freq > n/2){    // Majority_element means which has Max_freq(or)Count is greater than N/2; 
            return i;
        }
    }
    return -1;
}

// Efficient_Solution :- Morus_mouting Algo..Major on Majority of Occurs..
                                            // TC -> O(N).. and AS -> O(1)..
int maj_ele(int ar[], int n){
    int count = 1, res = 0;
    for (int i=1; i<n; i++){
        if (ar[res] == ar[i]){
            count++;
        }
        else{           // Finding the Element..
            count--;
        }
        if (count == 0){
            res = i;
            count = 1;
        }
    }

    count = 0;
    for (int i=0; i<n; i++){
        if (ar[res] == ar[i]){  // Check if the element is actually is the majority..
            count++;
        }
    }
    if (count <= n/2){
        return -1;
    }
    return res; // Return any Index of the Majority_element..
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << majority_ele(ar, n);
    cout << maj_ele(ar, n);
    
    return 0;
}