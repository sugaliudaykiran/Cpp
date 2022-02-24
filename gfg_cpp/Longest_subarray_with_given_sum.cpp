#include<bits/stdc++.h>
#include<climits>
#include<map>
using namespace std;

//      Navie - Solution :=     {take both length of subarray which is equal to sum and do max(s1, s2)};
int long_s(int a[], int n, int sum){    //   TC -> O(N_square)..    AS -> O(1)..
    int mx_l = 0;
    for (int i=0; i<n; i++){        // "j-i+1" which provide the length of subarray..
        int cur_sum = 0;
        for (int j=i; j<n; j++){
            cur_sum += a[j];
            if (cur_sum == sum){
                mx_l = max(mx_l, j-i+1);
            }
        }
    }
    return mx_l;
}

    //      Efficient - Solution :=     pre_sum1 + sum = pre_sum2 --->  pre_sum2 - sum = pre_sum1..
int ls(int a[], int n, int sum){                //          TC --> 0(N)..   AS -> O(N)..
    unordered_map <int, int> um;    // it is an unordered_map..
    int res = 0, pre_sum = 0;
    
    for (int i=0; i<n; i++){
        pre_sum += a[i];        
        if (pre_sum == sum){    //      Initial case
            res = i+1;          // if i=0 then in such case we need to count its length which is "1"..
        }
        if (um.find(pre_sum) == um.end()){      // if pre_sum is not present then insert into the hash_map.. key as element and value as index..
            um.insert({pre_sum, i});
        }
        if (um.find(pre_sum - sum) != um.end()){    // if (pre_sum - sum) is present in map then check the max(curr_res, (i_th_pos - map[pre_sum - sum]))
            res = max(res, i - um[pre_sum - sum]);          //                                   which is alredy existing val in map         <-|
        }
    }
    return res;
}

int32_t main(){
    int n, sum;  
    cin >> n >> sum;

    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << long_s(a, n, sum) << endl;
    cout << ls(a, n, sum) << endl;

    return 0;
}