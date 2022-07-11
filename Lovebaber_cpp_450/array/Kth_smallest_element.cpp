#include<bits/stdc++.h>
using namespace std;


int kthSmallest(int arr[], int l, int r, int k) 
{
       priority_queue <int> maxh;  // using Max Heap..


       for (int i=0; i<(l+r)+1; i++)  // TC → O(nlogk)..
       {
           maxh.push(arr[i]);
           if (maxh.size() > k)
           {
               maxh.pop();
           }
       }       
       return maxh.top();
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

    cout << k <<"_Smallest element : "<< kthSmallest(ar, 0, n-1, k);
}


/*
    1) Identifing that given question is use of heap or not, by checking that input has K, need to find 
        smallest or largest..
    2) In this we uses Max Heap.. because by this we remove the max element and find the K_th smallest element,..
    3) Traverse the array and insert the element to heap by this size of 'K'..
    4) When size of heap becomes '> K' then pop() from the heap.. 
*/ 