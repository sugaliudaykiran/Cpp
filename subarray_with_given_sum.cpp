#include<bits/stdc++.h>
using namespace std;

// using brute-force apporach :-        // time complexity - O(n*2);

int using_subarray(int ar[], int n, int givenSum){
    int start = 0;
    int end = 0;
    int current_sum = 0;
    for (int i=0; i<n; i++){
        current_sum = 0;
        for (int j=i; j<n; j++){
            current_sum += ar[j];
            if (current_sum == givenSum){
                start = i;
                end = j;
                cout << start << " " << end << endl;
                break;
            }
        }
    }
}


int32_t main(){
    int n, s;
    cin >> n >> s;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    
    int i=0, j=0, st=-1, en =-1, sum = 0;
    
    while (j<n && sum + ar[j] <= s){
        sum += ar[j];
        j++;
    }
    if (sum == s){
        cout << i+1 << " " << j << endl;
        return 0;
    }

    while (j < n){
        sum += ar[j];
        while (sum > s){
            sum -= ar[i];
            i++;
        }
        if (sum == s){
            st = i+1;
            en = j+1;
            break;
        }
        j--;
    }
    cout << st <<" "<< en<<endl;
 

    //  using_subarray(ar, n, givenSum); ------------> O(n* 2);

    // using optimized way :- uisng two pointers way.
    /*
    ** using 2 pointers st, en and a variable currsum sum from st to en.
    ** increment en till currsum + a[en] > S(given Sum).
    ** start increment st until currsum <= S... ---> O(n);
    */

    return 0;
}