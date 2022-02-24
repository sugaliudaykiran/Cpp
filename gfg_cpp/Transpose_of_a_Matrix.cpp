// ar[i][j] = ar[j][i]..

// Method - 1) Navie Solution :=        Using Additional temp array..

#include<bits/stdc++.h>
using namespace std;

const int n = 4; // Transpose will work in case of row and column are same..

void trans(int ar[n][n]){
    int temp[n][n];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            temp[i][j] = ar[j][i]; 
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            ar[i][j] = temp[i][j];
        }
    }
}
/*

int32_t main(){
    
    int ar[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> ar[i][j];
        }
    }
    trans(ar);
    cout << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << ar[i][j] << " ";
        }cout << endl;

    }

    return 0;
}

*/

// Method - 2) In-Place And requires only One Traversal..

#include<bits/stdc++.h>
using namespace std;        // Diagonal element will remains same as after the Transpose..

void m_tr(int mt[n][n]){        // It takes constant space..
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){      // So we swap the upper elements with lower elements..
            swap(mt[i][j], mt[j][i]);
        }
    }
}


int32_t main(){
    int mat[n][n];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    m_tr(mat);
    
    cout << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }cout << endl;
    }
    return 0;
}