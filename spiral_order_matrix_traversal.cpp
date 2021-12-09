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

    // spiral order print 
    int row_start = 0, row_end = n-1, col_start = 0, col_end = n-1;

    while (row_start <= row_end && col_start <= col_end){
        // for row_start 
        for (int col = col_start; col <= col_end; col++){
            cout << ar[row_start][col] << " " << endl;
        }
        row_start++;

        // for col_end
        for (int row = row_start; row <= row_end; row++){
            cout << ar[row][col_end] << " " << endl;
        }
        col_end--;

        // for row_end
        for (int col = col_end; col >= col_start; col--){
            cout << ar[row_end][col] << " " << endl;
        }
        row_end--;

        // for col_start
        for (int row = row_end; row >= row_start; row--){
            cout << ar[row][col_start] << " " << endl;
        }
        col_start++;
    }

    return 0;
}