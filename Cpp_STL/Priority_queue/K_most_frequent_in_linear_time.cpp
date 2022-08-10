/*
    Given an array of integers, we need to print k most frequent elements.
     If there is a tie, we need to prefer the elements whose first appearance is first.
    
    Ref :- https://www.geeksforgeeks.org/find-k-most-frequent-in-linear-time/#:~:text=Find%20k%20numbers%20with%20most%20occurrences%20in%20the%20given%20array&text=The%20idea%20is%20to%20use,maximum%20frequency%20can%20be%20n.

    I/p :-  {10, 5, 20, 5, 10, 10, 30};
            k = 2;
    O/p :-  10  5

    
    I/p :-  {6, 7, 6, 7, 6, 7, 4, 4, 2, 2, 5};
        k = 3;
    O/p :-  6 7 4 (or) 7 6 4 (or) 6 7 2 (or) 7 6 2

    The idea is to use hashing with frequency indexing.
        We first store counts in a hash. Then we traverse through the hash and use 
        frequencies as the index to store elements with given frequencies. 
        The important factor here is, the maximum frequency can be n. So an array of
        size n+1 would be good.

*/ 

#include<bits/stdc++.h>
#include<map>
#include<queue>
using namespace std;

void printKfrequent(int *ar, int n, int k)
{
    unordered_map<int, int>mp;  //  In this approach order of element is random in case of same frequency item.

    for (int i=0; i<n; i++)
    {
        mp[ar[i]]++;
    }

    vector<int> Freq[n+1];
    
    for (auto x: mp)
    {
        Freq[x.second].push_back(x.first);
    }
    
    int count = 0;
    for (int i=n; i>=0; i--)
    {
        for (auto x: Freq[i])
        {
            cout << x << " ";
            count++;
            if (count == k)
            {
                return;
            }
        }
    }
}

/*
     
Printing according to the first appearance. 
    To keep the required order, we traverse the original array instead of the map. 
    To avoid duplicates, we need to mark processed entries as -1 on the map.

*/ 
void printKfrequent2(int *ar, int n, int k)
{
    unordered_map<int, int>mp;  

    for (int i=0; i<n; i++)
    {
        mp[ar[i]]++;
    }

    vector<int> Freq[n+1];
    
    for (int i=0; i<n; i++)
    {
        int x = mp[ar[i]];
        if (x != -1)
        {
            Freq[x].push_back(ar[i]);
            mp[ar[i]] = -1; //  Assuming that it is visited..
        }
    }
    
    int count = 0;
    for (int i=n; i>=0; i--)
    {
        for (auto x: Freq[i])
        {
            cout << x << " ";
            count++;
            if (count == k)
            {
                return;
            }
        }
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

    printKfrequent2(ar, n, k);

    return 0;
}