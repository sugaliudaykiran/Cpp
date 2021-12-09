#include<bits/stdc++.h>
using namespace std;

bool palindrome_orNot(int num){
    int reverse = 0, temp = num;
    while (temp){
        int last_digit = temp % 10;
        reverse = last_digit + (reverse * 10);
        temp /= 10;
    }
    return (num == reverse);
}


int32_t main(){
    int Num;
    cin >> Num;
    cout << palindrome_orNot(Num) << endl;
    return 0;
}

// Time Complexity -> 0(input_digit) => tetha..
