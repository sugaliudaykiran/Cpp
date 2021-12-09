#include<bits/stdc++.h>
using namespace std;

// Naive-Solution..
int lcm_of_2num(int n1, int n2){
    int res = max(n1, n2);
    while(true){
        if (res % n1 == 0 && res % n2 == 0){
            return res;
        }
        res++;
    }
    return res;
}

int32_t main(){
    int n1, n2;
    cin >> n2 >> n2;
    cout << lcm_of_2num(n1, n2) << endl;
    return 0;
}