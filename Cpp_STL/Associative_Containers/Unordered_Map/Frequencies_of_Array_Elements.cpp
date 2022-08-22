#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printFreq(int *ar, int n) // TC -> O(N^2).. SC -> O(N)..
{
    unordered_set <int> s;

    for (int i=0; i<n; i++)
    {
        if (s.find(ar[i]) != s.end())
        {
            continue;
        }
        int count = 1;
        
        for (int j=i+1; j<n; j++)
        {
            if (ar[i] == ar[j])
            {   
                count++;
            } 
        }
        cout << ar[i] << " " << count <<  "\n";
        s.insert(ar[i]);
    }
}

void printFreq2(int *ar, int n)  // TC -> O(n)..    SC -> O(n)..
{
    unordered_map <int, int> mp;
    for (int i=0; i<n; i++)
    {
        mp[ar[i]]++;
    }

    // for (auto x: mp)  // unordered_map is stored in unordered.. using Hashing..
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }

    for (int i=0; i<n; i++)
    {
        auto it = mp.find(ar[i]);
        if (it != mp.end())
        {
            cout << it -> first << " " << it -> second << "\n";
            mp.erase(it);
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

    printFreq2(ar, n);
    return 0;
}