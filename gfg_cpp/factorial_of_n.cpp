#include<bits/stdc++.h>
using namespace std;
// recursive - method.. => T(n) = T(n-1) + 0(1) --> 0(n) as TC and AS;  
int fact(int n){                
    if (n == 1 || n == 0){
        return n;
    }
    else{
        return n * fact(n-1);
    }
}

// iterative - method.. => TC -> 0(n) and AS -> O(1);
int facts(int n){
    int res = 1;

    for (int i=2; i<= n; i++){
        res = res * i;
    }
    return res;
}

int32_t main(){
    int N;
    cin >> N;
    cout << fact(N) << endl;
    cout << facts(N) << endl;
    return 0;
}