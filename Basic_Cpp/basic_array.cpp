#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++){
        cin >> arr[i] ;
    }

    cout << "array : " ;
    for (int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}