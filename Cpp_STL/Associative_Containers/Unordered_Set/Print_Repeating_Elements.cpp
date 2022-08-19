#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void printRepeat(int *ar, int n)
{
    for (int i=1; i<n; i++)
    {               // TC -> O(n^2).. SC -> O(1)..
        bool flag = false;
        for (int j=0; j<i; j++)
        {
            if (ar[i] == ar[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            cout << ar[i] << " ";
        }
    }cout << "\n";
}

void printRepeat2(int *ar, int n)
{
    unordered_set <int> s;  // TC -> O(n).. SC -> O(n)..
    for (int i=0; i<n; i++)
    {
        if (s.find(ar[i]) != s.end())
        {
            cout << ar[i] << " ";
        }
        else{
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

    printRepeat2(ar, n);

    return 0;
}