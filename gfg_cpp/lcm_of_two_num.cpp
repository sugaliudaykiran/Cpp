#include<bits/stdc++.h>
using namespace std;

// Naive-Solution..     // TC --> O(a * b -max(a, b));
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

// Logithmatic way(Efficient Way).. // O(log(min(a, b)));
                    // || (a * b) = gcd(a, b) * lcm(a, b) ||
int gcd(int n1, int n2){
    if (n2 == 0){
        return n1;
    }
    else{
        return gcd(n2, n1%n2);
    }
}

int lcm_of_2nums(int n1, int n2){
    
    return ((n1 * n2)/gcd(n1, n2));
}


int32_t main(){
    int n1, n2;
    cin >> n1 >> n2;
    // cout << lcm_of_2num(n1, n2) << endl;
    cout << lcm_of_2nums(n1, n2) << endl;
    return 0;
}