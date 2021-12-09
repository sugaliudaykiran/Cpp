#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    cin >> n;

    char ar[n];
    cin >> ar;

    bool check = 1;

    for (int i=0; i<n; i++){
        if (ar[i] != ar[n-1-i]){
            check = 0;
            break;
        }
    }
    if (check){
        cout << "Given is an palindrome..!" << endl;
    }
    else{
        cout << "Given is not an palindrome..!" << endl;
    }
    

    return 0;
}