#include<bits/stdc++.h>
using namespace std;

int BubbleSort(int ar[], int n){
    int counter = 1;

    while (counter < n){
        for (int i = 0; i < n-counter; i++){
            if (ar[i] > ar[i+1]){
                int temp = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = temp;
            }
        }counter += 1;
    }
    for (int i = 0; i < n; i++){
        cout << ar[i] << " ";
    }
    cout << endl; 
}

int32_t main(){
    int n;
    cout << "n : ";
    cin >> n;

    int ar[n];
    
    for (int i = 0; i < n; i++){
        cin >> ar[i];
    }

    BubbleSort(ar, n);
    return 0;
}


/* Bubble sort --> bubble because it bubble the high value in the array in where iterations... 
Reapetedly swap two adjacent elements if they are in wrong order 

wrong order --> ar[i] > ar[i+1] that why we need swap...

in this sorting :
            (n-1) iterations requires before we get our sorted Array...
            that is 1 st iterations required upto n-1 value, 
                    2 nd iterations required upto n-2 value,
                    .. and soon...
                    i th iterations required upto n-i  value...*/