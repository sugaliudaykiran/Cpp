#include<bits/stdc++.h>
#include<string>
using namespace std;
//       Using Recursion......    output are (2_power(N))..
void perm(string str, int i = 0){  // i -> Indexing..for the Order to follow..
    
    int n = str.length();
    
    if (i == n-1){          // Upto last index of string..
        cout << str << endl;
        return;
    }
    
    for (int j=i; j<n; j++){        // J follow the Index as 012..upto str_length..

        swap(str[i], str[j]);
        perm(str, i+1);             // Double - Swap because of return the original state of string further..permutation..
        swap(str[i], str[j]);
    }

}

int32_t main(){

    string str;
    cin >> str;

    perm(str);
    return 0;
}