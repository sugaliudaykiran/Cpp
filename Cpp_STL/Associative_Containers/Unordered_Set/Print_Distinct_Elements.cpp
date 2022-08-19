#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void printDist(int * ar, int n)
{
    for (int i=0; i<n; i++) // TC -> O(n^2).. SC -> O(1)..
    {
        bool flag = false;
        for (int j=0; j<i; j++)
        {
            if (ar[i] == ar[j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << ar[i] << " ";
        }
    }cout << "\n";
}

void printDist2(int *ar, int n)  // Random order..
{
    unordered_set <int> s; // TC -> O(n).. SC -> O(n)..
    for (int i=0; i<n; i++)  // Insert, search, delete in O(1)..
    {
        s.insert(ar[i]);
    }

    for (auto x: s)
    {
        cout << x << " ";
    }cout << "\n";
}

void printDist3(int *ar, int n)  // Input order..
{
    unordered_set <int> s;  // TC -> O(n).. SC -> O(n)..
    for (int i=0; i<n; i++) // Insert, search, delete in O(1)..
    {
        if (s.find(ar[i]) == s.end())
        {
            cout << ar[i] << " ";
            s.insert(ar[i]);
        }
    }cout << "\n";
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

    // printDist(ar, n);
    printDist3(ar, n);

    return 0;
}