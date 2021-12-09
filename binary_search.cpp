#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int key){            // Time Complexity => O(log n)base 2...
    int start = 0;                                      // Array should be sorted..
    int end = n;

    while(start <= end){
        int mid = (start + end) / 2;
        if (arr[mid] == key){
            return mid;
        }
        else if (arr[mid] > key){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}

int32_t main(){
    int n;
    cout << "n : ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Key : ";
    cin >> key;

    cout << "index_at : " << BinarySearch(arr, n, key) << endl;
    return 0;
}