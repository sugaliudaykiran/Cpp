#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int ar1[n1][n2];
    int ar2[n2][n3];

    for (int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            cin >> ar1[i][j];
        }
    }

    for (int i=0; i<n2; i++){
        for (int j=0; j<n3; j++){
            cin >> ar2[i][j];
        }
    }
    // answer --> martix n1 * n2;
    int M[n1][n3];
    for (int i=0; i<n1; i++){
        for (int j=0; j<n3; j++){
            M[i][j] = 0;
        }
    }

    for (int i=0; i<n1; i++){
        for (int j=0; j<n3; j++){
            for (int k=0; k<n2; k++){
                M[i][j] += ar1[i][k] * ar2[k][j];
            }
        }
    }

    for (int i=0; i<n1; i++){
        for (int j=0; j<n3; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
** In future Matrix_Exponentiation is implemented...
 */