#include<bits/stdc++.h>
using namespace std;

int num_of1s(int n){
    int count = 0;

    while(n){       // n != 0
        n = n & (n-1);
        count += 1;
    }
    return count;
}


int32_t main(){
    int n;  //  n = 19;
    cin >> n;
    cout << num_of1s(n) << endl;
    return 0;
}


/*
(n & n-1) has same bits as n except the rightmost set bit..
update the n and increase the count..
*/