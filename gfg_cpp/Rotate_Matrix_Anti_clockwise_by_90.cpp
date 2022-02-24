

#include<bits/stdc++.h>
using namespace std;

const int n = 3;
//             Navie Solution :=                 TC --> 0(N_square)..   AS --> 0(N_square)..

void rotate(int ar[n][n]){     // Last Column becomes first row.. secound last column becomes secound row..
    int t[n][n];
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            t[n-j-1][i] = ar[i][j]; // Here we last column move to first row..
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            ar[i][j] = t[i][j];
        }
    }
}

//                 In-place Apporach [Efficient Solution] :=  
                //                                              TC --> 0(N_square)..   AS --> 0(1)..
//          **   First we need to do Transpose of Matrix.. and reverse the Indiviual columns..  **

void eff(int ar[n][n]){

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){          // Here we used the Transpose of the Matrix..
            swap(ar[i][j], ar[j][i]);
        }
    }

    for (int i=0; i<n; i++){
        int low = 0, high = n-1;
        while (low < high){                         // After the Transpose ..
            swap(ar[low][i], ar[high][i]);   //  we swapping the particular column element on bases of row values..
            low++;                                     //  first with last and secound with but one..
            high--;
        }
    }
}



int32_t main(){
    int m[n][n];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> m[i][j];
        }
    }
    // rotate(m);
    eff(m);

    cout << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << m[i][j] << " ";
        }cout << endl;
    }

    return 0;
}



