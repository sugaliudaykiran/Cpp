#include<bits/stdc++.h>
#include<map> 
using namespace std;

/*      Navie - Solution :=         TC -> O(N_LogN)
    1) sort the array..
    2) Check the previous elements with curr_ele (i = 1, c = 1)
    3) if (c > n/k) then print curr_ele..
    4) then check next elements..

*/
int n_by_k(int a[], int n, int k){      // TC -> O(N_LogN)
    sort(a, a+n);
    int i = 1, c = 1;

    while (i < n){          //  0(N)..
        while (i < n && a[i-1] == a[i]){
            i++;
            c++;
        }
        if (c > n/k){
            cout << a[i-1] << " ";
        }
        c = 1;
        i++;
    }
}

/*          Efficient - Solution :=         // TC -> O(N)..  AS -> O(N/K)..
    1) Insert all elements in map as the freq 
    2) check the each freq is greater than n/k, print them
    3) check next elements..
*/ 

int n_by_k_2(int a[], int n, int k){    // TC -> O(N)..  AS -> O(N)..
    unordered_map <int, int> um;

    for (int i=0; i<n; i++){
        um[a[i]] += 1;      //    um[a[i]]++;
    }

    for (auto z: um){
        if (z.second > n/k){
            cout << z.first << " ";
        }
    }
}

int32_t main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    n_by_k(a, n, k);
    cout << endl;

    n_by_k_2(a, n, k);
    return 0;
}