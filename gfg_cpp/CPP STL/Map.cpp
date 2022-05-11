/*              Containers Ref :- https://www.geeksforgeeks.org/containers-cpp-stl/


Map :-      Very common use-case:   Count frequency of various Objects..
    Maps are associative containers that store elements in a mapped fashion. 
        Each element has a key value and a mapped value. 
        No two mapped values can have the same key values.

    Ref :- https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
    Ref2 :- https://www.cplusplus.com/reference/map/map/

    Some basic functions associated with Map: 

        begin() – Returns an iterator to the first element in the map.
        end() – Returns an iterator to the theoretical element that follows the last element in the map.
        size() – Returns the number of elements in the map.
        max_size() – Returns the maximum number of elements that the map can hold.
        empty() – Returns whether the map is empty.
        pair insert(keyvalue, mapvalue) – Adds a new element to the map.
        erase(iterator position) – Removes the element at the position pointed by the iterator.
        erase(const g)– Removes the key-value ‘g’ from the map.
        clear() – Removes all the elements from the map.
---------------------->

Map :-      Very common use-case:   'Count frequency of various Objects'..
        You can think of these as special arrays in which the indices(keys) of elements 
            can be negative or very big or even strings!    It's similiar as dictionaries..
    
    map <key_datatype, value_datatype> m;
    map <string, int> m;        //  defines a map in which the keys of elements are strings..

Note :- Maps are very similiar to sets, in sets the values are unique and sorted, in map the keys are unique and sorted..

    Now, we can use it like:     
        m["hello"] = 10;
        m["world"] = 20;
    cout << m["hello"] << " " << m["world"];    //      10   20

    map<int, int> m;
    m[-234] = 10;   //  negative ints are valid as keys..

--------->
    m.clear()       -> clears a map.
    m[key]          -> value of element with key.   O(Log N)
    m.count(key), m.find(key), m.erase(key),
    m.lower_bound(key), m.upper_bound(key),.     similiar to set.

    Map iterators behave similiar to set iterators, but upon doing *it you instead of
         getting the value, you get a pair of {key, value}

    Examples :-
        map<string, double> m;              //  BONUS :-    (*it).first and (*it).second can instead be written as it->first, it->second;
        //  insert values in map..
        auto it = m.find("uday");
        pair <string, double> p = *it;  //  {"uday", m["uday"]}

map <int, int> m;           //  For storing the val and it's frequency..
    cout << m.size() << endl;

    cout << m[10] << endl;  //  If element is not present. map instanly create the element and the value will be 0.
    m[11];  m[12];  m[13] = 2;
    cout << m.size() << endl;
    
    m[10]++;
    cout << m[10] << endl;  //  It will return inorder of pair. so we need to store in pair form.

--------------->

N = 4;
    "abacaba"
    "acaba"
    "abacaba"
    "acab"

O/p :-  
        OK
        OK
    "abacaba1"
        OK

N = 3;
    "abc"
    "bac"
    "abc"

O/p :-  
        OK
        OK
      "abc1"
*/ 

#include<bits/stdc++.h>
using namespace std;

int32_t main()
{   
    //  CodeForce C.Registration System :-

    map <string, int> freq;

    int n;
    cin >> n;

    for (int i=0; i<n; i++)
    {
        string s;
        cin >> s;

        if (freq[s] == 0)
        {
            cout << "OK\n";
        }
        else
        {
            cout << s << freq[s] << "\n";
        }
        freq[s]++;
    }
    
    return 0;
}
