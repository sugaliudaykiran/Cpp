/*

Set in C++ STL  :-  "Set used to store the sorted data.. which return sorted data."

In this, introduces us to Set in the C++ STL class. It also shows the implementation of the set
     through examples and explains few functions associated with the Set STL class in C++.


CPP(insert()+begin()+end())

    set <int> s;        // object "s" of set class.

    s.insert(5);
    s.insert(20);
    s.insert(7);
    s.insert(1);

    for (int x : s){
        cout << x << " ";
    }cout << endl;

    for (auto it: s){               
        cout << it << " ";
    }cout << endl;

    for (auto it = s.begin(); it != s.end(); it++){     //  auto :- set <int> :: iterator;
        cout << *it << " ";
    }cout << endl;

___________________________________________________________________>

CPP(rbegin()+rend()+find()+clear())

    //  Decreasing Order :-
    set <int, greater <int>> s;     //  Which used to reverse the sorted order..
    s.insert(5);
    s.insert(11);
    s.insert(1);
    s.insert(20);

    for (int x: s){
        cout << x << " ";
    }cout << endl;

    for (auto it = s.begin(); it != s.end(); it++){
        cout << (*it) << " ";
    }cout << endl;

    //  Reverse using rbegin(), rend();
    for (auto it = s.rbegin(); it != s.rend(); it++){
        cout << (*it) << " ";
    }cout << endl;


    set <int> s;

    s.insert(10);
    s.insert(15);
    s.insert(1);
    s.insert(30);   //  set doesn't allow the duplicate item..
    s.insert(15);   //  Duplicate are automatical removed in the set..
    s.insert(1);
                            //  find().. used to find the iterator pointing to the item.
    auto it = s.find(10);   // "it" is an iterator..

    if (it == s.end()){
        cout << "Not Found..!" << endl;
    }
    else {
        cout << "Found..!" << endl;
    }

    while (it != s.end()){  //  print item from "it" to end.
        cout << *it++ << " ";   //  *it -> referening the item.
    }cout << endl;

    //      Clear()     :- used to clear the entire set..

    s.clear();
    if (s.size() == 0){
        cout << "Set is Clear.." << endl;
    }

_____________________________________________________________________>
CPP(count()+erase())

    set <int> s;

    s.insert(5);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    s.insert(1);    //  set does not allows duplicates..

    if (s.count(1)){     // count which return 1 or 0 because set has unique items.
        cout << "Item is present..!" << endl;
    }
    else {
        cout << "Not present..!" << endl;
    }
    
    s.erase(1);     //  which erase item from the set.. which will erase stream of items..
    cout << s.count(1) << endl;      

    //       by get iterator using find() and erase form "it to end of set"..
    auto it = s.find(2);

    s.erase(it, s.end());   
    cout << s.size() << endl;

    s.erase(s.begin(), s.end());    //  erase can be used to erase entire set..
    cout << s.size() << endl;

_________________________________________________________>

CPP(lower_bound()+upper_bound())

    lower_bound() :- Here is a member of the set class. where as in vector/array it is used as method which take parameter as v/a..
        
        How it work ?   =>  auto it = lower_bound(5);
            1) It gives the iterator to the element if it is present in set.
            2) If it doesn't present then it return element "just greater the element"..
            3) If the element we are searching greater than largest element then "it" points to the end() of set..
    
    set <int> s;

    s.insert(10);
    s.insert(1);
    s.insert(5);
    s.insert(7);
    s.insert(9);
    
    auto it = s.lower_bound(11);
    if (it != s.end()){
        cout << *it << endl;
    }
    else {
        cout << "Given element is greater than the largest..!";
    }


    upper_bound()   :-  It is also member function of the set.
        1) If we pass an element to the iterator then it return next greater to the element.. (item which is present the set..)
        2) If the element is not present then also it return the next greater element..
        3) Else if the element is greater than the largest element then it points to set.end()..
 
    set <int> s;

    s.insert(10);
    s.insert(1);
    s.insert(5);
    s.insert(7);
    s.insert(9);
    
    auto it = s.upper_bound(1);
    if (it != s.end()){
        cout << *it << endl;
    }
    else {
        cout << "Given element is greater than the largest..!";
    }
*/

#include<bits/stdc++.h>
#include<set>
using namespace std;

struct test{
    int x;  //  member 
    bool operator<(const test &t) const{
        // return (this -> x < t.x);   //  Increasing order ..
        return (this -> x > t.x);   //  Decreasing order ..
    }                               
};

int32_t main(){
                        //  set for user defined data type..
    set <test> s;       //  test type set..

    s.insert({10});
    s.insert({3});
    s.insert({5});

    for (test t: s){
        cout << t.x << " ";
    }cout << endl;

    return 0;
}

/*

        Internally working and Time complexity of the set...
            set which works on bases of Self balancing BST (RED - BLACK TREE)..
    ** Insert/delete of red-black tree is O(Log h).. h is O(n)..
    ** Items which are inserted to the set are returns the sorted order..

    ** begin(), end(),              
        rebegin, rend(),        
        cbegin(), cend(),               ->              O(1)
        crbegin(), crend(),
        size(), empty()

    ** insert(), find(), 
        count(), lower_bound(),         ->              O(Log n)    // since it is a RBT..
        upper_bound(), erase(val) 

    ** erase(iterator)                  ->              Amortized O(1)  // If we know the address of the element then it takes O(1).


Applications of the set :-
    1) Sorted Stream of Data,   // We have un-order elements we need to sort the items.. then we use 'set'.
    2) Doubly Ended Priority Queue.     //  We can implement both Max and Min heap.. in O(1)..


*/ 