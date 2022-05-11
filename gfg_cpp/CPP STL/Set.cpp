/*

    Set :-
        Sets are a type of associative containers in which each element has to be unique because 
            the value of the element identifies it. The values are stored in a specific order. 
Syntax:
    set<datatype> setname;
    Datatype: Set can take any data type depending on the values, e.g. int, char, float, etc.

Example:
    set<int> val; // defining an empty set
    set<int> val = {6, 10, 5, 1}; // defining a set with values

Note: set<datatype, greater<datatype>> setname; is used for storing values in a set in descending order.

    Ref :-  https://www.geeksforgeeks.org/set-in-cpp-stl/


Properties:
    The set stores the elements in sorted order.
    All the elements in a set have unique values.
    The value of the element cannot be modified once it is added to the set, though it is possible to remove and then add the modified value of that element. Thus, the values are immutable.
    Sets follow the Binary search tree implementation.
    The values in a set are unindexed.
    Note: To store the elements in an unsorted(random) order,  unordered_set() can be used.

Some Basic Functions Associated with Set: 
    begin() – Returns an iterator to the first element in the set.
    end() – Returns an iterator to the theoretical element that follows the last element in the set.
    size() – Returns the number of elements in the set.
    max_size() – Returns the maximum number of elements that the set can hold.
    empty() – Returns whether the set is empty.


Set is a container which keeps a unqiue copy of every elements in sorted order.
    set <int> s;        //  empty set of integers..
    set <string> s;     //  empty set of strings..

    Important Functions :-
        s.insert(X)       --> insert the value X into set, do nothing if already present.   TC -> O(logN)..
        s.erase(X)        --> erase the value X from set, if present.   O(log N)..
        s.count(X)        --> return 0 if X is not in set, if X is present in set return 1..    O(log N)..
        s.clear()         --> erase all elements.   O(n)..
        s.size()          --> returns the current size of the set.      O(1)..

Note :-
            cout << s[0];   //  [] operator doesn't works with set.. because random access is not supported in set.

    
    set <int> s;
    
    s.insert(10);   s.insert(12);   s.insert(9);    s.insert(11);

    cout << s.count(11) << "\n";
    s.erase(11);
    cout << s.count(11) << endl;    

------------------->

Set iterators   :-  
        Set iterators offers less features than vector iterators.
        auto it = s.begin();    //  It is the iterator to the first element
    it++, ++it, it--, --it; //  These are all valid and work in O(log N) time..
         because it follows RED-BLACK Algo which takes O(logN) in each operation.

NOTE :  (it + 5) or it += 2 etc are INVALID.. To advance multiple steps, do it++ multiple times..

    Functions related to set iterators  :-
        s.find(X)   -> returns iterator to element with value X. Returns s.end() if not found.  O(logN)
        s.lower_bound(X)    -> returns iterator to the first element which is >= X. Returns s.end() if not found.   O(logN)
        s.upper_bound(X)    -> returns iterator to the first element which is > X (Just greater one). Returns s.end() if not found. O(logN)
        s.erase(X)  -> erases the element with iterator it. O(logN)

    Both of the next 2 lines are exactly same..
        if (s.find(10) == s.end())
            cout << "Not Found";
        if (s.count(10) == 0)
            cout << "Not Found";

*/ 

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    set <int> s;
    
    s.insert(10);   s.insert(12);   s.insert(9);    s.insert(11);

    cout << *s.begin() << "\n";

    s.erase(s.begin());         //  At every movement 'set' keeps the elements in sorted order..
    cout << *s.begin() << "\n";

    s.insert(9);
    auto it = s.begin();
    for (; it != s.end(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}

