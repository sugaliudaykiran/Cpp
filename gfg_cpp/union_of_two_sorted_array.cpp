// Union of two sorted arrays := print the all the Elements of Both the arrays and without including the common elements..

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Naive - Solution :-              TC --> O((N+M) * Log(N+M))..    AS -> 0(N+M)..
void unions(int a[], int b[], int n, int m){
    int temp[n+m];

    for (int i=0; i<n; i++){
        temp[i] = a[i];
    }
    for (int j=0; j<m; j++){
        temp[n+j] = b[j];
    }
    sort(temp, temp+n+m);

    for (int k=0; k<(n+m); k++){
        if (k == 0 || temp[k] != temp[k-1]){
            cout << temp[k] << " ";
        }
    }
}

// Efficient-Solution :-        TC --> O(N+M)... AS --> O(1).. Using Merge Sort..
void un(int a[], int b[], int n, int m){
    int i=0, j=0;
    while(i<n && j<m){
        if (i>0 && a[i] == a[i-1]){
            i++;
            continue;
        }
        if (j>0 && b[j] == b[j-1]){
            j++;
            continue;
        }
        if (a[i] < b[j]){
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] > b[j]){
            cout << b[j] << " ";
            j++;
        }
        else{
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while (i<n){
        if (i > 0 && a[i] != a[i-1]){
            cout << a[i] << " ";
            i++;
        }
    }
    while (j<m){
        if (j > 0 && b[j] != b[j-1]){
            cout << b[j] << " ";
            j++;
        }
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
    //unions(a, b, n, m);
    un(a, b, n, m);
    return 0;
}