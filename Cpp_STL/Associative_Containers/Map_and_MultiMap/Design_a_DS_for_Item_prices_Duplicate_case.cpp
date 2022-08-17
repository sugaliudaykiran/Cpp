#include<bits/stdc++.h>
#include<map>
using namespace std;

multimap <int, string> mp;

void add(int price, string item) 
{                          //   O(Log N)..
    mp.insert({price, item});  // [] operator not allowed because.. multiple instance for a single key..
}

void find(int price)
{
    auto ip = mp.equal_range(price);

    for (auto it=ip.first; it != ip.second; it++)
    {
        cout << it -> second << " " << (*it).first << "\n";
    }cout << "\n";
}

void printSorted()
{                   //   0(N)..
    for (auto x: mp)
    {
        cout << x.second << " " << x.first << "\n";
    }cout << "\n";
}


void printGreaterSorted(int price)
{                       //   O(N)..
    auto it = mp.upper_bound(price);
    while (it != mp.end())
    {
        cout << it -> second << " " << (*it).first << "\n";
        it++;
    }
}

void printSmallerSorted(int price)
{                       //   O(N)..
    auto it2 = mp.lower_bound(price);
    for (auto it1 = mp.begin(); it1 != it2; it1++)
    {
        cout << (*it1).second  << " " << it1 -> first << "\n";
    }
}

int32_t main()
{
    add(5, "xyz");
    add(10, "abc");
    add(15, "uvw");
    add(100, "pqr");
    add(15, "opq");

    

    find(15);

    printSorted();

    printGreaterSorted(15);
    printSmallerSorted(15);

    return 0;
}