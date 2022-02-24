// Implement chaining in case of occurrence of a collision  :=

#include<bits/stdc++.h>         // Hashing with Chaining..
using namespace std;

struct Myhash{
    int BUCKET;         // For Declare the Value as BUCKET..
    list <int> *table;      // It is array of Linked list where " List class used to implement Double Linked list.."
    Myhash(int b){  
        BUCKET = b;                     // here we b is Bucket size..
        table = new list <int> [b];    //  table which creates new list with size b..
    }

    void insert(int key){       
        int i = key % BUCKET;       // Here on i th Position in Linked list we insert the Key..
        table[i].push_back(key); 
    }

    void remove(int key){
        int i = key % BUCKET;       //  Here on i th Position in Linked list we remove the Key..
        table[i].remove(key);
    }

    bool search(int key){
        int i = key % BUCKET;       
        for (auto s: table[i]){                 // Here we return true if key is exist and false if not..
            if (s == key){
                return true;
            }
            return false;
        }
    }

};

int32_t main(){

    Myhash mh(7);   //      Myhash -> Calling the Constructor.. 
    mh.insert(10);  //         mh(7) -> mh short_name with size..
    mh.insert(15);
    mh.insert(20);
    mh.insert(25);

    cout << mh.search(15) << endl;   // result is 1;
    mh.remove(15);
    cout << mh.search(15) << endl;   // result is 0; it does not exists..

    return 0;
}

/*
    ** unordered_map in C++ STL **   -> https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/

    #include<bits/stdc++.h>
    #include<unordered_map>
    using namespace std;

    int32_t main(){

        unordered_map <string, int> umap;       // Here Declaring the unordered_map.. key is only in string and value can be int or bouble..

        umap["aa"] = 10;
        umap["bb"] = 20;
        umap["cc"] = 30;

        for (auto s: umap){
            cout << s.first << " " << s.secound << endl;    // Here first will print key which "aa"
                                                            // and secound will print int value..
        }
        return 0;
    }


*/