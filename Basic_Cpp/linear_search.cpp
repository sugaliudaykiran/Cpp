#include<bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[], int n, int k){          // Time Complexity => O(n)
    for (int i = 0; i < n; i++){
        if (arr[i] == k){
            return i;
        }
    }
    return -1;
}


int32_t main(){
    int n;
    cout << "n : ";
    cin >> n;

    int arr[n];
    cout << "array : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int key;
    cout << "key_Tosearch : ";
    cin >> key; 

    cout << "index at : " << LinearSearch(arr, n, key) << endl;
    return 0;
}