#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    cout << "n : ";
    cin >> n;

    int ar[n];

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    int ans = 2;
    int pd = ar[1] - ar[0];
    int j = 2;
    int current = 2;

    while (j < n){
        if (pd == ar[j]-ar[j-1]){
            current++;
        }
        else {
            pd = ar[j] - ar[j-1]; // previous_common_difference (pd);
            current = 2;
        }
        ans = max(current, ans);
        j++;
    }
    cout << "Longest_arithematic_subarray_length: " << ans << endl;
    return 0;
}

/*
in this has two case are :-
1)  (previous_common_difference) pd == ar[j] - ar[j-1]; --> Current ans increase by 1. and ans = max(ans, current);
2)  pd != ar[j] - ar[j-1]; --> update Current ans to 2;
*/