// ==, !=, >, <, >=, <=;

#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "Enter N value : ";
    cin >> N;

    if (N > 10){
        cout <<"Yes N is greater than 10 " << endl;
    }
    else if (N < 10){
        cout << "Yes N is lesser than 10 " << endl;
    }
    else{
        cout << "Yes N is equal to 10 " << endl;
    }
    return 0;
}