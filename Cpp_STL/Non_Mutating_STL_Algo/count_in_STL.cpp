#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int32_t main() // TC -> O(n)..
{
    vector <int> v = {10, 20, 30, 40, 10, 20, 40, 10};
    cout << 10 << ": " << count(v.begin(), v.end(), 10) << "\n";


    int ar[] = {1, 2, 4, 5};
    cout << 2 << ": " << count(ar, ar+4, 2) << "\n";


    list<int> l = {11, 21, 11, 22, 10}; // Doubly Linked list..
    cout << 10 << ": " <<  count(l.begin(), l.end(), 10) << "\n";


    string str = "geeksforgeeks";
    cout << 'e' << ": " << count(str.begin(), str.end(), 'e') << "\n";

    return 0;
}