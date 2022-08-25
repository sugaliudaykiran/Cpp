#include<bits/stdc++.h>
#include<algorithm> 
using namespace std;    //  TC -> 0(n).. Linear time..

int myFun(int x, int y)
{
    return x * y;
}

int32_t main() {

    vector <int> v = {5, 1, 7, 10, 20};
    int init_res = 0;
    cout << accumulate(v.begin(), v.end(), init_res) << "\n";
    // cout << init_res << "\n";
    
    // init_res  = accumulate(v.begin(), v.end(), init_res) ;
    // cout << init_res << "\n";

    
    int ar[] = {1, 2, 3, 5, 1};
    int res = 10;
    cout << accumulate(ar, ar+5, res) << "\n";


    vector <int> v2 = {10, 5, 20, 10, 5};
    res = 100;
    cout << accumulate(v2.begin(), v2.end(), res, minus<int>()) << "\n";
    

    vector <int> v3 = {1, 2, 3, 5, 4};
    res = 1;
    cout << accumulate(v3.begin(), v3.end(), res, myFun) << "\n"; 
    return 0;
}