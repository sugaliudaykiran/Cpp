#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct point{
    int x, y;

    point(int x, int y)
    {
        this -> x = x;
        this -> y = y;
    }
};

bool myCmp(const point &p1, const point &p2)
{
    if (p1.x == p2.x)
    {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

int32_t main()  // TC -> O(n) => Both min_element and max_element..
{
    vector <int> v = {10, 12, 30, 4};
    auto it = min_element(v.begin(), v.end());
    cout << *(it) << " ";
    it = max_element(v.begin(), v.end());
    cout << *(it) << "\n";

    
    vector <char> v2 = {'a', 'z', 'e', 'f'};
    cout << *(min_element(v2.begin(), v2.end())) << " "
         << *(max_element(v2.begin(), v2.end())) << "\n";
    
    
    int ar[] = {11, 2, 4, 5};
    cout << *(min_element(ar, ar+4)) << " ";
    cout << *(max_element(ar, ar+4)) << "\n";


    vector <point> v3 = {{12, 2}, {3, 40}, {3, 2}, {12, 33}, {11, 0}};
    auto it2 = min_element(v3.begin(), v3.end(), myCmp);
    cout << it2-> x << " " << (*it2).y  << "\n";  

    it2 = max_element(v3.begin(), v3.end(), myCmp);
    cout << it2-> x << " " << (*it2).y  << "\n";  

    return 0;
}