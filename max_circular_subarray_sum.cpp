#include<bits/stdc++.h>
using namespace std;

int kadanes(int ar[], int n){
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i=0; i<n; i++){
        currentSum += ar[i];
        if (currentSum < 0){
            currentSum = 0;
        }
        maxSum = max(currentSum, maxSum);
    }
    return maxSum;
}


int32_t main(){
    int n;
    cin >> n;
    int ar[n];

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    int wrapsum;
    int non_wrapsum;

    non_wrapsum = kadanes(ar, n);
    int totalSum = 0;

    for (int i= 0; i<n; i++){     // Positive elements to Negative elements //
        totalSum += ar[i];
        ar[i] = -ar[i];
    }
    
    wrapsum = totalSum + kadanes(ar, n);
    cout << max(wrapsum, non_wrapsum) << endl;

    return 0;
}

/*
**  maxSubarray_Sum = Total_sum_of_array - Sum_of_non-contributing_elements(non - rapping ones). **
*/