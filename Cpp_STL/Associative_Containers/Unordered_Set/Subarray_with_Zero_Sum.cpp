#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

bool isSum(int *ar, int n)
{
    for (int i=0; i<n; i++) //  TC -> O(N logN)..
    {
        int sum = ar[i];
        if (sum == 0)
        {
            return true;
        }
        
        for (int j=i+1; j<n; j++)
        {
            sum += ar[j];

            if (sum == 0)
            {
                return true;
            }
        }
    }return false;
}

bool isSum2(int *ar, int n)
{
    unordered_set <int> s; // Using PrefixSum.. 
    int preFixSum  = 0;     //  TC -> O(N).. SC -> O(N)..

    for (int i=0; i<n; i++)
    {
        preFixSum += ar[i];

        if (s.find(preFixSum) != s.end())
        {
            return true;
        }
        if (preFixSum == 0)
        {
            return true;
        }

        s.insert(preFixSum);
    }    
    return false;
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

    if (isSum2(ar, n) == 1)
    {
        cout << "Yes" << "\n";
    }
    else
    {
        cout << "No" << "\n";
    }

    return 0;
}

