/* Repeating Elements Part (1)
 Rules :-  1) Array size should be N >= 2 ..
           2) Only one element should be repeats (Any Numbers of times)..
           3) All elements from 0 to Max(arr)..are present..
           4) Therefore " 0 <= Max(ar) <= N-2 "..
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Super - Navie Solution :=        TC -> O(N_square)..
int rep(int ar[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (ar[i] == ar[j]){
                return ar[i];
            }
        }
    }
    return -1;
}

// Navie - solution :-    TC --> O(Nlog_N)..and AS --> O(1)..
int r_e(int ar[], int n){
    sort(ar, ar+n);     // Start_Address , End_Address..[next contiguous location]
    
    for (int i=0; i<n-1; i++){
        if (ar[i] == ar[i+1]){
            return ar[i];
        }
    }
    return -1;
}

// Efficient - Solution :-      TC --> O(N).. and AS --> O(N)..
//  1) Create a boolean array of size N-1;
//  2) Visited[] --> {F, F, F, F} -> as Index the range is {0, 1, 2, 3}..
//  3) change the visited by looping the array.. and mark as T.. and if (visited[ar[i]] == true) then return ar[i]..
int rep_ele(int ar[], int n){
    bool visited[n-1];      // " 0 <= Max(ar) <= N-2 " that why we create array upto N-1..

    memset(visited, false, sizeof(visited));  // setting the default value as fasle..      

    for (int i=0; i<n; i++){
        if (visited[ar[i]] == true){    // if it already visited then return the value..
            return ar[i];
        }
        visited[ar[i]] = true;   // if it is first time of occurance then it will update to true in visited..
    }
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << rep(ar, n);
    // cout << r_e(ar, n);
    
    cout << rep_ele(ar, n);

    return 0;
}
