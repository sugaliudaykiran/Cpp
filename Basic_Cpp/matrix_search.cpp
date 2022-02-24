/*
** using linear search we get O(n*m);
** using below code we can do better.. 
*/

#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n, m, k;
    cin >>n >>m >>k;
    int ar[n][m];

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }
    
    int row = 0, col = m-1;
    bool found = false;

    while (row < n && col >= 0){
        if (ar[row][col] == k){
            cout << row << " " << col << endl;
            found = true;
        }
        if (ar[row][col] > k){
            col--;
        }
        else{
            row++;
        }
    }
    if (found){
        cout << "Key is found..!" << endl;
    }
    else{
        cout << "Key is not found..!" << endl;
    }
    return 0;
}

/*

** start from top right element (or) from left bottom;
** you are at (r,c)
    if (matrix[r][c] == key){
        return true;
    }
    if (matrix[r][c] > key){
        c--;
    }
    else{
        r++;
    }

*/