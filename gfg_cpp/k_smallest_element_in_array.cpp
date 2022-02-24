#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Navie - Solution :-          TC --> O(N_LogN)..and Modify the Orginal Array..
int k_small(int ar[], int n, int k){
    sort(ar, ar+n);
    return ar[k-1];
}

// Efficient Solution :- TC --> 0(N_Square).. which is Greater than Navie Solution 
                                    //  but In case of the Average case is Works as Linerly..so it Most effective..
// Using Lomuto Partition :- Which is Best In this Case of Partition..
int Lomuto_p(int ar[], int low, int high){
    int i = low-1, pivot = ar[high];

    for (int j=low; j<high-1; j++){
        if (ar[j] < pivot){
            i++;
            swap(ar[i], ar[j]);
        }
    }
    swap(ar[i+1], ar[high]);
    return i+1;
}
// Quick Select :-          // It changes the Orginal Array..
int Qselect(int ar[], int n, int k){
    int low = 0, high = n-1;
    while (low <= high){
        int p = Lomuto_p(ar, low, high);

        if (p == (k-1)){
            return p;
        }
        else if (p > (k-1)){
            high = p -1;
        }
        else {
            low = p +1;
        }
    }
    return -1; // In case of "K" is Greater than N..
}



int32_t main(){
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << k_small(ar, n, k) << endl;
    
    int idx = Qselect(ar, n, k);
    cout << ar[idx] << endl;

    return 0;
}