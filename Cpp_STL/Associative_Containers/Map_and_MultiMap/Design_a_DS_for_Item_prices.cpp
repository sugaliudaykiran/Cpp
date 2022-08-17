#include<bits/stdc++.h>
#include<map>
using namespace std;

map <int, string> mp;

void add(int price, string item) 
{                          //   O(Log N)..
    // mp.insert({price, item});
    mp[price] = item;
}

string find(int price)
{                          //   O(Log N)..
    // auto it = mp.find(price);
    // if (it != mp.end())
    // {
    //     return (*it).second;
    // }
    // else{
    //     return "";
    // }

    string item = mp[price];
    return item;    
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
        cout << (*it).second << " " << (*it).first << "\n";
        it++;
    }cout << "\n";
}

void printSmallerSorted(int price)
{                       //   O(N)..
    auto it2 = mp.lower_bound(price), it1 = mp.begin();
    for (; it1 != it2; it1++)
    {
        cout << it1 -> second << " " << it1 -> first << "\n";
    }
}

int32_t main()
{
    add(10, "abc");
    add(5, "xyz");
    add(100, "pqr");

    cout << find(5) << "\n";

    printSorted();

    printGreaterSorted(7);
    printSmallerSorted(20);

    return 0;
}