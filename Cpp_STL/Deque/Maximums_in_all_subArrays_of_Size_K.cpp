/*
    Given array ar[] = {20, 40, 30, 10, 60};
        and k = 3,  need to find the maximums in all subarrays of size K..

    O/p :-  40  40  60   --> no of maximum in subarrays are [N - k+1]..

*/ 
#include<bits/stdc++.h>
#include<deque>
using namespace std;

/*  
    Navie solution :-   TC -> O(N^2)..  Traverse from i (0 to N-K+1) and maxx = ar[i] 
          traversing from j (i+1, k+i) finding the maximum of them..
*/
void Maximums(int *ar, int n, int k)
{
    for (int i=0; i<n-k+1; i++)
    {
        int maxx = ar[i];
        for (int j=i+1; j<k+i; j++)
        {
            maxx = max(ar[j], maxx);
        }
        cout << maxx << " ";
    }cout << "\n";
}

/*
    Efficient solution :-  TC -> O(N).. Using deque, by this we can push_front(), push_back(), pop_back(), pop_front()..
        all this operations in O(1)..  
*/

void Maximums2(int *ar, int n, int k)
{
    deque <int> dq;
    for (int i=0; i<k; i++)
    {
        while (!dq.empty() && ar[i] >= ar[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i=k; i<n; i++)
    {
        cout << ar[dq.front()] << " "; 
        while (!dq.empty() && dq.front() <= i-k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && ar[i] >= ar[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    cout << ar[dq.front()] << " ";
}




int32_t main()
{
    int n, k;
    cin >> n >> k;

    int *ar = new int [n];

    for (int i=0; i<n; i++)
    {
        cin >> ar[i];
    }   
    Maximums2(ar, n, k);

    return 0;
}