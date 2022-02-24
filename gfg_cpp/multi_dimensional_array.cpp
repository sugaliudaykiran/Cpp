/*
    Multidimensional arrays in C++ :=   
        different methods to create multidimensional arrays in C++

    Important Points :-     {It is also stores elements at Continuous memeory location..}
    1) Elements are Stored in row - major Order..
        | 10 | 20 | 30 | 40 | 50 | 60 |
        ^    ^    ^    ^    ^    ^
memory 2000 2004 2008 2012 2016 2020 

    2) Internal Curly Brackets are Optional..
        int ar[2][2] = {1, 2, 3, 4}

    3) Only the First Dimension can be Omitted when we Initialize..
        int ar[][2] = {1, 2, 3, 4};
        int ar[][2][2] = {{{1, 2}, {3, 4}},
                            {{5, 6}, {7, 8}}}.. // Two outermost Dimensions and Two inner Dimensions and Two Innermost Dimensions..

    
Example 6(Vector of Vectors)

Example 5(Array of Vectors)

Example 4(Array of Pointer)





*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int32_t main(){
                                //  Example 1 (Fixed Sized Arrays)   :=
    int ar[3][2] = {{1, 2},
                    {3, 4},
                    {5, 6}};

    for (int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            cout << ar[i][j] << " ";
        }
    }cout << endl;

    int n, m;
    cin >> n >> m;      // Example 2 (Variable Sized Arrays)   :=

    int A[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            A[i][j] = i + j;
            cout << A[i][j] << " ";
        }
    }cout << endl;
    
    //     Example 3 { "Double Pointer" } :=    Here we can have Indiviual rows of different size.. which juzed array..

    m = 3, n = 2;

    int **Ar ;          // Creating Double Pointer..  which Takes More "Cache Space"..{Not Cache Friendly..} 
    Ar = new int *[m];          // Array of Pointer which is an Dynamic allocation..type like..{HEAP}..

    for (int j=0; j<m; j++){        // Matrix of (M * N).. 
        Ar[j] = new int [n];        // Here "n" we can declare any Number by this it may.. take extra space to excute..
    }                               // And it is an Dynamic allocation..type {HEAP}..

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            Ar[i][j] = 0;          // Assing the value and print them..
            cout << Ar[i][j] << " ";
        }
    }

//              Example  4 ->  "Array of Pointers" :-
    m = 3, n = 2;
    int *arr[m];   // Here In this type declartion is static format... which is Stack..

    for (int i=0; i<m; i++){    // Create a 2D array of Size " M*N ";
        arr[i] = new int [n];   // In this Case Row are allocated Static and Column are allocated in Dynamic Way..
    }
    cout << endl;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){        // Assing the value and print them..
            arr[i][j] = 1;
            cout << arr[i][j] << " ";
        }
    }

//        Example 5 --> "Array of Vectors"  :-
    m = 3, n = 2;
    vector <int> aR[m];         // Here we are Using Vectors for creating dynamic array.. with size m..
    for (int i=0; i<m; i++){        
        for (int j=0; j<n; j++){    // Vector has Advantage as it will take dynamic length of column..
            aR[i].push_back(0);    // Here Push.back(element) will help to push elements in particular row..
        }
    }
    cout << endl;                   // About Vector -> Not as Cache Friendly as simple 2D - arrays..
    for (int i=0; i<m; i++){        // Individual rows are of Dynamic Sizes.. we can increase Size and decrease the Size..
        for (int j=0; j<n; j++){        // Easy to pass to a function..
            cout << aR[i][j] << " ";
        }
    }

    //      Example 6 --> "Vector of Vectors"   :-
    m = 3, n = 2;
    vector <vector <int>> v_ar;         // Vector of vector for Dynamic allocation..
    for (int i=0; i<m; i++){        // Here in this Number of rows can also be Dynamic.. 
        vector <int> v;
        for (int j=0; j<n; j++){
            v.push_back(1);         // Here we particular adding row wise elements..
        }
        v_ar.push_back(v);          // push entire row to vector..
    }
    cout << endl;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << v_ar[i][j] << " ";
        }
    }                               


    return 0;
}