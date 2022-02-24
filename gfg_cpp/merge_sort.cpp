/*  Merge_sort :=
    1) Divide and Conquer Algorithm (Divide, Conquer, and Merge)..
    2) Stable Algorithm..=> TC -> 0(N_logN) and AS -> O(N)..
    3) Well suited for Linked lists and works in AS -> O(1)..
    4) Used in External sorting..
    5) In general for Arrays ,Quick sort outperforms it..(Quick is better in this place..)
    6) Merge sort in various place of hybrid sorts..
*/

// ques :- Given Two sorted arrays and create the one finally sorted with them..
#include<bits/stdc++.h>
using namespace std;

// Navie_Solution :-             TC --> O((N+M)Log(N+M)).. and AS --> 0(M+N)..
void merge(int a[], int n, int b[], int m){
    int c[n+m];             // Size of N+M...array..

    for (int i=0; i<n; i++){    // 0(N)
        c[i] = a[i];
    }
    for (int j=0; j<m; j++){    // 0(M)
        c[n+j] = b[j];
    }

    sort(c, c+n+m); // Takes TC --> O((N+M)Log(N+M))..
    for (int x: c){             
        cout << x << " ";           // 0(N+M)..
    }

    // for(int k=0; k<(n+m); k++){
    //     cout << ar[k] << " ";
    // }
}

// Efficient Solution :-        TC -> 0(M+N)..   and AS -> O(1)..
void mg(int a[], int n, int b[], int m){
    int i=0, j=0;

    while(i < n && j < m){      // Here we traverse through the both array..Linear..
        if (a[i] <= b[j]){          // If the A[ele] is smaller then we print and then increment the index..
            cout << a[i] << " ";
            i++;
        }
        else {
            cout << b[j] << " ";        // else the B[ele] is smaller then we print and then increment the index..
            j++; 
        }
    }

    while (i < n){              // Checking the Remaining element if any elements is left in it..
        cout << a[i] << " ";
        i++;
    }
    while (j < m){                  // Checking the Remaining element if any elements is left in it..
        cout << b[j] << " ";
        j++;
    }
}

int32_t main(){
    int n, m;
    cin >> n >> m;

    int a[n], b[m];

    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int j=0; j<m; j++){
        cin >> b[j];
    }

    // merge(a, n, b, m);
    mg(a, n, b, m);
    return 0;
}