// Intersection of two sorted arrays :-
// two sorted arrays and picking out the intersection elements(Common ones) from the two arrays.

#include<bits/stdc++.h>
using namespace std;

// Navie-Solution :-               TC -->  O(N*M)..
void intersection(int a[], int b[], int n, int m){
    for (int i=0; i<n; i++){
        if (i > 0 && a[i] == a[i-1]){
            continue;
        }
        for (int j=0; j<m; j++){
            if (a[i] == b[j]){
                cout << a[i] << " ";
                break;
            }
        }
    }
}

// Efficient - Solution :-        TC --> 0(N+M)..
void inter(int a[], int b[], int n, int m){
    int i=0, j=0;
    while (i<n && j<m){
        if (i > 0 && a[i] == a[i-1]){
            i++;
            continue;
        }
        if (a[i] > b[j]){   // b th element is smaller..
            j++;
        }
        else if (a[i] < b[j]){  // a th element is smaller..
            i++;
        }
        else {          // a[i] == b[j]  there are equal..
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

int32_t main(){         // Two Sorted Arrays..

    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int j=0; j<m; j++){
        cin >> b[j];
    }

    // intersection(a, b, n, m);
    inter(a, b, n, m);
    return 0;
}