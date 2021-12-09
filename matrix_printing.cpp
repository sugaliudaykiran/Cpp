#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int R,C;
    cout << "Enter the Rows and Columns : ";
    cin >> R >> C;

    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++){
            if (i == 1 || i == R){
                cout << "*";
            }
            else if (j == 1 || j == C){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout<<endl;
    }
    return 0;
}