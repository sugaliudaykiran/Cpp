#include<bits/stdc++.h>
#include<map>
using namespace std;

//     Navie - Solution :=      // TC -> 0(N_square).. AS -> O(1)..
int ls(int a[], int n){
    int res = 0;

    for (int i=0; i<n; i++){
        int c0 = 0, c1 = 0;
        for (int j=i; j<n; j++){
            if (a[j] == 0){
                c0++;
            }
            else {
                c1++;
            }
            if (c0 == c1){
                res = max(res, c0+c1);
            }
        }
    }
    return res;
}

/*    Efficient - Solution :=       TC => 0(N).. AS -> O(N)..
    1) replace every 0 with -1..    
        for (int i=0; i<n; i++){        -> 0(N)
            if (a[i] == 0){
                a[i] = -1;
            }
        }
    2) now call the function to find length of the "longest subarray" with 0 sum.. {sum = 0}  -> 0(N) 
        overall.. Tc -> 0(N)
*/

int log_s(int a[], int n){      //  TC -> 0(N).. AS -> O(N)..
    int sum = 0;
    for (int i=0; i<n; i++){
        if (a[i] == 0){
            a[i] = -1;
        }
    }

    unordered_map <int, int> um;
    int res = 0, pre_sum = 0;

    for(int i=0; i<n; i++){
        pre_sum += a[i];
        if (pre_sum == sum){
            res = i+1;
        }
        if (um.find(pre_sum) == um.end()){
            um.insert({pre_sum, i});
        }
        else if (um.find(pre_sum - sum) != um.end()){
            res = max(res, i - um[pre_sum - sum]);
        }
    }
    return res;
}

int32_t main(){

    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << ls(a, n) << endl;
    cout << log_s(a, n) << endl;
    return 0;
}