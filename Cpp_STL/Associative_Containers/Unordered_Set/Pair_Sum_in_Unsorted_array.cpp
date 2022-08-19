#include<bits/stdc++.h>
#include<unordered_set> 
using namespace std;

bool isPair(int *ar, int n, int sum)
{                          // TC -> O(n^2).. SC -> O(1)..
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (ar[i] + ar[j] == sum)
            {
                return true;
            }
        }
    }
    return false;
}

bool isPair2(int *ar, int n, int sum)
{
    unordered_set <int> s; // TC -> O(n).. SC -> O(n)..

    for (int i=0; i<n; i++)
    {
        int x = sum - ar[i];
        if (s.find(x) != s.end())
        {
            return true;
        }
        else
        {
            s.insert(ar[i]);
        }
    }
    return false;
}

int32_t main()
{
    int n, sum;
    cin >> n >> sum;

    int *ar = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    if (isPair2(ar, n, sum) == 1)
    {
        cout << "Yes" << "\n";
    }
    else
    {
        cout << "No" << "\n";
    }

    return 0;
}