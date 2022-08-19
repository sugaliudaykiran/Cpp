// Maximum Distinct Items..
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int MaxDist(int *ar, int n, int k)
{
    unordered_set <int> s; // TC -> O(n).. SC -> O(n)..
    for (int i=0; i<n; i++)
    {
        s.insert(ar[i]);
    }

    int d = s.size();
    
    if (d >= n/k)
    {
        return n/k;
    }
    else
    {
        return d;
    }
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

    cout << MaxDist(ar, n, k) << "\n";

    return 0;
}