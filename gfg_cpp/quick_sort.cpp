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

// Lomuto Partition..       The Name itself start with L so it's hint is Pivot is LAST element..
int lomuto_p(int ar[], int low, int high){
    int pivot = ar[high];
    int i = low -1;             // And i start from the low-1..

    for (int j=low; j<= high-1; j++){   // j from low to High-1 because.. last is an pivot element..
        if (ar[j] < pivot){
            i++;
            swap(ar[i], ar[j]);     // If any element is Smaller than Pivot then Increment " i++ " and swap the elements..i, j..
        }
    }
    swap(ar[i+1], ar[high]);  // On final we swap the i+1 element with last element.. for the Current Position..
    return i+1;             // and returing the Index of it..
}

// Quick Sort Algorithm :-      QuickSort using the method of Lomuto Partition..
void Qsort(int ar[], int low, int high) {      
    
    if (low < high){                    // Array Alteast Must Contain 2 elements..
        int p = lomuto_p(ar, low, high);    //  Use of Lomuto..which an In-place..Partition..       In BST.. we can consider as Root_Node..
        Qsort(ar, low, p-1);     // and Sorting remaining left side elements to the Pivot..                 as the Left side of Root_Node..
        Qsort(ar, p+1, high);   //  and Sorting remaining Right side elements to the Pivot..                 as the Right side of Root_Node..
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