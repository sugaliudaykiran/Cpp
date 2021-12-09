#include <bits/stdc++.h>
#include<climits>
using namespace std;

int32_t main(){
    int n;
    cout << "n : ";
    cin >> n;

    int ar[n];

    for (int i = 0; i < n; i++){
        cin >> ar[i];
    }

    int maxNo = INT_MIN;
    int minNo = INT_MAX;

    for (int i = 0; i < n; i++){
        if (ar[i] > maxNo){
            maxNo = ar[i];
        }
        // or another way is...
        minNo = min(ar[i], minNo);
    }

    cout << "Max_no : "<< maxNo << ", " << "Min_no : "<< minNo << endl;

    return 0;
}