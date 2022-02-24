#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n, m;
    cin >> n >> m;
    int ar[n][m];

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }
    cout << "Matrix : " << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
    int k;
    cin >> k;
    bool flag = false;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (ar[i][j] == k){
                cout << i <<" "<< j << endl;
                flag = true;
            }
        }
    }
    if (flag){
        cout << "Key is found..!" << endl;
    }else{
        cout << "Key is not found..!"<< endl;
    }
    return 0;
}