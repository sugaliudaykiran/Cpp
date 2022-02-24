#include<bits/stdc++.h>
using namespace std;

const int n = 4;

                            //  top row, right column, bottom row, left column
void spiral(int ar[n][n]){          
    int top = 0, bottom = n-1, left = 0, right = n-1;
    while (top <= bottom && left <= right){
        for (int i=left; i<=right; i++){        
            cout << ar[top][i] << " ";
        }
        top++;
        
        for (int i=top; i<=bottom; i++){
            cout << ar[i][right] << " ";
        }
        right--;
        
        if (top <= bottom){                 // In case of single column..
        
        for (int i=right; i>=left; i--){
            cout << ar[bottom][i] << " ";
        }
        bottom--;
        }

        if (left <= right){                 // In case of Single row..
        
        for (int i=bottom; i>=top; i--){
            cout << ar[i][left] << " ";
        }
        left++;
        }

    }
}

int32_t main(){
    int M[n][n];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> M[i][j];
        }
    }
    spiral(M);

    return 0;
}