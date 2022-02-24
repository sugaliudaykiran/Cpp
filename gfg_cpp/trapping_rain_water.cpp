#include<bits/stdc++.h>
using namespace std;
// Navie_Solution :-
int trap(int ar[], int n){      // 0(N_square)..
    int res = 0;

    for (int i=1; i<n-1; i++){  // Because of the first and last are can't be stored..
        int left_max = ar[i];           // then we start from Index -> 1 to N-1..
        for (int j = 0; j<i; j++){
            left_max = max(left_max, ar[j]);    // Get the max of left_side of current_Index..
        }

        int right_max = ar[i];
        for (int j=i+1; j<n; j++){
            right_max = max(right_max, ar[j]);      // get the max of right side of current_index..
        }

        res += min(left_max, right_max) - ar[i];     // Finally we do Min of left and right_max and remove current Index element..by increment of res..
    }
    return res;
}

// Efficient_Solution :- Getting the pre-compute Left Max, Right Max..
int traps(int ar[], int n){         // TC --> 0(N) and AS --> 0(N)..
    int left_max[n];
    int right_max[n];
    int res = 0;
    
    left_max[0] = ar[0];
    for (int i=1; i<n; i++){
        left_max[i] = max(left_max[i], ar[i-1]);
    }

    right_max[n-1] = ar[n-1];
    for (int i=n-2; i>= 0; i++){
        right_max[i] = max(right_max[i+1], ar[i]);
    }

    for(int i=1; i<n-1; i++){
        res += (min(left_max[i], right_max[i]) - ar[i]);
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;
    
    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout <<  trap(ar, n);
    cout << traps(ar, n);
    return 0;
}
