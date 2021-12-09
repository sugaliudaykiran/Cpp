# include <bits/stdc++.h>
using namespace std;

int32_t main(){
    // int i = 1;
    // i = i++ + ++i;
    // cout << i << endl;

    // int i = 1;
    // int j = 2;
    // int k;
    //     //1 //2 //1->2 //2->3 //3 //4
    // k = i + j + i++ + j++ + ++i + ++j;
    // cout << i <<" "<< j <<" "<< k << endl;

    // int i = 0;
    // i = i++ - --i + ++i - i--;
    // cout << i << endl;

    // int i = 1;
    // int j = 2;
    // int k = 3;
    // int m;

    // m = i-- - j-- - k--;
    // cout << i <<" " << j << " " << k << " " << m <<endl;

    int i = 10, j = 20, k ;

    k = i-- - i++ + --j - ++j + --i - j-- + ++i - j++;
    cout << i <<" "<< j << " " << k << endl;

    return 0;
}