#include<bits/stdc++.h>
#include<algorithm>
using namespace std;    //  TC -> O(n)..
    //  Find(Begin, End, X) -> Supports all the container.. Search Linear Time.. uses mostly in Vector, array, List, dequeue
    //  Map, Set, Unordered_Map, Unordered_Set, String -> Has memeber function find() which work effectively.. 
    
int32_t main()
{
    vector <int> v = {5, 10, 7, 10, 20};
    auto it = find(v.begin(), v.end(), 7); // Does Linear Search..
    if (it == v.end())
    {
        cout << "Not Found..!" << "\n";
    }
    else{
        cout << "Found at Index: " << (it - v.begin());
    }cout << "\n";

    
    int n = 5;
    int ar[5] = {10, 2, 7, 11, 21};
    int *ptr = find(ar, ar+n, 21);

    if (ptr == ar+n)
    {
        cout << "Not Found..!" << "\n";
    }
    else{
        cout << "Found at Index: " << ptr - ar;
    }cout << "\n";

    
    list <int> l = {10, 29, 44, 6, 1};
    auto it2 = find(l.begin(), l.end(), 10);
    if (it2 == l.end())
    {
        cout << "Not Found..!" << "\n";
    }
    else{
        cout << "Found " << "\n";
    }cout << "\n";

    return 0;
}