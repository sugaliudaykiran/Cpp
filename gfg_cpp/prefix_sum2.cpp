/* Maximum Occuring Element :-
    Given N ranges, Find the Maximum appearing element in the Both the ranges..

    ** IMP_Questions :-
                1) check if a given array can be divided into three parts with equal sum..
                2) check if there is a subarray with 0 sum..
                3) find the longest subarray with equal 0's and 1's..
*/


#include<bits/stdc++.h>
#include<cmath>
#include<climits>

using namespace std;

int max_occ(int left[], int right[], int n){    // In range of (zero to L[], R[] to 1000)..
    //vector <int> V[1000];                       // or can use array :- int ar[1000];  memset(arr, 0, sizeof(arr)) which assign value is 0..;
    int V[1000];
    memset(V, 0, sizeof(V));

    for (int i=0; i<n; i++){    
        V[left[i]]++;               // marking the present of elements..
        V[right[i]+1]--;              // for making the prefix_sum to make easy and count the frequency of the elements..
    }
    int max_sum = V[0], res = 0;    // pre_fix_sum..
    for (int i=1; i<1000; i++){
        V[i] += V[i-1];             // upto the range..
        if (max_sum < V[i]){    
            max_sum = V[i];         // storing the pre_fix sum..
            res = i;
        }
    }
    return res;
}


int32_t main(){
    int n;
    cin >> n;

    int left[n];
    for (int i=0; i<n; i++){
        cin >> left[i];
    }

    int right[n];
    for(int i=0; i<n; i++){
        cin >> right[i];
    }

    cout << max_occ(left, right, n);

    return 0;
}