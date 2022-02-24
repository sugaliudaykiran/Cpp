#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "Enter the N value : ";
    cin >> N;

    for (int i = N; i >= 1; i--){
        for (int j = 1; j <= i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;


}