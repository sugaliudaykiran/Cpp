#include "bits/stdc++.h"
#include "string"
#include "algorithm"
using namespace std;

int32_t main(){
    string s;
    s = "18579";

    sort(s.begin(), s.end(), greater<int>());  // here we can use int or char..
    cout << s << endl;
    return 0;
}