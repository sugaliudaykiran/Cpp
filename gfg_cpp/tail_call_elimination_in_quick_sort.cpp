/*
    Tail call elimination QuickSort Algorithm :-
        We rewrite the QuickSort Algo and by this {Tail call Conditions}..
        We optimalize the additional space{AS}.. requirement 
        After Partitions.. First Check How elements are there..In both of side of Partitions 
        and Which is More..then Apply Tail_call_Elimation on it..
    
    Ex :- Applying on Hoare Partitions..
*/

#include<bits/stdc++.h>
using namespace std;

// Hoare Partitions :-
int Hoare_p(int ar[], int low, int high){
    int i = low-1, j = high+1;
    int pivot = ar[low];
    while(true){    // Always True condition.. assuming..
        do{
            i++;
        }while(ar[i] < pivot);
        do{
            j--;
        }while(ar[j] > pivot);
        if (i >= j){
            return j;
        }
        swap(ar[i], ar[j]);
    }
}

// Applying Tail call Elimination..
void Qsort(int ar[], int low, int high){
    Begin :
    if (low < high){
        int p = Hoare_p(ar, low, high);
        Qsort(ar, low, p);
        low = p+1;              // Assumed that Right side elements are more.. then Applying Tail on it..
        goto Begin;
    }
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    int low = 0, high = n-1;

    Qsort(ar, low, high);
    for (int s: ar){
        cout << s << " ";
    }
    return 0;
}
