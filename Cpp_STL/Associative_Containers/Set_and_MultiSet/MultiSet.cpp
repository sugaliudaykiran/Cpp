#include<bits/stdc++.h>
#include<set>   // Ref :- https://www.geeksforgeeks.org/multiset-in-cpp-stl/
using namespace std;



int32_t main()
{
    multiset <int> ms;
    ms.insert(10);
    ms.insert(20);
    ms.insert(30);
    ms.insert(10);

    for (auto x : ms)
    {
        cout << x << " ";
    }cout << "\n";

    // ms.erase(10);   //  Removes all instance of "10"..
    
    // auto it = ms.find(10);
    // ms.erase(it);   //  Removes the given position of iterator..

    // ms.erase(it, --ms.end());   //  Removes the range of elements..

    // for (auto x: ms)
    // {
    //     cout << x << " ";
    // }cout << "\n";

    // cout << ms.count(10) << " " << ms.count(20) << "\n"; // count no of instance of 'x'

    auto it1 = ms.lower_bound(5);  // lower_bound is member function of muliset.
    cout << *(it1) << "\n";      // If element is not present then return iter to Just_Greater element..
                             // If element is present, then return iter to that present element.
                            //  If element is greater than greater element then return iter to ms.end()..

    it1 = ms.upper_bound(10);// Upper_bound is member function of muliset.
    cout << *(it1) << "\n";      // If element is not present then return iter to Just_Greater element..
                             // If element is present, then return iter to Just_Greater element.
                            //  If element is greater than greater element then return iter to ms.end()..

    auto it = ms.equal_range(10); // return a pair of iterator..
    cout << *(it).first << " " << *(it).second << "\n"; //  iter.first return to lower_bound() and iter.second return iter to upper_bound() of iter...
    
    return 0;
}

