//  Matrix in Snake Pattern
// To print a matrix in snake pattern :=
//     (first row should be printed from left to right, second row from right to left, and so on).

#include<bits/stdc++.h>
using namespace std;
const int m = 4;
const int n = 4;

void snake(int Mt[m][n]){           // TC --> R * C..
    for (int i=0; i<m; i++){
        if (i % 2 == 0){
            for (int j=0; j<n; j++){
                cout << Mt[i][j] << " ";
            }
        }
        else {
            for (int j=n-1; j>=0; j--){
                cout << Mt[i][j] << " ";
            }
        }cout << endl;
    }
}

int32_t main(){
    // int m, n;
    // cin >> m >> n;

    int Mt[m][n];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> Mt[i][j];
        }
    }
    snake(Mt);
    return 0;
}