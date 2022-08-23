#include<bits/stdc++.h>
#include<algorithm>
using namespace std;    //  TC -> O(Logn).. For Random access container..only like vector, array.
    //  Upper_bound(Begin, End, X) -> Internally uses Binary Search..
    //      Returns an Iterator points next greater element to X.. in case of X is present and not present..
                // Else pointing to end()..
    //  Map, Set, Unordered_Map, Unordered_Set, String -> Has memeber function upper_bound() which work effectively.. 
        //  Internally uses " advances() " or Forward Iteration..
    
    //  By using Both lower_bound() and upper_bound() we can find all the occurances of element.. 
    
int32_t main()
{  // Used to find last occurance of element..
    vector <int> v = {1, 5, 7, 11, 21};  // Vector need to be non-decreasing order..
    auto it = upper_bound(v.begin(), v.end(), 7); 
    if (it != v.end())
    {
        cout << *(it) <<" "<< it - v.begin() <<   "\n";
    }
    else{
        cout << "Out of Range" << "\n";
    }

    
    int n = 5;
    int ar[5] = {10, 2, 7, 11, 21};
    int *ptr = upper_bound(ar, ar+n, 7);
    if (ptr != ar+n)
    {
        cout << *(ptr) << " " << ptr - ar << "\n";
    }
    else{
        cout << "Out of Range" << "\n";
    }

    //  Finding X=21 is present in the container or not..
    if (ptr != ar && *(ptr - 1) == 7)
    {
        cout <<  "Found.." <<" "<< ((ptr-1) - ar) <<  "\n";
    }
    else{
        cout << "Not Found.." << "\n";
    }

    return 0;
}