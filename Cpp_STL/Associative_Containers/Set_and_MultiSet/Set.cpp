#include<bits/stdc++.h>
#include<set>
using namespace std;

int32_t main()
{
    set<int> s; // Internally uses BST..    Red Black Tree..
    // set<int, greater<int>>s;

    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(5);
    s.insert(10);

    // for (int x: s)
    // {
    //     cout << x << " ";
    // }

    // for (auto it = s.begin(); it != s.end(); it++)  //  auto -> set<int>::iterator;
    // {
    //     cout << *(it) << "\n";
    // }

    // auto it = s.find(1);
    // if (it != s.end())
    // {
    //     cout << *(it) << "\n";
    // }
    // else
    // {
    //     cout << "Not Found..!" << "\n";
    // }

    // s.clear();
    // cout << s.empty() << " " << s.size() << "\n";   

    // if (s.count(1))
    // {
    //     cout << "Found..!" << "\n";
    // }
    // else
    // {
    //     cout << "Not Found..!" << "\n";
    // }

    // s.erase(10);
    // for (int x: s)
    // {
    //     cout << x << "\n";
    // }

    // auto it = s.find(10);
    // s.erase(it);
    // s.erase(it, s.end());
    // s.erase(s.begin(), --s.end());
    // s.erase(s.begin(), s.end());

    for (int x: s)
    {
        cout << x << " ";
    }cout << "\n";

    // auto it = s.lower_bound(14);
    // if (it != s.end())
    // {
    //     cout << *(it) << "\n";
    // }
    // else
    // {
    //     cout << "Given element is greater than Largest..!" << "\n";
    // }

    auto it = s.upper_bound(5);
    if (it != s.end())
    {
        cout << *(it) << "\n";
    }
    else
    {
        cout << "Given element is greater than Largest..!" << "\n";
    }

    return 0;
}