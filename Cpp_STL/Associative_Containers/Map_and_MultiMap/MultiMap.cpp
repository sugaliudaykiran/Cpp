#include<bits/stdc++.h>
#include<map>
using namespace std;

int32_t main()
{
    multimap <int, int> mp; // Multimap similiar to map and uses internal red black tree[Self balancing binary search tree.]..
                    //  Then main difference is same key has multiple instance (or) Values,[] operator.. can't used for this multiple instance case..
    mp.insert({10, 21});
    mp.insert({5, 40});
    mp.insert({10, 12});
    mp.insert({1, 10});
    mp.insert({20, 5});

    for (auto x: mp) // Non decreasing order..
    {
        cout << x.first << " " << x.second << "\n";
    }cout << "\n";

    cout << mp.count(10) << "\n";   //  return count of instance of key..
    auto it = mp.find(10);
    // mp.erase(10);  // removes all instance of the key..
    // mp.erase(it);     // removes only iterator pointing element..
    // mp.erase(it, mp.end()); 

    // cout << mp.count(10) << " " << mp.size() << "\n";  

    auto it1 = mp.lower_bound(10);
    auto it2 = mp.upper_bound(10);
    // cout << (*it1).first << " " << it2 -> first << "\n"; // we can declare any sort of them..

    auto ip = mp.equal_range(10); // which return pair of multimap<int>::iterator..  which holds lower_bound by first and upper_bound by second.
    for (auto it = ip.first; it != ip.second; it++)
    {
        cout << it -> first << " " << it -> second << "\n";
    }
}