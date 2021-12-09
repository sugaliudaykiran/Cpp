#include<bits/stdc++.h>
using namespace std;

int Selection_sort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int32_t main(){
    int n;
    cout << "n : ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Selection_sort(arr, n);
    return 0;
}

/* selection_sort 

find the minimum element  in unsorted array and swap it with element at beginning of the unsorted array...*/ 