#include<bits/stdc++.h>
#include<unordered_map>
#include<vector>
using namespace std;

//  Ordering in case of Tie..
void sortByFreq2(int ar[], int n)
{
    unordered_map <int, int> mp;  // TC -> 0(N).. SC -> O(N)..
    for (int i=0; i<n; i++)
    {
        mp[ar[i]]++;
    }

    vector <int> freq[n+1];

    for (int i=0; i<n; i++)
    {
        if (mp[ar[i]] != -1)
        {
            freq[mp[ar[i]]].push_back(ar[i]);
            mp[ar[i]] = -1;
        }
    }

    int index = 0;
    for (int i=n; i>0; i++)
    {
        for (int x: freq[i])
        {
            for (int j=0; j<i; j++)
            {
                ar[index++] = x;
            }
        }
    }
    
}


// No ordering in case of Tie..
void sortByFreq(int ar[], int n)
{ 
    unordered_map <int, int> mp;  // TC -> 0(N).. SC -> O(N)..
    for (int i=0; i<n; i++)
    {
        mp[ar[i]]++;
    }

    vector <int> freq[n+1];

    for (auto x: mp)
    {
        freq[x.second].push_back(x.first);
    }

    int index = 0;
    for (int i=n; i>0; i++)
    {
        for (int x: freq[i])
        {
            for (int j=0; j<i; j++)
            {
                ar[index++] = x;
            }
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
    // int ar[] = {10, 5, 20, 5, 10, 10, 30};


    for (int i=0; i<n; i++)
    {
        cout << ar[i] << " ";
    }
    sortByFreq(ar, n);
    for (int i=0; i<n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}