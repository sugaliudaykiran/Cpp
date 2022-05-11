/*

  Containers Ref :- https://www.geeksforgeeks.org/containers-cpp-stl/

    Iterating Containers :-
        One way of iterating them using iterator, like
            for (auto it=s.begin(); it!=s.end(); it++)
            {
                cout << *it << " ";
            }
        // This works for all three:    set, map, vector.

    Shortand:
        vector <int> v;                 set <int> s;                map <int, int> m;
        for (int x: v)                  for (int x: s)              for (pair<int, int>x:v)
            //  x                           //  x                       //  x.first, x.second
        

*/ 

#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    set <int> s;
    
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++)
    {   
        int x;
        cin >> x;
        s.insert(x);
    }

    s.erase(2);     // at every movement 'set' make itself in sorted order, by help of RED_BLACK tree algorithm.  
    for (int x: s)
    {
        cout << x << " ";
    }

    return 0;
}