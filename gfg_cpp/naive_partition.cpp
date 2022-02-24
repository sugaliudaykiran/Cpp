/*
    Naive partition :-
    Introduction to the Partition method of Quick Sort. 
    This partitioning method is a naive way of approach towards partitioning an array.

    Ques := Partition a given array.. in this an array is given with an pivot(with an index..) and we need to find
            lower and equal values before it and higher values after it..
            and also return Index of the pivot.. 

    Stability :-
        Stable  and         Un-Stable 
        |                      |    
    Navie-partition      Lomuto, Hoare(Most efficient.. and Unstable..)

*/

#include<bits/stdc++.h>
using namespace std;

// Naive partition :-
void partition(int ar[], int l, int h, int p){      // TC --> 0(N).. AS --> 0(N)..  
    int temp[h -l+1], index = 0;

    // Smaller elements than the Pivot elements..
    for (int i=l; i <= h; i++){
        if (ar[p] > ar[i]){
            temp[index] = ar[i];
            index++;
        }
    }
    // Equal elements to the pivot elements..
    for (int j=l; j<= h; j++){
        if (ar[p] == ar[j]){
            temp[index] = ar[p];
            index++;
        }
    }
    // res -> Index of the Pivot element in Original array because.. it is Stable..Last Occurances of Pivot Value..
    int res = l + index -1;    // {Index -1 because in above condition it's added similar elements..} and
                                //  [l + index-1 ] this is because of depency on the user input it may changes..

    // Greater elements to the pivot elements..
    for (int k = l; k <= h; k++){
        if (ar[p] < ar[k]){
            ar[index] = ar[k];
            index++;
        }
    }
    // Copying to the Original array..
    for (int i = l; i <= h; i++){
        ar[i] = temp[i-l];
    }
    cout << res << endl;
}

int32_t main(){
    int n, p;           // Pivot Index...in array..
    cin >> n >> p;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    int l = 0, h = n-1;

    partition(ar, l, h, p);

    return 0;
}
