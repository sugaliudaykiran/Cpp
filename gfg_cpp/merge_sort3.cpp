/*
    Merge Sort Algorithm :=  

    void mergeSort(int ar[], int left, int right){
        if (right > left){      // Aleast Contain two elements..
            int mid = (left + (right - left)) / 2;
            
            mergeSort(ar, left, mid);       // Check the left half and sort it..
            mergeSort(ar, mid+1, right);    // Check the right half and sort it..
            Merge(ar, left, mid, right);    // Merge the Entire array and sorted..
        }
    }

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void Merge(int ar[], int left, int mid, int right){
    int n1 = (mid -left+1), n2 = right - mid;
    int L[n1], R[n2];
    
    for (int i=0; i<n1; i++) {
        L[i] = ar[left+i];
    }
    for (int j=0; j<n2; j++){
        R[j] = ar[mid+j+1];
    }
    
    int i=0, j=0, k=left;
    while (i<n1 && j<n2){
        if (L[i] <= R[j]){
            ar[k] = L[i];
            i++;
            k++;
        }
        else{
            ar[k++] = R[j++];
        }
    }
    while (i < n1){
        ar[k] = L[i];
        i++;
        k++; 
    }
    while (j < n2){
        ar[k++] = R[j++];
    }
}
//  TC --> X * 0(N) --> where X is Levels of Division.. that is Ceil(Log_N_Base2) + 1.. => TC -> 0(LogN) * 0(N)..
void mergeSort(int ar[], int left, int right){        // TC -> 0(N_LogN).. and AS -> 0(N) were it allocation and de-allocation..
    if (right > left){      // Aleast Contain two elements..
        int mid = left + (right - left) / 2;
            
        mergeSort(ar, left, mid);       // Check the left half and sort it..
        mergeSort(ar, mid+1, right);    // Check the right half and sort it..
        Merge(ar, left, mid, right);    // Merge the Entire array and sorted..      TC -> 0(N)..
    }
}

int32_t main(){

    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    int left = 0, right = 4;

    mergeSort(ar, left, right);

    for (int v: ar){
        cout << v << " ";
    }

    return 0;
}

