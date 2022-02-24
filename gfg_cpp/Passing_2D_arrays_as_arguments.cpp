#include<bits/stdc++.h>
#include<vector>
using namespace std;

void prints(int two_d[3][2]){
    for (int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            cout << two_d[i][j] << " ";
        }
    }
    cout << endl;
}

// int32_t main(){
//     int two_d[3][2] = { {10, 20},
//                         {30, 40},
//                         {50, 60} };
//     prints(two_d);
//     return 0;
// }

/*
            Issues faced when we pass multidimensional arrays as arguments in this case it only accept the 2_d[3][2]..
            
            Like we pass random size or dimensions in that case we need to perform some sort of 
              various argment or different type of declaration
            To solve the Issue :- Follow the Below examples..

*/

//              Here in these case we can proved the row as argument in this example..
void prints(int two_d[][2], int row){
    for (int i=0; i<row; i++){
        for (int j=0; j<2; j++){
            cout << two_d[i][j] << " ";
        }
    }
    cout << endl;
}

// int32_t main(){
//     int two_d[3][2] = { {10, 20},
//                         {30, 40},
//                         {50, 60} };
//     prints(two_d, 3);
//     return 0;
// }

//                  Here default in Cpp there is no specific type of argument declrations..

const int row = 3;
const int col = 2;

void pts(int A[row][col]){
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cout << A[i][j] << " ";
        }
    }
}

// int32_t main(){
//     int two_d[row][col] = { {1, 2},
//                             {3, 4},
//                             {5, 6} };
//     pts(two_d);
//     return 0;
// }

//                                     Martix of any dimensions :-

//                                       Using Double Pointer :-

void print_s(int **ar_p, int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << ar_p[i][j] << " ";
        }
    }
}

/*
int32_t main(){

    int **ar_p;             // Here First we created the Double Pointer..
    int m = 3, n = 2;       
    ar_p = new int *[m];        // To the Particular Pointer we declare the Row Pointer..
    for (int i=0; i<m; i++){
        ar_p[i] = new int [n];      // For the Particular Row we declare the column values..
        for (int j=0; j<n; j++){
            ar_p[i][j] = i;
            // cout << ar_p[i][j] << " ";
        }
    }
    print_s(ar_p, m, n);
    return 0;
}

*/ 

//                        Array of Pointer :-

void a_p(int *a[], int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
    }
}

/*
int32_t main(){
    int m = 3, n = 2;
    int *a[m];          // Here we Created the Pointer array..

    for (int i=0; i<m; i++){
        a[i] = new int [n];         // Again for each row we assing the column size and declare the value..

        for (int j=0; j<n; j++){
            a[i][j] = i;
        }
    }
    a_p(a, m, n);

    return 0;
}
*/

//                              Uisng Array of Vector :-

void v_s(vector <int> v[], int m){          // Here we Providing the Vector and Row item..
    for (int i=0; i<m; i++){
        for (int j=0; j<v[i].size(); j++){      // For particular row has its column lenght.. 
            cout << v[i][j] << " ";             // After Declaring the Each row we assing the particular row length ..
        }
    }
}

/*

int32_t main(){
    int m=3, n=2;
    vector <int> ars[m];                // Here we declare the Vector of array with size..as row,,
    for (int i=0; i<m; i++){            
        for (int j=0; j<n; j++){
            ars[i].push_back(i);        // for particular row we push the elements to it..
        }
    } 
    v_s(ars, m);
    return 0;
}

*/

//                                       Vector of Vectors :-

void pr_S(vector <vector <int>> a_rs){
    for (int i=0; i < a_rs.size(); i++){            // Here we use Vector Size..
        for (int j=0; j < a_rs[i].size(); j++){     // Here we use Vector of Particular Row Size.. 
            cout << a_rs[i][j] << " ";
        }
    }
}

int32_t main(){
    int m = 3, n = 2;
    vector <vector <int>> a_rs;         
    for (int i=0; i<m; i++){
        vector <int> v_s;
        for (int j=0; j<n; j++){
            v_s.push_back(i);
        }
        a_rs.push_back(v_s);
    }
    pr_s(a_rs);             // In vector the element many not store in Contiunes memory locations,,

    return 0;
}

