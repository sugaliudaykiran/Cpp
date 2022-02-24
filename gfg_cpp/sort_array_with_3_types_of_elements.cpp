/*      Sort an array with three types of elements :=
    A famous interview problem in which you need to segregate an array of elements containing three types of elements.
        The types are:
           A) Sort an array of 0s, 1s, 2s.
           B) Three-way partitioning when multiple occurrences of a pivot may exist.
           C) Partitioning around a range.
    
*/
#include<bits/stdc++.h>
using namespace std;

// Navie - Solution :-          TC --> 0(N).. and AS --> 0(N).. Extra Space..
void sorts(int ar[], int n){
    int temp[n], idx = 0;           // it takes "Four - Traversals.."

    for (int i=0; i<n; i++){
        if (ar[i] == 0){
            temp[idx] = ar[i];
            idx++;
        }
    }
    for (int j=0; j<n; j++){
        if (ar[j] == 1)
            temp[idx++] = ar[j];
    }
    for (int k=0; k<n; k++){
        if (ar[k] == 2){
            temp[idx++] = ar[k];
        }
    }

    for (int i=0; i<n; i++){
        ar[i] = temp[i];
    }
}

/* Efficient - Solution (Using Hoare Partition) :-  ** Dutch National Flag Algorithm ** 
    Idea to Solve :-
        A) The Section 0 to Low-1 which Contain Zeroes..
        B) The Section Low to Mid-1 which Contain Ones..
        C) The Section Mid to High Which Contain Un - Known..
        D) The Section High to N-1 Which Contain Twoes..
    Initially that :-
        A) Low and Mid Start from "Zero" and High start from the "N-1".. (Which Both Cannot Go Beyond the limits..)

     Array -->  | 0's | 1's | Un-knowns  | 2's |
                ^       ^     ^         ^   
                |       |     |         |
    Indexs  --> 0      low    mid       high..      
*/
//                               TC -> 0(N).. AS -> 0(1).. and in "One - Traversal"..
void sort_3(int ar[], int n){
    int low = 0, mid = 0, high = n-1;       

    while (mid <= high){
        if (ar[mid] == 0){
            swap(ar[mid], ar[low]);
            mid++;
            low++;
        }
        else if (ar[mid] == 1){
            mid++;
        }
        else{           // These are 2's
            swap(ar[mid], ar[high]);
            high--;
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

    // sorts(ar, n);
    
    sort_3(ar, n);
    for (int s: ar){
        cout << s << " ";
    }
    return 0;
}