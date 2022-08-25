#include<bits/stdc++.h>
#include<algorithm> 
using namespace std;    //  TC -> 0(n).. Linear time..
    
int32_t main()  //  rotate() does Increment the Iterator, which moves forward direction..
{                         // forward container like vector, array, string, dequeue, forward_list.

    vector <int> v = {5, 1, 7, 10, 20};
    // rotate(v.begin(), v.begin()+2 ,v.end());
    rotate(v.begin()+1, v.begin()+2 ,v.end());
    // rotate(v.rbegin(), v.rbegin()+2 ,v.rend());
    for (auto x: v)
    {
        cout << x << " ";
    }cout << "\n";


    int ar[] = {12, 9, 10, 4, 3};
    rotate(ar, ar+2 , ar+5);
    for (int x: ar)
    {
        cout << x << " ";
    }cout << "\n";


    return 0;
}