// Ref :-  https://cplusplus.com/reference/forward_list/forward_list/
//  Ref2 :- https://www.geeksforgeeks.org/forward-list-c-set-1-introduction-important-functions/

#include <bits/stdc++.h>
#include <forward_list>
using namespace std;

int32_t main()
{
    forward_list <int> l = {10, 15, 20};
    l.push_front(5);
    l.push_front(2);    //  It does copied to the space before first element in the container..
    l.push_front(1);    
            //  Both operations are insert/delete node at "1_st Position"/0_th index.. 
    l.pop_front();
    l.pop_front();
    l.pop_front();

    l.emplace_front(777); // It does similiar to push_front, but in this no-copying operation occurs, it create directly in memory..

    // for (int &i: l)
    // {
    //     cout << i << " ";
    // }

    
    
    //  assign()    :-

    forward_list <int> l2, l3;
    l2.assign({1, 2, 3, 4, 1});     //   which creates the new list and assign 'l2'..
    
    //  remove();
    l2.remove(1);       //  It removes all instance of '1' in the list..

    // l2.assign(6, 10);       // which assign the 'value 10 in list of 6 time'..
    l3.assign(l2.begin(), l2.end());    //  which assign one list to list..

    // for (auto it = l3.begin(); it != l3.end(); it++)    //  it which points to address of the object in the container..
    // {
    //     cout << *(it) << " ";   //  Need to Derefence to access the value..
    // }


    //      insert_after() :-
    forward_list <int> l4 = {1, 2, 3};
    auto it = l4.insert_after(l4.begin(), 5);  // takes iterator as argument and insert an position after that iterator the val.. 
                        //  and points iterator to it.. or newly inserted node.. 
    it = l4.insert_after(it, {4, 7, 9});    
    

    //    emplace_after() :- similiar to insert_after but, doesn't create any copy of assign & val..
    it = l4.emplace_after(it, 111);
    // for (int &i: l4)
    // {
    //     cout << i << " ";
    // }cout << "\n";

    //  erase_after() :-    erase item after which "it" pointing after.. now "it" points to next of deleted_item..
    it = l4.erase_after(it);
    
    // for (int &i: l4)
    // {
    //     cout << i << " ";
    // }cout << "\n";

    it = l4.erase_after(l4.begin(), l4.end());  //  erase a range of items..

    // for (int &i: l4)
    // {
    //     cout << i << " ";
    // }cout << "\n";

    forward_list<int> l5;   //  remove_if :- This function removes according to the condition in its argument. 
    l5.assign({10, 20, 30, 25, 15, 40, 5});
    l5.remove_if([](int x)
    {
        return x > 20;
    });
    
    for (int i: l5)
    {
        cout << i << " ";
    }

    //  clear() :- deletes all the elements from the list. 
    l5.clear();

    //  empty() :- check is list is empty or not..
    //  reverse() :- reverse the order of list..
    //  merge() :-  merge the l1 and l2 into l1.. does in-place merging..
    //  sort() :- sort the list..

    return 0;
}