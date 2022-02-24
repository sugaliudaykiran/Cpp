#include<bits/stdc++.h>
using namespace std;
// Using Recursion :-       TC ---> 0(2_power(N))..      Dp and Bracktracking can be used to solve..
void subset_sum(int ar[], int n, int sum){
    if (n == 0){
        return (sum == 0)?  1 : 0;
    }
    // Here the One is empty and not add element and subtract from the sum... 
    // another one is add and subtract element from the sum..till the sum == 0..
    return (subset_sum(ar, n-1, sum) + subset_sum(ar, n-1, sum-ar[n-1]));
}

int32_t main(){
    int n, sum, ar[n];

    cin >> n >> sum;

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    return 0;
}