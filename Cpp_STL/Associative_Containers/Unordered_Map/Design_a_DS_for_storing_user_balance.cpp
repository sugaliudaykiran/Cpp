#include<bits/stdc++.h>
#include<unordered_map> 
using namespace std;


unordered_map <int, int> mp;

void Set2(int id, int bal) // TC -> O(1)..
{
    mp[id] = bal;
}

int get2(int id)  // TC -> O(1)..
{
    return mp[id];
}


vector <pair <int, int>> v;  // TC -> O(n).. 

void Set(int id, int bal) // id, balance
{ 
    for (auto &i: v)
    {
        if (i.first == id)
        {
            i.second = bal;
            return;
        }
    }
    v.push_back({id, bal});
}

int get(int id)
{               // TC -> O(n).. 
    for (auto i: v)
    {
        if (i.first == id)
        {
            return i.second;
        }
    }
    return -1;
}

int32_t main()
{
    // Need to create get(), set()..
    Set2(1, 100);
    Set2(2, 200);
    Set2(3, 400);
    cout << get2(1) << " " << get2(2) << "\n";

    Set2(1, 500);
    Set2(2, 100);
    cout << get2(1)  << " " << get2(2) << "\n";
    
    return 0;
}