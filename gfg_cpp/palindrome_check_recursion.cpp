#include<bits/stdc++.h>
#include<string.h>
using namespace std;
                // TC and AS --> O(N).. Recursion way is --> T(N) = T(N-2) + 0(1)..
bool pali(string &str, int start, int end){      // &str --> Because of it should not copy the orginial one..
    if (start >= end){
        return true;
    }
    return (str[start] == str[end]) && pali(str, start+1, end-1);   // If first condition is true then it follows the next..
}
int32_t main(){
    string str;
    cin >> str;

    int start = 0, end = (str.size())-1;

    cout << pali(str, start, end) << endl;
    return 0;
}