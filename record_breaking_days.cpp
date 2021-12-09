#include<bits/stdc++.h>
#include<climits>
using namespace std;

int32_t main(){
    int n;
    cout << "n : ";
    cin >> n;
    int ar[n+1];
    ar[n] = -1; // because for the last element of array should have empty;

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    if (n == 1){
        cout << "1" << endl;
        return 0;
    }
    int mx = INT_MIN;
    int ans = 0;                // count of record_breaking_days...
     
    for (int i=0; i<n; i++){
        if(ar[i] > mx && ar[i] > ar[i+1]){
            ans++;
        }
        mx = max(mx, ar[i]);
    }
    cout << ans << endl;
    return 0;
}

/*
Here we need to a[i] > mx;
a[i] > a[i+1] if (i+1 < n) and update mx, mx = max(mx, a[i]),, so it reduces to O(n) --> O(1).
*/