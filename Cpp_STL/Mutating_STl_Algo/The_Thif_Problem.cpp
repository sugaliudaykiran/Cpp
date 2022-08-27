#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//  Navie Solution :- Traversing the array and find the maximum of k items in array.
        //  TC -> O(N*K)..  SC -> O(1)..

int getMaxVal(int *ar, int n, int k)// Sort the array and traverse upto K item and return sum of k items..
{   
    int ans = 0;
    sort(ar, ar+n, greater<int>());
    for (int i=0; i<k; i++)
    {
        ans += ar[i];
    }
    return ans; //  TC -> O(K+ NlogN)  => O(N LogN)..
}

// Efficient Solution Using priority_queue [Max Heap and Min Heap]..
                // TC -> O(N + KLogN).. SC -> O(N) &&    TC -> O(K + (N-k)LogK).. SC -> O(K)..     

int32_t main()
{
    int n = 6, k = 3; // print all sum of k max items..

    int ar[] = {3, 7, 2, 5, 12, 30};

    cout << getMaxVal(ar, n, k) << "\n"; 
    return 0;
}
