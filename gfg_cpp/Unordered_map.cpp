/*

    Unordered_map in C++ STL how can it be implemented :=
        |-> Used to store (key, value) pairs 
        |-> Uses Hashing 
        |-> No order of keys

    ordered_map uses Red-blood tree and follows order keys..


*/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int32_t main(){
    //  declaring unordered_map
    unordered_map <string, int> um;     // unordered_map <key, value> map_name

    um["gfg"] = 10;             // it creates new one if it is new one (or) existing value reference/ assign ..
    um["javatpoint"] = 15;
    um["w_3school"] = 20;
    
    // insert()
    um.insert({"youtube", 30});     //      insert({key, value})

    for (auto s: um){               //      auto from initial value of unordered_map
        cout << s.first << " " << s.second << endl;     // s.first   -> gets key of iterator
    }                                                   // s.secound -> gets value of iterator
    
    //  find()
    if (um.find("gfg") == um.end()){            // for finding and uses key.. 
        cout << "Not Found.." << endl;          // it actually return an iterator which is pointing to that record..
    }
    else {
        cout << "Found.." << endl;
    }

    // Finding Value for corresponding to the key..
    auto its = um.find("gfg");
    if (its != um.end()){
        cout << its-> second <<" "<< its-> first << endl;
    }
    // at -> function will also return reference of value when is present..

    for (auto it = um.begin(); it != um.end(); it++){
        cout << it-> first << " " << it-> second << endl;
    }

    // count()
    if (um.count("w_3school")){     // if (um.count("w_3school") > 0){}
        cout << "Found.." << endl;
    }
    else{
        cout << "Not Found.." << endl;
    }

    // size(), erase()
    cout << um.size() << endl;

    // erase("key")..   particular (key, value) pair..
    um.erase("gfg");
    cout << um.count("gfg") << endl;

    // erase(a particular begining of map)..
    um.erase(um.begin()); 

    // erase entire map..
    um.erase(um.begin(), um.end());

    cout << um.size() << endl;

    return 0;
}

/*
        Time Complexity :=
                ____
        begin()    |
        end()      |        -->   O(1) in Worst case..
        size()     |
        empty()    |
                ____
                _____
        count()     |
        find()      |
        erase(key)  |       -->  O(1) on Average..
        insert()    |
        []          |
        at          |
                ______





 * /