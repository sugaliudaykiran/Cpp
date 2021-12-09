// ques -> https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// ans -> https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int sortArr_k(int ar[], int n, int k){
    sort(ar, ar + n);

    return (ar[k-1]);
}


int32_t main(){
    int n, k;
    cin >> n >> k;
    int ar[n];
    // n = sizeof(ar)/sizeof(ar[0]);

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    //cout << sortArr_k(ar, n, k) << endl;

    set <int> s(ar, ar+n);
    set <int> ::iterator itr = s.begin(); // s.begin() returns a pointer to first
                                    // element in the set
    advance(itr, k-1); // itr points to kth element in set
    cout << * itr << endl;
    return 0;
}

/*
Method 1 (Simple Solution) 
A simple solution is to sort the given array using a O(N log N) sorting algorithm
like Merge Sort, Heap Sort, etc, and return the element at index k-1 in the sorted array. 
Time Complexity of this solution is O(N Log N);


Method 2 (using set from C++ STL)
we can find the kth smallest element in time complexity better than O(N log N).
we know the Set in C++ STL is implemented using Binary Search Tree 
and we also know that the time complexity of all cases(searching , inserting,
, deleting ) in BST is log (n) in average case and O(n) in worst case .
we are using set because it is mentioned in the question that all 
the elements in array re distinct.
Time Complexity:  O( log N) in Average Case and O(N) in Worst Case
Auxiliary Space: O(N)

Method 3 (Using Min Heap – HeapSelect) 
We can find k’th smallest element in time complexity better than O(N Log N).
 A simple optimization is to create a "Min Heap" of the given n elements and
  call extractMin() k times.

*/