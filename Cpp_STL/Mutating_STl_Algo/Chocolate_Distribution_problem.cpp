#include<bits/stdc++.h>
using namespace std;

int MinDiff(int *ar, int n, int m)
{
    if (m > n)
    {
        return -1;
    }

    sort(ar, ar+n);  // TC -> O(N logN) + O(N-M+1)..     SC -> O(1)..

    int ans = ar[m-1] - ar[0];

    for (int i=1; (i+m-1)<n; i++) //  or (i < n-m+1)..
    {
        ans = min(ar[i+m-1] - ar[i], ans);
    }

    return ans;
}



int32_t main()
{
    int n, m;
    cin >> n >> m;

    int *ar = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    cout << MinDiff(ar, n, m) << "\n"; 
    return 0;
}
