#include<bits/stdc++.h>
using namespace std;

// using Recursion..
void DTB(int n){
    // BASE CASE..
    if (n == 0) {return;}
    DTB(n/2);
    cout << n % 2 << " ";

}


int32_t main(){
    int n;
    cin >> n;
    DTB(n);
    return 0;
}