#include<bits/stdc++.h>
using namespace std;
// Navie-Solution :-                    TC -> 0(N_square)..
int max_profit(int ar[], int start, int end){
    if (end <= start){
        return 0;
    }
    int profit = 0;
    for (int i=start; i<end; i++){
        for (int j = i+1; j<= end; j++){
            if (ar[j] > ar[i]){
                int cur_profit = ar[j] - ar[i] + max_profit(ar, start, i-1) + max_profit(ar, j+1, end);
                profit = max(cur_profit, profit);
            }
        }
    }return profit;
}

// Efficient-Solution :-        In Cumulative.. Value are added.. TC --> 0(N)
int max_p(int ar[], int n){
    int profit = 0;
    for (int i=1; i<n; i++){        // Here we start at Index 1 to N..
        if (ar[i] > ar[i-1]){       
            profit += (ar[i] - ar[i-1]);    // Add profit.. if it is there ...
        }
    }
    return profit;
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n] ;     // => {1, 5, 3, 8, 12};
    for (int i=0; i<n; i++){
         cin >> ar[i];
    }

    // cout << max_profit(ar, 0, n-1) << endl;
    cout << max_p(ar, n);
    return 0;
}