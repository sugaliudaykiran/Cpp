/* 

The Stability in Sorting Algorithm :=
    Stable sorts :-  Which follows the Stablity of arranging the elements..
                ex:- Bubble Sort, Merge Sort, Insertion Sort..

    Un-Stable sorts :-   Which doesn't follows the Stablity of arranging the elements..
                    ex :-   Quick Sort, Selection Sort, Heap Sort..
*/

// Bubble Sort :-  TC --> (n-1) + (n-2) +.. + 3 + 2 + 1..
                        // => is equal to (N * N-1)/2 .. => 0(N_square)..
                        // it is stable and in-place..

#include<bits/stdc++.h>
using namespace std;

// Bubble Sort :-   // it is stable and in-place(Doesn't required any extra space and change in itself)..
void Bs_(int ar[], int n){
    for (int i=0; i<n-1; i++){              // i < n-1 because of the we need to traverse upto the N-2..element 
        bool swapped = false;               //  **  {j < n-1} Which is Not an Optimal Solution..
        for (int j=0; j<n-i-1; j++){        // traverse upto ar[N-2] th value..for the ar[N-1] element..  
            if (ar[j] > ar[j+1]){
                swap(ar[j], ar[j+1]);
                swapped = true;
            }
        }
        if (!swapped){      // Which is swapped == false..
            break;
        }
    }
}


int32_t main(){
    int n;
    cin >> n;

    int ar[n];

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    Bs_(ar, n);

    for (int x: ar){
        cout << x << " " ;
    }
    return 0;

}