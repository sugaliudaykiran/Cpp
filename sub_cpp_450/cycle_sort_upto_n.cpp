#include<bits/stdc++.h>
using namespace std;
// Using Cycle_sort..0(n)
void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray (int ar[], int n){
    for (int i=0; i<n;){
        if (ar[i] == i+1){
            i++;
        }
        else{
            swap(&ar[i], &ar[ar[i]-1]);
        }
    }
}
int32_t main(){
    int n, k_th;
    cin >> n; 
    int ar[n];

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    sortArray(ar, n);
    for (int i=0; i<n; i++){
        cout << ar[i] << " ";
    }
    return 0;
}