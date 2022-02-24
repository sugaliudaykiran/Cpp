#include<bits/stdc++.h>
using namespace std;
// Naive_Solution :=                TC --> O(N_square)..
int MCSS(int ar[], int n){
    
    int res = ar[0];
    for(int i=0; i<n; i++){
        int cur_sum = ar[i];
        int cur_max = ar[i];
        for (int j=1; j<n; j++){
            int index = (i + j) % n;        // Based on the (i + j) % N ..
            cur_sum += ar[index];
            cur_max = max(cur_max, cur_sum);
        }
        res = max(res, cur_max);
    }
    return res;
}

/* Efficient_Solution :=    TC --> 0(N)..

Idea :  Take the Maximum of the following two..
    1) Maximum Sum of a Normal_subarray (Using Kadane's Algo..)
    2) Maximum Sum of a Circular_subarray (Using Kadane.. to Find the Min_Subarray Sum.. and subtract the Overall_Sum by Min_Subarray_Sum..);
    # Hence max(1, 2)..
    In this case the max_subarray may be the Normal_subarray or Circular_subarray..
*/

int kadane(int ar[], int n){        // Normal_Max_Subarray_Sum..    TC -> 0(N)..
    int res = ar[0], max_end = ar[0];
    for (int i=1; i<n; i++){
        max_end = max(max_end + ar[i], ar[i]);
        res = max(max_end, res);
    }
    return res;
}

int overallMax_sum(int ar[], int n){
    int max_normal = kadane(ar, n);
    if (max_normal < 0){        // In case of the all element are the Negative elements..simple return 0..
        return 0;
    }

    int arr_sum = 0;
    for (int i=0; i<n; i++){
        arr_sum += ar[i];
        ar[i] = -ar[i];             // Changing the element to Negative.. //
    }                       // Here Instead of subtract from the Arr_sum..can Need to "Add" the Negative of the Max_of the reverse elements of array...
    int max_circular = arr_sum + kadane(ar, n);
    return max(max_circular, max_normal); 
}





int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << MCSS(ar, n);
    cout << overallMax_sum(ar, n);
    return 0;
}
