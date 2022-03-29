/*
Map in C++ STL  :-
In this, we introduces us to Map in the C++ STL class. It also shows the implementation of the set through
    examples and explains few functions associated with the Map STL class in C++.

**  Map is a container which is similiar to the set and uses Red Black tree Internal..
        ** Set is used to key but the Map used to store the (key,value) pair..
        ** Every item of set is a single object, map is a pair..
        ** Like set which is ordered similiar Map is ordered.. which has (key, value) and ordered as key by default..
        ** This is similiar as set which is increasing order..
        
CPP(insert()+operator[ ]+at()+size())

    map <int, int> m;   //  we can use any data type (or) user defined data type also..

    m.insert({1, 100});     //  we insert in pair as (key, value)..
    m.insert({7, 500});
    m[9] = 200;             //  This another way to insert the item pair to the map..
    m.insert({3, 900});
    m.insert({2, 300});
    m.insert({1, 200});     //  map does not allows dulipcates.. which does not update the key which is present but -> [] will allow..
    m[7] = 100;             //  It will update the value of the pariticular "KEY"/ reference..
    m[5];                   //  It default insert 0 because, we using integer..
                            //  [] -> used for insert/update/create when key is not present in the map.. 

    m.at(5) = 500;          //  similiar to m[5] = 500;
    cout << m.at(1) << endl;    // "at()" uses for accessing the item key in map.. 
                                //  In at().. if the key is not present then it will raises excuation..

    for (auto &x : m){
        cout << x.first << " " << x.second << endl;
    }

    cout << m.size() << endl;
---------------------------------------------------------------->
CPP(begin()+end()+clear()+empty())

    map <int, int> m;   //  we can use any data type (or) user defined data type also..

    m.insert({1, 100});     //  we insert in pair as (key, value)..
    m.insert({7, 500});
    m[9] = 200;             //  This another way to insert the item pair to the map..
    m.insert({3, 900});
    m.insert({2, 300});
    m[4];
    m.at(4) = 200;

    // map <int, int>:: iterator it;        // In place of "auto" ..
    for (auto it = m.begin(); it != m.end(); it++){
        cout << (*it).first << " " << (*it).second << endl; 
    }
    //  We can also use rbegin(), rend(), cbeign(), cend(), crbegin(), crend();
    
    cout << m.size() << endl;
    m.clear();

    cout << (m.empty()? "Yes" :"No") << endl;

-------------------------------------------------------------------->
CPP(find()+count()+lower_bound())

                                        //  greater <int> which reverse the order in decreasing way..
    map <int, string, greater<int>>m;   //  we can use any data type (or) user defined data type also..

    m.insert({1, "gfg"});
    m.insert({2, "uday"});
    m.insert({3, "coding"});

    if (m.find(3) != m.end()){          //  It return iterator having that record.. else return m.end()..
        cout << "Found..!" << endl;     //  We can only call the "key" not value in find()..
    }
    else{
        cout << "Not Found..!" << endl;
    }

    for (auto it = m.find(3); it != m.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }

    if (m.count(4) == 0){       //  Map doesn't allows duplicates so, count which return 0 or 1 because it return type as size..
        cout << "Not Found..!" << endl;
    }
    else {
        cout << "Found..!" << endl;
    }

    //  lower bound :-  takes the key, if the key is present it return iterator, pointing the key..
                                // else if key is not present then return just "next iterator", pointing the key..
                                //  else if key is greater than largest item, then return not in range..
    
    auto it = m.lower_bound(0); //  order is reverse because we used greater <int>..
    if (it != m.end()){
        cout << (*it).first << " " << (*it).second <<  endl;
    }
    else {
        cout << "No equal (or) Greater value..!" << endl;
    }

---------------------------------------------------------------------->
CPP(upper_bound()+erase())

map <int, string>m;   //  we can use any data type (or) user defined data type also..

    m.insert({1, "gfg"});
    m.insert({2, "uday"});
    m.insert({3, "coding"});
    
    //  upper bound :-  takes the key, if the key is present then return next iterator comes to the key..
                                    // else if key is not present then also return next iterator comes the key..
                                    // else if key is greater than largest key then return "No range"..
    auto it = m.upper_bound(0);
    if (it != m.end()){
        cout << (*it).first << " " << (*it).second << endl;
    }
    else {
        cout << "No greater value" << endl;
    }               //  try using reverse order as using greater <int> ..


    cout << m.size() << endl;
    m.erase(1);
    cout << m.size() << endl;       //  We can also use iterator as input to the erase()..

    auto it2 = m.find(2);
    m.erase(it2);
    cout << m.size() << endl;
    //  We can pass begin and end iterator to the erase()..

    // auto it = m.find(3);
    // m.erase(m.find(3), m.end());

    m.erase(m.begin(), m.end());    
    cout << (m.empty()?"Yes":"No") << endl;


*/ 

#include<bits/stdc++.h>
#include<map>
using namespace std;

int32_t main(){
                                        
    map <int, string>m;   //  we can use any data type (or) user defined data type also..

    m.insert({1, "gfg"});
    m.insert({2, "uday"});
    m.insert({3, "coding"});

    m.clear();
    cout << (m.empty()?"YES" : "NO");
    return 0;
}

/*
        Time Complexity and Internal working :-

    ** In Map,  keys are used to order the Red Black tree..
    ** Map, set are similiar in time complexity..

    begin(), end(), 
    rbegin(), rend(),
    cbegin(), cend(),           -> O(1)..
    crbegin(), crend(),
    size() , empty(),


    count(), find(),erase(key),
    insert(), [], at()          -> O(Log n)..   Using RBT..


    erase(iterator)             -> On average takes O(1) time..


    Applications :-
        1) Sorted stream of data with (key, value) pair..
        2) Doubly Ended priority queue of items with (key, value) pair..    

*/ 