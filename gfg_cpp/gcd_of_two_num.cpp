#include<bits/stdc++.h>
using namespace std;

// Navie-Solution..  -> TC => min(a, b);
int gcd_of_2nums(int n1, int n2){
    int res = min(n1, n2);
    while (res > 0){
        if (n1 % res == 0 && n2 % res == 0){
            break;
        }
        res--;
    }
    return res;
}

// Using Euclidean Algorithm-> Basic Version..[Optimal to navie_sol..]
int Euclidean1(int n1, int n2){
    while (n1 != n2){
        if (n1 > n2){
            n1 = n1 - n2;
        }
        else{
            n2 = n2 - n1;
        }
    }
    return n1; // or n2 as there are same..
}

// Using Euclidean Algorithm -> Optimial Version..
int Euclidean2(int n1, int n2){    //  (Left, Right)
    if (n2 == 0){
        return n1;          // return the left value..
    }
    else{
        Euclidean2(n2, n1%n2);  //----> Here it always swap greater to left and smaller to right..
    }
}


int32_t main(){
    int n1, n2;
    cin >> n1 >> n2;
    // cout << gcd_of_2nums(n1, n2) << endl;
    // cout <<  Euclidean1(n1, n2) << endl;
    cout << Euclidean2(n1, n2) << endl;
    return 0;
}

// gcd -> greater common divisor...