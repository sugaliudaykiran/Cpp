#include<bits/stdc++.h>
#include<unordered_set> // Which works only on keys..
using namespace std;

int32_t main()
{
    unordered_set <int> s; // unordered_set is based on Hashing..
    s.insert(10);  // insert, search, delete takes O(1).. on average..
    s.insert(5);    //  In hashing, items are uniformly distributed..
    s.insert(11);
    s.insert(1);

    // for (int x: s)
    // {
    //     cout << x << " ";
    // }cout << "\n";

    for (auto it=s.begin(); it != s.end(); it++)
    {
        cout << *(it) << " ";
    }cout << "\n";
    
    // cout << s.size() << "\n";
    
    // s.clear(); 
    cout << s.size() << "\n";
    
    if (s.find(12) != s.end())
    {
        cout << "Found..!" << " " << *(s.find(12)) << "\n";
    }
    else{
        cout << "Not Found..!" << "\n";
    }

    if (s.count(5) == 1)
    {
        cout << "Found..!" << "\n";
    }
    else{
        cout << "Not Found..!" << "\n";
    }

    // s.erase(10);

    // auto it = s.find(10);
    // s.erase(it);

    s.erase(s.begin(), s.end());    //  Takes O(n).. 
    cout << s.size() << "\n";

    return 0;
}
