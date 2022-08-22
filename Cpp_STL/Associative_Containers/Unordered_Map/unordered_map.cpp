#include<bits/stdc++.h>
#include<unordered_map> //  Used to store key,value pairs..
using namespace std;    //  Uses 'Hashing'.. and No order of Key..
                        //  Insert, search, delete in O(1)..
int32_t main()
{
    unordered_map <string, int> mp;
    mp["gfg"] = 20;
    mp["ide"] = 15;   //    mp[key] -> member access operator.. used to insert if key is present (or) assign key if not present with default value '0'..
    mp.insert({"course", 30}); //  Inserting items into 'mp'
    mp.insert({"uday", 13});

    // for (auto x: mp)    // Has No Order.. in Hashing. 
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }

    
    
    // if (mp.find("uday") != mp.end()) // If Key is present in map, return address pointing to that key address..
    // {
    //     cout << "Found..!" <<" "<< (mp.find("uday"))-> second <<  "\n";
    // }
    
    auto it = mp.find("gfg");   //  Using Iterator..
    if (it != mp.end())
    {
        cout << "Found..!" << " " << (*it).second << "\n"; 
    }else{   //  If Not present in map then points to mp.end()..
        cout << "Not Found..!" << "\n";
    }
 
    
    mp.at("ide") = 100;  // at() is used to access the key's val and modifing purposes..
    cout << mp.at("ide") << "\n"; 

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << " " << it -> second << "\n";
    }


    if (mp.count("gfg") == 1) // Used for searching the key in the map similiar to find()..
    {                           //  But return '1' is key is present.. '0' if key is not present..
        cout << "Found..!" << "\n";
    }else{
        cout << "No Found..!" << "\n";
    }

    cout << mp.size() << "\n";
    mp.erase("ide");
    
    auto it2 = mp.find("gfg");  
    mp.erase(it2);

    // mp.erase(it, mp.end()); // erase a range of items..
    // mp.erase(mp.begin(), mp.end()); // erase enterly..
    cout << mp.size() << "\n";

    return 0;
} // count(), find(), at(), [], erase(key), insert() in O(1).. on average..

