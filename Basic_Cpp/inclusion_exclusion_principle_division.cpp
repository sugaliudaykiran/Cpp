#include<bits/stdc++.h>
using namespace std;

int divisible(int n, int x, int y){
    int a = n/x;
    int b = n/y;
    int c = n/(x*y);

    return (a+b-c);
}
// 40, 5, 7..-> 40/5 = 8, 40/7 = 5, 40/(5*7) = 1..;
            //  => 8 + 5 - 1 = 12..;

int32_t main(){
    int n, a, b;    
    cin >> n >> a >> b;
    cout << divisible(n, a, b) << endl;
    return 0;
}