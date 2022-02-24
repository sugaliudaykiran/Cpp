/*
    Quick-Sort Introduction :- 
        1) Divide and Conquer Algorithm..
        2) Wrost case Time  -> O(N_square)..
        3) Despite O(N_square..) Worst case, It is Considered faster, Because of the Following Reasons :-
                    A) IN - Place,
                    B) Cache Friendly..
                    C) Average Case is O(N_LogN)..
                    D) Tail Recurisve..
        4) Partition is Key Function (Naive {Stable}, Lomuto, Hoare..{Un - Stable})..

    In Best case :-   TC --> 0(N_LogN).. and recursion is T(n) = 2T(n/2) + Cn..
    In Worst case :-  TC --> 0(N_square).. and recursion is T(n) = T(n-1) + 0(n)..
    In Avg Case  :-  TC --> 0(N_logN)..

*/

#include<bits/stdc++.h>
using namespace std;

// Hoare - Partition :-
int hoare_p(int ar[], int low, int high){
    int Pivot = ar[low];                // It Must Declare Pivot as the Low..Index..
    int i = low -1, j = high +1;        // Here we assumes as i as low -1, j as high +1;

    while(true){
        do{
            i++;
        }while(ar[i] < Pivot);          // It Follows while ar[i] is smaller than Pivot..

        do{
            j--;
        }while(ar[j] > Pivot);          // It Follows while ar[j] is Greater than Pivot..

        if (i >= j){                    // If Condition is True.. then Return j th Index.. we left side elements are smaller and equal and right side elements are Larger and equal..
            return j;
        }
        swap(ar[i], ar[j]);     // If Condition is Not True then Swap... them..
    }
    
}

//                  Quick Sort Using Hoare Partition which is More effective than Lomuto partition..
void Qsort(int ar[], int low, int high){
    
    if (low < high){                    // Must Contain alteast 2 elements.. 
        int p = hoare_p(ar, low, high);
        Qsort(ar, low, p);              // Here Which Include 'p' because here it Un stable and may not perfect as Lumto(p-1) so..
        Qsort(ar, p+1, high);
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