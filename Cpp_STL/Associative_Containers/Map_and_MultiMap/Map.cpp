#include<bits/stdc++.h>
#include<map>
using namespace std;

int32_t main()
{
    map <int, int> mp;  //  Map is similiar to 'set' but map stores (key, value) pair..
                        //  every object in map is' a pair object '..
        
    mp.insert({1, 20});
    mp.insert({2, 30});
    // mp.insert({3, 10});
    mp.insert({4, 20}); 
    mp.insert({2, 30}); // Map doesn't allows duplicates..
    mp.insert({2, 30});
    mp[5] = 50; //  "[] operator " used for assign val if exits in map..
    mp[6] = 60;         //  Else it creates and assgin the val.. 
    
    cout << mp[7] << "\n"; // or with default val in case of no-assigned val..
    // cout << mp.at(8) <<"\n"; // terminate called after throwing an instance of 'std::out_of_range'

    for (auto &x: mp)    //  Map internal uses Red black tree..
    {
        cout << x.first << " " << x.second << "\n";
    }cout << "\n";


    // for (auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     cout << (*it).first << " " << (*it).second  << "\n";
    // }

    
    if (mp.find(7) != mp.end()) // Find(X) if present in map return iterator point it..
    {                                   //  Else iterator points to mp.end()..
        cout << "Found..!" <<"\n";
    }
    else{
        cout << " Not Found..!" << "\n";
    }

    // for (auto it = mp.find(2); it != --mp.end(); it++)
    // {
    //     cout << (*it).first << " " << (*it).second << "\n";
    // }

    if (mp.count(7) != 0) // If key is present then return '1' else '0'.
    {
        cout << "Present..!" << "\n"; 
    }
    else{
        cout << "Not Present..!" << "\n";
    }

    // auto it = mp.lower_bound(3); // If key is present then return that point. Not present return then justGreater one. If greater than largest key then points to mp.end()..
    auto it = mp.upper_bound(3); // If key is present (or) Not present return iter to next greater.. If greater than largest key then points to mp.end()..

    if (it != mp.end())
    {
       cout << (*it).first << "\n";
    }
    else
    {
        cout << "No equal (or) Greater value.." << "\n";
    }

    // mp.erase(2);
    // mp.erase(3); // Key is not present in map then ignores.. 
    // mp.erase(mp.find(4));   //  Using iterator..

    mp.erase(mp.find(4), mp.end()); // erase a range in map..
    for (auto &x: mp)    //  Map internal uses Red black tree..
    {
        cout << x.first << " " << x.second << "\n";
    }cout << "\n";


    return 0;
}