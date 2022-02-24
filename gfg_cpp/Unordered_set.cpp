/* Unordered_set in C++ STL :=
        
    along with various functions involved in the unordered_set like:

insert()
begin()
end()
size()
clear()
find()

*/

#include<bits/stdc++.h>         // Ordered_set works on Red-Black Tree..
#include<unordered_set>         // Uses Hashing and Used in only "Keys operations"..
using namespace std;

int32_t main(){

    // insert()
    unordered_set <int> s;
    s.insert(5);
    s.insert(10);
    s.insert(15);

    for (int x: s){
        cout << x << " ";
    }cout << endl;

    // begin(), end(), size(), clear()
    for (auto it = s.begin(); it != s.end(); it++){
        cout << (*it) << " ";
    }cout << endl;

    cout << s.size() << endl;

    // s.clear();
    // cout << s.size() << endl;

    // find(), count()
    if (s.find(15) == s.end()){
        cout << "Not Found.." << endl;
    }
    else{
        cout << "Found.." << endl;
    }

    if (s.count(10)){
        cout << "Present" <<" "<< s.count(10) <<endl;   // "1" means present and "0" means not present..
    }
    else{
        cout << "Not Present" << endl;
    }

    // erase()
    s.erase(10);

    for(int x: s){
        cout << x << " ";
    }cout << endl;

    auto it = s.find(15);
    s.erase(it);
    
    for(int c: s){
        cout << c << " ";
    }cout << endl;

    s.erase(s.begin(), s.end());
    cout << s.size() <<" - size after erase.."<< endl;

    s.insert(10);
    s.insert(15);
    s.insert(5);

    for(int x: s){
        cout << x << " ";
    }cout << endl;

    return 0;
}

/*
    Internal working and Time Complexities :=
    
        begin(), end(), cbegin(), cend()      -->     O(1)

        insert(), erase(it), erase(), find(), count()   -->  O(1) on average..

        size(), empty()     -->  O(1)

    Applications :=

        we can use anywhere when,
        we need following operations or a subset of following {Operations quickly} :=
            |-> Search, Insert, Delete 


*/