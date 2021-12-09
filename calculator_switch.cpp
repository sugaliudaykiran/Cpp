// simple calculator using switch :-

# include<bits/stdc++.h>
using namespace std;

int32_t main(){
    // we can int, float values also...
    int a,b;
    cout << "Enter the two Numbers : ";
    cin >> a>> b;
    char opr;
    cout << "Enter the operator : ";
    cin >> opr;

    switch(opr){
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '/':
            cout << a / b << endl;
            break;
        case '%':
            cout << a % b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        default :
            cout << "please checks the operators..." << endl;
            break;
    }
    return 0;
}