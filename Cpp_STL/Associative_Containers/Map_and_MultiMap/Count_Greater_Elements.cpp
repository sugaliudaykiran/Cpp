#include<bits/stdc++.h>
#include<map>
using namespace std;


void PrintCountGreaterELE(int *ar, int n)
{                             //  TC -> O(N^2)..
    for (int i=0; i<n; i++)
    {
        int count = 0;
        for (int j=0; j<n; j++)
        {
            if (i != j && ar[j] > ar[i])
            {
                count++;
            }
        }
        cout << count << " ";
    }cout << "\n";
}

void PrintCountGreaterELE2(int *ar, int n)
{                       //  TC -> O(N LogN).. SC -> O(N)..
    map <int, int> mp;
    for (int i=0; i<n; i++)
    {
        mp[ar[i]]++;
    }

    int cum_freq = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        int freq = it -> second;
        it -> second = cum_freq;
        cum_freq += freq;
    }

    for (int i=0; i<n; i++)
    {
        cout << mp[ar[i]] << " ";
    }cout << "\n";
}

void PrintCountGreaterELE3(int *ar, int n)
{                                   //  TC -> O(N LogN).. SC -> O(N)..
    vector <int> temp;
    for (int i=0; i<n; i++)
    {
        temp.push_back(ar[i]);
    }

    sort(temp.begin(), temp.end());

    for (int i=0; i<n; i++)
    {
        auto x = upper_bound(temp.begin(), temp.end(), ar[i]);
        int index = x - temp.begin();

        cout << n-index << " ";
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

    PrintCountGreaterELE3(ar, n);
    return 0;
}