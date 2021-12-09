#include<bits/stdc++.h>
using namespace std;

int binary_To_decimal(int n){
    int ans = 0;
    int x = 1;

    while (n > 0){
        int ldigit = n % 10;
        ans += ldigit * x;
        x *= 2;                 // base is '2';
        n = n / 10;
    }
    return ans;
}

int octal_To_decimal(int n){
    int ans = 0;
    int x = 1;

    while(n > 0){
        int ldigit = n % 10;
        ans += x * ldigit;
        x *= 8;             // base is '8';
        n = n / 10;
    }
    return ans;
}

int hexa_decimal_To_decimal(string n){
    int sum = 0;
    int x = 1;
    int s = n.size();

    for (int i = s-1; i >= 0; i--){
        if (n[i] >= '0' && n[i] <= '9'){
            sum += x* (n[i] - '0');
        }
        else if (n[i] >= 'A' && n[i] <= 'F'){
            sum += x*(n[i] - 'A' + 10);
        }
        x *= 16;
    }
    return sum;

}

int decimal_To_binary(int n){
    int x = 1;
    int ans = 0;

    while (x <= n){
        x *= 2;
    }
    x /= 2;

    while (x > 0){
        int lastdigit = n / x;
        n -= lastdigit * x;
        x /= 2;
        ans = ans * 10  + lastdigit;
    }
    return ans;

}

int decimal_To_octal(int n){
    int x = 1;
    int ans = 0;

    while (x <= n){
        x *= 8;
    }
    x /= 8;

    while (x > 0){
        int lastdigit = n / x;
        n -= lastdigit * x;
        x /= 8;
        ans = ans * 10 + lastdigit;
    }
    return ans;
}

string decimal_To_hexadecimal(int n){
    int x = 1;
    string ans = "";

    while (x <= n)
        x *= 16;
    x /= 16;

    while (x > 0){
        int lastdigit = n / x;
        n -= lastdigit * x;
        x /= 16;
        
        if (lastdigit <= 9){
            ans = ans + to_string(lastdigit);
        }
        else {
            char c = 'A' + lastdigit - 10;
            ans.push_back(c);
        }
    }
    return ans;
}


int32_t main(){
    // int n;
    // cout << "Binary_no : ";
    // cin >> n;

    // cout <<"Decimal_no : "<< binary_To_decimal(n) << endl;
    
    // int n;
    // cout << "Octal_no : ";
    // cin >> n;

    // cout << "Decimal_no : " << octal_To_decimal(n) << endl;

    // string n;
    // cout << "Hexa_decimal_no : ";
    // cin >> n;

    // cout << "decimal_no : " << hexa_decimal_To_decimal(n) << endl;

    // int n;
    // cout << "decimal_no : ";
    // cin >> n;

    // cout << "binary_no : " << decimal_To_binary(n) << endl;

    // int n;
    // cout << "decimal_no : ";
    // cin >> n;

    // cout << "octal_no : " << decimal_To_octal(n) << endl;

    int n;
    cout << "decimal_no : ";
    cin >> n;

    cout << "hexa_decimal_no : " << decimal_To_hexadecimal(n) << endl;
    return 0;
}