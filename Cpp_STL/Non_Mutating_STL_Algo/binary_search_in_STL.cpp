#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct point
{
    int x, y;
    
    point(int x, int y)
    {
        this -> x = x;
        this -> y = y;
    }
};
bool myCmp(const point&p1, const point&p2)
{
    return p1.x < p2.x;
}


int32_t main()
{              // TC -> O(Log N).. Binary Search ..
    vector <int> v = {1, 2, 3, 5, 7, 10}; // container need to be' SORTED '..
    int x = 4;   // If x is present in container return true.. else false..
    if (binary_search(v.begin(), v.end(), x) == true) 
    {
        cout << "Found..!" << "\n";
    }
    else{
        cout << "Not Found..!" << "\n";
    }

    int ar[] = {10, 29, 33, 55, 99};
    int y = 33;
    if (binary_search(ar, ar+5, y) == true)
    {
        cout << "Found..!" << "\n";
    }
    else
    {
        cout << "Not Found..!" << "\n";
    }

    vector <point> v2 = {{1, 2}, {5, 6}, {11, 3}, {21, 1}};
    point p1(21, 1);
    point p2(21, 2);  // Here binary search based on the myCmp function.. so it search based on 'x' val.. and ignore 'y' values..

    if (binary_search(v2.begin(), v2.end(), p2, myCmp) == true)
    {
        cout << "Found..!" << "\n";
    }
    else{
        cout << "Not Found..!" << "\n";
    }

    return 0;
}


/*
        In case of Random access container O(Log N) else O(N) incase of list,..
    Internal working is based on lower_bound().. TC -> O(Log N)..

    auto it = lower_bound(Begin, End, x);
    if (it != End && !(x < *(it)))
    {
        return true;
    }
    else{
        return false;
    }

*/ 