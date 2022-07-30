#include<bits/stdc++.h>
#include<deque>
using namespace std;


int32_t main()
{
    deque <int> dq = {10, 20, 30};
    dq.push_back(50);
    dq.push_front(5);
    // for (auto &x: dq)
    // {
    //     cout << x << " ";
    // }cout << "\n";
    
    // cout << dq.front() << " " << dq.back() << "\n";

    deque <int> dq1 = {10, 15, 30, 5, 12};
    auto it = dq1.begin();
    it++;

    dq1.insert(it, 20);
    dq1.pop_back();
    dq1.pop_front();

    for (it = dq1.begin(); it != dq1.end(); it++)
    {
        cout << *(it) << " ";
    }cout << "\n";

    cout << dq1.size() << "\n";

    cout << dq1[3] << "\n";     //  Indexing..
}