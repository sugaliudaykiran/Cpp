#include<bits/stdc++.h>
#include<cmath>
#include<climits>
using namespace std;

// Prefix Sum Array :-
int pre_fix_sum[10000];

void prefix_sum(int ar[], int n){
    pre_fix_sum[0] = ar[0];

    for(int i=1; i<n; i++){
        pre_fix_sum[i] = ar[i] + pre_fix_sum[i-1];
    }

}
                //              TC --> 0(1)..
int get_sum (int pre_fix_sum[], int l, int r){      // L -> left and r -> right Indexs..
    if (l != 0){
        return (pre_fix_sum[r] - pre_fix_sum[l-1]); // this are the Index of the queris..
    }
    else{
        return (pre_fix_sum[r]);
    }
}

// Equilibrium Point(Navie Method) :-   TC -> O(N_square)..
bool Eq(int ar[], int n){

    for (int i=0; i<n; i++){
        int left_sum = 0, right_sum = 0;
        for (int j=0; j<i; j++){    // Index of 0 to left_Side_Index...
            left_sum += ar[j];
        }
        for (int k = i+1; k<n; k++){    // Index of Current_Index to N..
            right_sum += ar[k];
        }
        if (left_sum == right_sum){
            return true;
        }
    }
    return false;
}

// Equilibrium Point(Efficient Method) :-  TC --> O(N).. AS -> O(1)..
// Here We are negoring the right_sum by using the (Total - ar[i])..

bool Eq2(int ar[], int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += ar[i];
    }
    
    int left_sum = 0;
    for(int i=0; i<n; i++){
        if (left_sum == (sum - ar[i])){
            return true;
        }
        left_sum += ar[i];
        sum -= ar[i];
    }
    return false;
}


int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    
    // int l, r;
    // cin >> l >> r;

    // prefix_sum(ar, n);

    // cout << get_sum(pre_fix_sum, l, r);

    // cout << Eq(ar, n);
    cout << Eq2(ar, n);
    return 0;
}