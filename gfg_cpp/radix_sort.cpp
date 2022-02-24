/*
    Radix Sort :=
    Explanation and implementation fo Radix Sort
    1) first find the maximum element of the array..
    2) and count digits present in the maximum element.. and convert all remaining element to maximum element format..
    3) Using Counting sort as Subrotie on bases of the ones place, tens place, Hundrend place.. and so on..
    4) Radix sort is Stable and Better than Counting sort in quadratic form..
*/

#include<bits/stdc++.h>
using namespace std;

// Couting Sort as Subrotie :-
void countSort(int ar[], int n, int exp){
    int output[n];

    // for (int i=0; i<10; i++){
    //     counT[i] = 0;
    // }        // Or..

    int counT[10] = { 0 };
    for (int j=0; j<n; j++){
        counT[(ar[j] / exp) % 10]++;        // Increase the count on the digit place appeared..
    }
    for (int k=1; k<10; k++){
        counT[k] = counT[k] + counT[k-1];      // Accumlative count of the count appeared..
    }

    for (int i = n-1; i >= 0; i--){
        output[counT[(ar[i] / exp) % 10] -1] = ar[i];   // sorting based on the occuring the order based on the positions..
        counT[(ar[i] / exp) % 10]--;
    }
    for (int j=0; j<n; j++){    // copying sorted element to original array..
        ar[j] = output[j];
    }
}

// Radix-Sort :-            TC --> 0(d * (N + b))..         AS --> 0(N+b)..
void r_s(int ar[], int n){
    int mxs = ar[0];
    for (int i=1; i<n; i++){    // FInding the maximum element Over the array
        if (ar[i] > mxs){
            mxs = ar[i];
        }
    }
    for (int exp = 1; mxs/exp > 0; exp *= 10){      // Based on the max element performing Counting Sort...
        countSort(ar, n, exp);
    }
}

int32_t main(){

    int n;
    cin >> n;

    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }

    r_s(ar, n);
    for(int s : ar){
        cout << s << " ";
    }
    return 0;
}