/*
    Couting Sort :-
    A) TC --> O(N+K)..time to sort N elements in range from 0 to K-1..
    B) It takes linear Time to sort and Which is not An Comparion Based Sorting Algorithm..
    C) Which is an Count Based Sorting ...which Count the Occuries of the elements..
    D) If K is Linear Than Only it is Useful.. But Not in case of the K in Quardiate range.. 
    E) Because we have better Algo which takes O(N_LogN)..

    Important Point :=
    1) Not a Comparison Based Algorithm 
    2) 0(N+K) Time..
    3) 0(N+K) Auxiliary Space..
    4) Stable..
    5) Used as a subroutine in radix sort.. {Because Counting sort well performed when K is Liner.. if K is Quardiate then TC will be in O(N_cube..)}
    6) In that cases Radix sort is better performed than Counting Sort..

    Exercise :-
    1) Extend the given Implementation to work for an arbitrary range of size K..
*/

#include<bits/stdc++.h>
using namespace std;

// Navie - Solution :-
void Count_sort(int ar[], int n, int k){    // If K is Linear..
    int counT[k];
    for (int i=0; i<k; i++){        // TC --> 0(K)
        counT[i] = 0;
    }
    for (int j=0; j<n; j++){        // TC --> 0(N)
        counT[ar[j]]++;
    }

    int indx = 0;
    for(int i=0; i<k; i++){             // TC --> 0(N+K)..
        for (int j=0; j<counT[i]; j++){
            ar[indx] = i;
            indx++;
        }
    }
}

// In case of Objects..
/*
    Navie Implementation :=             TC --> 0(N+K).. AS --> 0(N+K)..
    Problem with this Approach..
        Can not be used as a general purpose algorithm for sorting Object with Multiple members 
        Like Sorting an array of Students by Marks..
*/
void c_s(int ar[], int n, int k){
    int Count[k];
    for (int i=0; i<k; i++){            // TC --> 0(K)..
        Count[i] = 0;   
    }
    for (int i=0; i<n; i++){
        Count[ar[i]]++;                 // TC --> 0(N)..
    }
           // Array element as Index on the Count_array and Inserting the Index of array as Output array and decrement the count elements..
    
    for (int i=1; i<k; i++){
        Count[i] = Count[i] + Count[i-1];       // TC --> 0(K)..
    }

    int output[n];
    for (int k = n-1; k >= 0; k--){             // TC --> 0(N)..
        output[Count[ar[k]] -1] = ar[k];
        Count[ar[k]]--;
    }

    for (int j=0; j<n; j++){                    // TC --> 0(N)..
        ar[j] = output[j];
    }
}

int32_t main(){
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // Count_sort(ar, n, k);
    c_s(ar, n, k);

    for (int s : ar){
        cout << s << " ";
    }
    return 0;
}