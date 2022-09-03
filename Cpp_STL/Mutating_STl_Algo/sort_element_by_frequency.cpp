#include<bits/stdc++.h>
using namespace std;


bool myCmp(const pair <int, int>& p1, const pair <int, int>& p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

void sortByFreq(int *ar, int n)  // TC -> O(Nlog N)..    SC -> O(N)
{                                                           
    unordered_map <int, int> mp;
    for (int i=0; i<n; i++)
    {
        mp[ar[i]]++;
    }

    vector <pair<int, int>> v(mp.begin(), mp.end());

    sort(v.begin(), v.end(), myCmp);

    int j = 0;
    for (auto x: v)
    {
        for (int i=0; i<x.second; i++)
        {
            ar[j++] = x.first;
        }
    }
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

    sortByFreq(ar, n);

    for (int i=0; i<n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}