// Search in Row-wise and Column-wise on sorted matrix :=

#include<bits/stdc++.h>
using namespace std;

const int n = 4;

//                          Navie - Solution :=     TC --> O(R*C).. row *column
void M_s(int ar[n][n], int k){

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (ar[i][j] == k){
                cout << "Found at :- " << "["<< i <<","<<  j << "]";
                return;
            }
        }
    }
    cout << "Not Found..!";
}

//              Efficient Solution :-           TC ---> O(R+C).. it is Linear Solution..
/*              In this case we can define 2 ways :-
    way - I)
          1) We Start from the Right Upper most element..       // Begin from the Top right corner..
          2) If K is same the Element then print and return..
          3) Else if K is greater than Current element then we move down-wards..
          4) Else if K is Smaller than Current element then we Move left-wards to that element..
          
*/

void M_s_Top_right(int ar[n][n], int k){        // TC --> O(R+C) // row +column
    int i = 0, j = n-1;
    
    while (i<n && j>=0){
        if (ar[i][j] == k){
            cout << "Found at :- " << "["<< i <<","<<  j << "]";
            return;
        }
        else if (ar[i][j] > k){     // Element is greater than k..
            j--;
        }
        else {                           //  else if (ar[i][j] < k)..
            i++;                         // element is smaller than k..
        }
    }
    cout << "Not Found..!";
}
/*
    Way = 2) 
    1) Here we take the bottom left element as the first element to check 
    2) If it is equal then we print and return..
    3) If the current is smaller than k then we go right-wards..
    4) If the current is greater than k thrn we go up-wards..

    Another Way to Improve the Efficient solution :-
    1) First check the top left element with k then if K is greater than or equal then ok..
    2) else return directly not found..
    3) Secound Check the bottom right element with k then if k is smaller than or equal then ok..
    4) else return no found..  
*/
void M_ss(int ar[n][n], int k){
    int i=n-1, j=0;
    
    if (ar[0][0] <= k && ar[n-1][n-1] >= k){
        while(i >= 0 && j < n-1){
            if (ar[i][j] == k){
                cout << "Found at :- " << "["<< i <<","<<  j << "]";
                return;
            }

            else if (ar[i][j] > k){
                i--;
            }
            else {
                j++;
            }
        }
    }
    cout << "Not Found..!";
}

int32_t main(){
    int M[n][n];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> M[i][j];
        }
    }

    int key ;
    cin >> key;

    // M_s(M, key);
    // M_s_Top_right(M, key);
    M_ss(M, key);

    return 0;
}