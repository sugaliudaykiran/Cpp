/*
    Given an array and a number k where k is smaller than the size of the array, 
        we need to find the k’th smallest element in the given array. It is given that 
        all array elements are distinct.

Examples:  
    Input: arr[] = {7, 10, 4, 3, 20, 15}, k = 3 
    Output: 7

    Input: arr[] = {7, 10, 4, 3, 20, 15}, k = 4 
    Output: 10 

// Ref :-  https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
*/  

#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;

int Ksmallest(int *ar, int n, int k)
{   //  Using Sorting :-    TC -> O(N LogN)..
    sort(ar, ar+n);

    return ar[k-1];
}

int Ksmallest2(int *ar, int n, int k)
{   //  Using Min Heap..    TC -> O(N + K Log N)..  SC -> O(N).. For Priority_queue..
    priority_queue<int, vector<int>, greater<int>> pq(ar, ar+n);

    for (int i=0; i<k-1; i++)
    {
        pq.pop();
    }
    return pq.top();
}

int Ksmallest3(int *ar, int n, int k)
{   //  Using Max_Heap..    TC -> O(K + (N-K) LogK).. SC -> O(K)..
    priority_queue<int> pq(ar, ar+k);

    for (int i=k; i<n; i++)
    {
        if (pq.top() > ar[i])
        {
            pq.pop();
            pq.push(ar[i]);
        }
    }
    return pq.top();
}


int Ksmallest4(int *ar, int n, int k)
{   //  Using Set.. because elements are distinct element..
    set <int> s(ar, ar+n);  
    // insert/delete/search of element..   0(Log N).. in average case..  O(N) in worst case..
    auto it = s.begin();    //  SC -> O(N)..
    
    advance(it, k-1);   
    // This shall only be negative for random-access and bidirectional iterators.
    return *it;
}

int32_t main()
{
    int n, k;
    cin >> n >> k;

    int *ar = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    cout << Ksmallest4(ar, n, k) << "\n";
    return 0;
}