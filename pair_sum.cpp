#include<bits/stdc++.h>
using namespace std;

bool pair_sum(int ar[], int n, int k){      //-----> for pairing the elements in array.---> O(n*2)
    for (int i=0; i<n-1; i++){
        for (int j=1; j<n; j++){
            if (ar[i]+ar[j] == k){
                cout << i << " " << j << endl;
                return 1;
            }
        }
    }
    return 0;
}
// ----------------------------------------------->
// --> O(n) only if Given Array is Sorted...
bool pair_sum_2(int ar[], int n, int k){            
    int low = 0;
    int high = n-1;

    while (low < high){
        if (ar[low] + ar[high] == k){
            cout << low << " " << high << endl;
            return 1;
        }
        else if (ar[low] + ar[high] > k){
            high--;
        }
        else{
            low++;
        }
    }
    return 0;
}



int32_t main(){
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }


    // cout << pair_sum(ar, n, k) << endl;
    cout << pair_sum_2(ar, n, k) << endl;      // --> O(n) only if Given Array is Sorted...

    return 0;
}