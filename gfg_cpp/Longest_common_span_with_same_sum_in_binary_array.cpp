#include<bits/stdc++.h>
#include<map>
using namespace std;

//      Navie - Solution :-         TC -> 0(N_square).. AS -> O(1)..
int lon(int a[], int b[], int n){
    int res = 0;

    for (int i=0; i<n; i++){
        int a_sum = 0, b_sum = 0;
        for (int j=i; j<n; j++){
            a_sum += a[j];
            b_sum += b[j];
            if (a_sum == b_sum){
                res = max(res, j-i+1);
            }
        }
    }
    return res;
}

/*          Efficient - Solution :-    
// Hint := the problem is going to reduce into the problem of longest subarray with 0 sum in an array..
    
        1) Compute a difference array 
            int temp[n];
            for(int i=0; i<n; i++){
                temp[i] = a[i] - b[i];
            }
        2) Return length of the longest subarray with 0 sum in temp..
            values in temp[] -> {0} if values are same in both.. 
                             -> {1} if values are 0 and 1..
                             -> {-1} if values are 1 and 0..
                             
*/
int lgs(int a[], int b[], int n){      // TC -> 0(N).. AS -> O(N)..
    int temp[n];
    for (int i=0; i<n; i++){
        temp[i] = a[i] - b[i];
    }

    unordered_map <int, int> um;
    int sum = 0, size = 0;
    for (int i=0; i<n; i++){
        sum += temp[i];

        if (sum == 0){  // To handle sum=0 at last index 
            size = i+1;
        }               // If this sum is seen before, then update max_len if required 
        else if (um.find(sum) != um.end()){
            size = max(size, i - um[sum]);
        }
        else {  // Else put this sum in hash table 
            um[sum] = i;
        }
    }
    return size;
}


int32_t main(){
    int n;
    cin >> n;

    int a[n], b[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int j=0; j<n; j++){
        cin >> b[j];
    }

    cout << lon(a, b, n) << endl;
    cout << lgs(a, b, n);
    return 0;
}