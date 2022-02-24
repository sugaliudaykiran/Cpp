// Find a Peak Element :- if current element is greater than curr_last_element and curr_but_one_element ..
// Check the First and last element..also required..

#include<bits/stdc++.h>
using namespace std;

// Navie-Solution :-        TC --> O(N).. and AS -> O(1)..
int f_p(int ar[], int n){
    if (n == 1){
        return ar[0];
    }
    if (ar[0] >= ar[1]){
        return ar[0];
    }
    if (ar[n-1] >= ar[n-2]){
        return ar[n-1];
    }
    for (int i=1; i<n-1; i++){
        if (ar[i] >= ar[i-1] && ar[i] >= ar[i+1]){
            return ar[i];
        }
    }
    return -1;
}

// Efficient-Solution :- Using Binary_search TC --> O(log_N) and AS -> O(1)..
int peak(int ar[], int n){
    
    int low = 0, high = n-1;
    while (low <= high){
        int mid = (low + high) / 2;     // Check the Condition 
        if ((mid == 0 || ar[mid] >= ar[mid-1]) && (mid == n-1 || ar[mid] >= ar[mid+1])){ // Check the first or last element and front and but_one elements..
            return mid;
        }
        if (ar[mid] <= ar[mid-1] && mid > 0){   // Checking if the current element is less than but_one element.. and it is not equal to zero..
            high = mid-1;
        }
        else{               // similary with right side..
            low = mid+1;
        }
    }
    return -1;   // In case of No peak element is present..
}


int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << f_p(ar, n);
    cout  << peak(ar, n);

}