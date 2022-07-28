#include<bits/stdc++.h>
#include<list>
using namespace std;

int32_t main()
{

    list <int> l;   //  'list' is an doubly LL, has head, tail pointer.. insert/deletion can done both ends..

    l.push_back(10);    //  push's at end.. of the list.
    l.push_back(20);     
    l.push_front(5);    //  push's at front.. of the list.

    l.pop_back();   //  pop's at back of the list..
    l.pop_front();  //  pop's at front of the list..

    // for (int x: l)
    // {
    //     cout << x << " ";
    // }cout << "\n";


    list <int> l2 = {10, 2, 30};
    auto it = l2.begin();   

    it++;
    it = l.insert(it, 99);  //  takes iterator as argument, insert the item at the address of it..
                                    //   and return address pointing next to it..
    l.insert(it, 4, 1); //  here it does inserting a frequency of items to the list..

    // cout << l2.front() << " " << l2.back() << "\n";

    // cout << l2.size() << "\n";

    // for (auto it= l2.begin(); it!= l2.end(); it++)
    // {
    //     cout << *(it) << " ";
    // }


    list <int> l3 = {10, 20, 30, 40, 20, 40};
    it = l3.begin();

    it = l3.erase(it); // remove the address of "it" is pointing..
    l3.remove(40);  //  remove "all occurances" of 40 in l3..

    // for (int x: l3)
    // {
    //     cout << x << " ";
    // }

    list <int> l4 = {1, 2, 3};
    list <int> l5 = {5, 6, 7};

    l4.merge(l5);   //  merge one list to another list, another list becomes empty list.. does in-place..

    // for(int x: l4)
    // {
    //     cout << x << " ";
    // }


    list <int> l6 = {1, 2, 2, 3, 3, 4, 4, 4, 1};
    l6.unique();    //  remove only all conscutive items..

    for (int x: l6)
    {
        cout << x << " ";
    }cout << "\n";

    l6.sort();   //  sort the order of list..
    l6.reverse();   //  reverse the order of the list..

    for (int x: l6)
    {
        cout << x << " ";
    }cout << "\n";


    return 0;
}