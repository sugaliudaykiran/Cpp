/* Lomuto Partition which is another method of partitioning. 
     In this method, the traversal is done only once with a constant space complexity.
    {This is Un-Stable..}
    Lomuto Partition :- In this Partition we traverse through the array ones which is better than Navie - partition 
                and take AS --> O(1).. and TC --> O(N)..
    Idea of these :- In this Partition which we assumes the Pivot element as the last element and travers by following conditions..
        **  1) Assumes the Last is an Pivot element if pivot element is not given..
            2) Take the I th element which starts Low-1 .. and this is elements which are smaller element than the Pivot..
            3) Then J start from Low to High-1 (Including it) because the Last element is already pivot element.. and these are element remains as the greater elements..than pivot..
            4) We start from the J and check with Pivot and if the element is greater we remains as it..
            5) If the element is smaller than we swap the element with (i) element and  Increment the i++..at last..
            6) we reaches to the pivot element(ar[high]) and swap with (i+1) element..and returing the Index of Pivot as (i+1)..

        **  1) if pivot element is given..then swap the high_index to Pivot element and follow the above conditions..
*/

#include<bits/stdc++.h>
using namespace std;

// Lomuto - Partition :-        TC --> O(N)... and AS --> O(1)..
int iparts(int ar[], int low, int high, int p){
    int i = low -1;
    // Assuming the Last Element as Pivot...
    int Pivot = ar[high];
    // If Pivot is Given then Swap..With Last element..
    // swap(ar[p], ar[high]);

    for (int j=low; j<=high-1; j++){
        if (ar[j] < Pivot){
            i++;
            swap(ar[i], ar[j]);
        }
    }
    swap(ar[i+1], ar[high]);
    return i+1;             // Because we Take Increment of the I th element so we need the perfect index of pivot by the increment of the I th element..
}

int32_t main(){
    int n, p;
    cin >> n >> p;
    
    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    int low = 0, high = n-1;

    cout << iparts(ar, low, high, p);
    cout << endl;

    for (int y: ar){
        cout << y << " ";
    }
    return 0;
}