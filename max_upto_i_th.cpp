#include<bits/stdc++.h>
#include<climits>
using namespace std;

int Maxs_upto_i(int ar[], int n, int index){
    int maxs = INT_MIN;
    for (int i=0; i<n; i++){
        maxs = max(maxs, ar[i]);
        if (index == i){
            cout << "Max_upto_i : " << maxs << endl;
            break;
        }
        else{
            cout << "Pls enter the Index in btw 0 - n index " << endl;
        }
    }
    
    
}

int32_t main(){
    int n;
    cout << "n : ";
    cin >> n;

    int ar[n];

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    // int maxs = INT_MIN;
    
    // for (int i=0; i<n; i++){
    //     maxs = max(maxs,ar[i]);
    //     cout << maxs << " ";
    // }

    int index ;
    cout << "Index : ";
    cin >> index;

    Maxs_upto_i(ar, n, index);
    return 0;
}