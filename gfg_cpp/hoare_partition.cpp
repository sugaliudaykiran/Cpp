/*
    Hoare partition :- which is another method of partitioning. 
        This is better than the previously discussed Partitioning method.. and "Un-Stable"..
        This method takes constant space and O(n) time for partitioning. 
        It also travels the input array only once.

    Idea of Implementation :-
        1) In this Partition we assumed the first element as the Pivot element..
        2) and take i and j which are assigned as 'i' from the (low-1) and 'j' from the (high+1)..
        3) the output in form of Left side is smaller than pivot and greater and equal elements include the pivot on the left side..
        4) It is Un stable because of the it does not provide the right order like Navie apporach ..
*/

#include<bits/stdc++.h>
using namespace std;

// Hoare_Partition :-
int hp(int ar[], int low, int high){
    int pivot = ar[0];
    int i = low -1, j = high +1;
    while (true){
        do{
            i++;   // In these we always Increment the i Value..and check the i th element is smaller than pivot..
        }while (ar[i] < pivot);         

        do{
            j--;   // In these we always Decrement the j Value..and check the j th element is greater than pivot..
        }while (ar[j] > pivot);
        
        if (i >= j){     // For the termination we then condition that i >= j..then return j..
            return j;       // Here 'J' which defines that element in array which are less than Pivot and after it the elements equal and greater..
        }
        
        swap(ar[i], ar[j]);     // If it is Not Terminated then swap the elements..
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
    
    cout << hp(ar, low, high);
    cout << endl;

    for (int s: ar){
        cout << s << " ";
    }
    return 0;
}

