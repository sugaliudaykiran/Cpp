#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


void Intersection(int *a, int m, int *b, int n)
{
    for (int i=0; i<m; i++)
    {
        bool flag = false;
        for (int j=0; j<n; j++)
        {
            if (a[i] == b[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            cout << a[i] << " ";
        }
    }cout << "\n";
}

void Intersection2(int *a, int m, int *b, int n)
{
    unordered_set <int> s;

    for (int i=0; i<n; i++)
    {
        s.insert(b[i]);
    }

    for (int i=0; i<m; i++)
    {
        if (s.find(a[i]) != s.end())
        {
            cout << a[i] << " ";
        } 
    }cout << "\n";
}

int32_t main()
{
    int m, n;
    cin >> m >> n;

    int *a = new int[m];
    int *b = new int[n];

    for (int i=0; i<m; i++)
    {
        cin >> a[i];
    }

    for (int i=0; i<n; i++)
    {
        cin >> b[i];
    }

    Intersection2(a, m, b, n);
}