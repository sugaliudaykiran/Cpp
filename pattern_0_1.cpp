#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= i; j++){
            // if ((i+j) % 2 == 0){
            //     cout << "1" << " ";
            // }
            // else{
            //     cout << "0" << " ";
            // }
            int x = (i+j);
            string result = (x % 2 == 0)? "1":"0";
            cout << result << " ";
        }
        cout << endl;
    }
    return 0;
}