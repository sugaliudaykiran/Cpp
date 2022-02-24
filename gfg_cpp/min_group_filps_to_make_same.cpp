/*
Minimum Consecutive Flips
Given a binary array, we need to find the minimum of number of group flips to make all array elements same.
  In a group flip, we can flip any set of consecutive 1s or 0s.
*/

#include<bits/stdc++.h>
using namespace std;

// Navie_Solution :-  First travers and count the group of 1's and 0's and find the Min_group appear and flip.. 

// Efficient_Solution :-        // Trick works when first and last element are same group.. TC -> O(N)..

void printGroup(bool ar[], int n){   // Always Choosing the Secound difference to flip from 0's to 1's |or| 1's to 0's
    for (int i=1; i<n; i++){        // Checking from the first element if previous element..and first element..
        if (ar[i] != ar[i-1]){
            if(ar[i] != ar[0]){
                cout << "From " << i << "to";
            }
            else{
                cout << " " << (i-1) << endl;
            }
        }        
    }
    if (ar[n-1] != ar[0]){      // In case of Same count of 0's and 1's
        cout << " " << (n-1) << endl;
    }
}

int32_t main(){
    
    int n;
    cin >> n;

    bool ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    
    printGroup(ar, n);
    return 0;
}