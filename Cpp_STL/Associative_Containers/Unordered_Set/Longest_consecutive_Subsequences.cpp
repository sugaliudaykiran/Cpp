#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int findLongest(int *ar, int n)
{
    sort(ar, ar+n); //  TC -> O(N logN)..

    int ans = 1, maxLen = 1;
    for (int i=1; i<n; i++)
    {
        if (ar[i] != ar[i-1]+1)
        {
            ans = max(ans, maxLen);
            maxLen = 1;
        }
        else
        {
            maxLen += 1;
        }
    }
    return ans;
}

int findLongest2(int* ar, int n)
{
    unordered_set <int> s;  // TC -> O(n)..     SC -> O(n)..

    for (int i=0; i<n; i++)
    {
        s.insert(ar[i]);
    }
    
    int ans = 0, maxLen = 0;
    for (int i=0; i<n; i++)
    {
        if (s.find(ar[i]-1) == s.end())
        {
            maxLen = 1;
            while (s.find(ar[i] + maxLen) != s.end())
            {
                maxLen++;
            }
            ans = max(maxLen, ans);
        }
    }
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;

    int *ar = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    cout << findLongest2(ar, n) << "\n";
}

