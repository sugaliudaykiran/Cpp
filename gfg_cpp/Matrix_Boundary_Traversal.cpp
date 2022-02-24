/*
                                Matrix Boundary Traversal :=
Here discusses a linear time solution for boundary traversal problem
    (first row left to right, last column top to bottom, last row right to left and first column bottom to top)
*/

#include<bits/stdc++.h>
using namespace std;

const int r = 4;
const int c = 4;        // TC -> 0( R+C )..

void Bound(int Mtr[r][c]){
    if (r == 1){                    // For Corner cases.. as if it contain only single Row..
        for (int i=0; i<c; i++){
            cout << Mtr[0][i] << " ";
        }
    }
    else if (c == 1){              // For Corner Case.. as if it contain only single Column..
        for (int j=0; j<r; j++){
            cout << Mtr[j][0] << " ";
        }
    }
    else {
        for (int i=0; i<c; i++){
            cout << Mtr[0][i] << " ";
        }
        for (int i=1; i<r; i++){
            cout << Mtr[i][c-1] << " ";
        }
        for (int i=c-2; i>=0; i--){
            cout << Mtr[r-1][i] << " ";
        }
        for (int i=r-2; i>=1; i--){
            cout << Mtr[i][0] << " ";
        }
    } // (first row left to right, last column top to bottom, 
     //    last row right to left and first column bottom to top)
}

int32_t main(){
    int Mtr[r][c];
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> Mtr[i][j];
        }
    }
    Bound(Mtr);
    return 0;
}