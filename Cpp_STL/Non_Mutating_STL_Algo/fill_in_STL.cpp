#include<bits/stdc++.h>
#include<algorithm> 
using namespace std;    //  TC -> O(n).. Linear time..
    
int32_t main() // fill() can be used also forward_list, dequeue..
{
    vector <int> v = {5, 10, 7, 10, 20};
    // fill(v.begin(), v.end(), 1);
    fill(v.begin()+1, v.end()-1, 1);
    for (auto x: v)
    {
        cout << x << " ";
    }cout << "\n";


    int ar[] = {11, 21, 33, 8, 7};
    // fill(ar, ar+5, -1);
    fill(ar+1, ar+4, -1);
    for (int x: ar)
    {
        cout << x << " ";
    }cout << "\n";

    
    list <int> l = {2, 1, 7, 3, 9};
    fill(l.begin(), l.end(), 0);
    // fill(l.begin()+1, l.end()-1, 0); // Because Random access is not possible.. in Doubly LL..
    for (auto x: l)
    {
        cout << x << " ";
    }cout << "\n";

    
    string s = "geeks";
    fill(s.begin()+1, s.end()-1, 'g');
    cout << s << "\n";

    
    vector <int> v2 = {1, 2, 1};
    fill(v2.begin(), v2.end()+2, 1); // fill() does only change to values that exists in the container..
    for (int x: v2)
    {
        cout << x << " ";
    }cout << "\n";

    return 0;
}