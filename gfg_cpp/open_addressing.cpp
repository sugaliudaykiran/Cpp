/*
    Open Addressing := 
            which is another way of handling Collision in Hashing.
            Idea is using single array.. and does not required any linked array..

        Requirement :=
           * No of slots in Hash table >= No of keys to be inserted..
        ** It is an Cache Friendly..

        This can apply in "3" differnet ways :-
            They are :-
                1) Linear Pobing,
                2) Quadratic Probing,
                3) Double Hashing..
        
        Linear Pobing :=
            Linear search for next empty slot when there is collision..
        
            For example :=
                " hash(key) = key % m "         (m is Size of Hash Table..)
                    key like  {50, 51, 49, 16, 56, 15, 19} where m is 7 then..
                _________           
               0|  49   |       -> hash(49) = 49 % 7 -> 0
               1|  50   |       -> hash(50) = 50 % 7 -> 1
               2|  51   |       -> hash(51) = 51 % 7 -> 2
               3|  16   |       -> hash(16) = 16 % 7 -> "2" on this Index there was key and leds to collision so Linear Pobing we check next empty slot and insert it..
               4|  56   |       -> hash(56) = 56 % 7 -> "0" on this Index there was key and leds to collision so Linear Pobing we check next empty slot and insert it..
               5|  15   |       -> hash(15) = 15 % 7 -> "1" on this Index there was key and leds to collision so Linear Pobing we check next empty slot and insert it..
               6|  19   |       -> hash(19) = 19 % 7 -> "5" on this Index there was key and leds to collision so Linear Pobing we check next empty slot and insert it..
                _________

            ** If in any case of last Index was first inserted then we can go circular way searching for the Empty slot..
            
            Try this {48, 42, 50, 55, 53} where m is 7..
                    " hash(key) = key % m "

        Above we done how to Insert using Linear Pobing and now try to Search and Delete the Key in Hash table..
            ** Search(key) :-
                |->  Here we usually search the Key using the hash function 
                |->  If the Key is found at it particular Index then return true..
                |->  Else if any another Key is found and then follow Conditions :-
                |->  Conditions where we stop :=
                        |-> If Key is Found on Linear search and return true..
                        |-> If any Empty slot is Found in Sequency search Order and return false..
                        |-> {Traverse through complete table} 
                                If all slots are filled and we start search from begin slot to an cycle search 
                                reached to begin slot then we stop search and return false;
                
            ** Delete(key) :-
                Problem with simply making slot empty when we delete :-
                    |-> If one slot is found and deleted then we again to search the Key which present below the Deleted slot 
                    |-> Then we cannot search because of empty slot in linear search..
                    |-> "TO OVER IT " we use keep the deleted key as the deleted slot in case of empty 
                    |-> By this we doesn't need to stop when saw an deleted slot and here we can search and can Insert the key in this deleted slot..

        Problem in Open Addressing :=
            "Clusting"  {A problem in linear pobing} :-
                |-> Various Keys has an Common slot/Index in Hash table then we linear search for next empty slot..
                        and then it leds to formation of Clusting..
                |-> If the Indexs of Keys{k} is already mapped then cluster size increase to {k+1}..
                |-> It is Costly for Search, Insert and Delete..
        
        Handling the Problem :-
            " hash(key, i) = (h(k) + i) % 7 " 
                |-> h(k) => hash(key) = key % 7;
                |-> where i=1 is pobing index when it forms collision and search next slot then we forms linear clusting..
                |-> Here it forms Primary clusters..
            
            "Quadratic Probing" :-
                |-> hash(key, i) = (h(key) + i_square) % m
                |-> Here we goes in square th slot with respective to "i"
                |-> Here it forms secondary clusters..
                |-> Here drawback is it does not find the empty slot.. 
                |-> and here it should be " Load_factor(alpha) < 0.5 " {No of Slots should be double the keys to be inserted} 
                |-> alpha = n/m (no of slots / no of keys) and m should be prime..

            "Double Hashing" :-     hash(key, i) = (h1(key) + (i *h2(key))) % m

                |-> concept of double hashing where two hash functions are used to perform the hashing operation.
                |-> First hash function is original function and secound hash function for finding next slot for probing.
                |-> If h2(key) is relatively prime to m, then it always find a free slot if there is one.
                |-> No clustering.
                |-> Distributes keys more uniformly than linear probing and quadratic hashing.

                Example :-
                    hash(key, i) = (h1(key) + (i *h2(key))) % m
                        let m = 7.
                        h1(key) = key % 7..    h2 = 6 *(key % 6).       // why 6 means remaining element from after 7 is 6 to zero..
                        
                        keys = {49, 63, 56, 52, 54, 48}..       // when collision happens  let i = 1.. it should not be zero..
                
                Steps :- 1) Here first we check the h1(key), if the result slot is empty then no collision then insert the key.
                         2) When if result slot is filled then we need to check f2 with represtive with m and if any case again result is filled slot.
                         3) Then repeat the hash(key) by increment of i like 1, 2, 3, 4, 5, 6.. in case we can find the empty slot to fill.

                    _________
                0   |  49   |       hash(49) = h1(49) --> 0    // here no collision so i = 0.. 
                1   |       |       hash(63) = h1(63) --> 0    // here  collision happens then ((49 % 7) + 1 *(6 - (49 % 6))) % 7 --> (0 + 3) % 7 -> 3..
                2   |  54   |        try for remaining ..      // follow the Step- 3 if the empty slot is not found..
                3   |  63   |
                4   |  56   |
                5   |  52   |
                6   |  48   |
                    _________

                Why h2(key) and m, should be relatively prime ?
                    (1*6) % 7 = 6   --> HERE it tell to shift by 6 slots to the h1(key).. 
                    (2*6) % 7 = 5   --> HERE it tell to shift by 5 slots to the h1(key)..
                    (3*6) % 7 = 4   --> and soon.. and here 6 and 7 relative which remains 6 to 1 slots for probing..
                    (4*6) % 7 = 3
                    (5*6) % 7 = 2
                    (6*6) % 7 = 1
            
        Program for Insertion using double probing :=

            void double_hash_insert(key){
                if (table is full){
                    return error;
                }
                
                probe = h1(key),  offset = h2(key);     // if offset is 1 then it becomes linear probing..
                
                while(table[probe] is occupied){        // means collision..
                    probe = (probe + offset) % m;
                }
                table[probe] = key;                     // if slot is empty..
            }
        
        Performance Analysis of search :-
            |-> search is simple follow inserting method which if slot is "empty and right key in right slot" then return true..
            |-> else if slot is empty then we follow f2(key) and increament the i'th value..
            
            Unsuccessful search happens when after tranverse of hole table and if slot is empty then
                follows an Assumption..
            
            Assumption :=   Every probe sequence looks at a random location

                alpha = total no. of keys / total no of slots in table.. ==> n/m {should be <= 1 }..
                
                ** Expected no. of probes required = (1/ 1-alpha)
                    |-> where (1- alpha) is a fraction of the table is empty 
                    |-> if alpha is 1 then if will infinite over the empty slot..

*/

// Implementation of Open_Addressing :- using Linear probing

#include<bits/stdc++.h>
using namespace std;

struct MyHash{
    int *ar;                // pointing to arr's starting point
    int cap, size;          // cap is capicity of table/arr size 
    
    MyHash(int c){          // it is an function with parameter is 
        cap = c;            
        size = 0;                   // Initial size of arr occupied is zero..
        ar = new int [cap];          // ar_name = new int [ar_size]..

        for (int i=0; i<cap; i++){  
            ar[i] = -1;                 // consider all slots are -1..  which is empty..
        }
    }

    int hash(int key){
        return key % cap;   // h(k) -> k % m..
    }

    bool search(int key){       
        int h = hash(key);      
        int i = h;              // consider h as i..
        
        while (ar[i] != -1){        //  search only if it is not -1..
            if (key == ar[i]){      //  if key is found then return..
                return true;
            }
            i = (i+1) % cap;        // if next element is not -1 then we linear search the next slot..

            if (i == h){
                return false;       // Iteration forms return false.. 
            }
        }
        return false;               // search is not possible..
    }

    bool insert(int key){
        
        if (size == cap){       //  if size is full then return..
            return false;
        }
        int i = hash(key);             //  follows on "i"..
        while (ar[i] != -1 && ar[i] != -2 && ar[i] != key){     // insert possible if slot is -1 or -2{deleted_slot}     
            i = (i+1) % cap;        // if collision happens then we linear search for next empty slot..
        }
        if (ar[i] == key){          // if key is already inserted then return..
            return false;
        }
        else{
            ar[i] = key;            // else insert the key and increment size of occupied table and return insert is possible..
            size++;
            return true;
        }
        
    }

    bool erase(int key){        // erase is similiar to search(key)..

        int h = hash(key);      
        int i = h;
        while (ar[i] != -1){        // erase possible only if index of table is not equal to -1..
            
            if (ar[i] == key){      // if key is found then replace as -2..
                ar[i] = -2;
                return true;         // return erase possible..
            }
            i = (i+1) % cap;        //  if initial index is not found the key then linear search next slot..
            
            if (i == h){
                return false;       // if Iteration forms then return..
            }
        }
        return false;               // if  erase is not possible then return..
    }       
};

int32_t main(){

    MyHash mh(7);       // here we declaring the MyHash(Size)..
    mh.insert(49);      
    mh.insert(56);
    mh.insert(72);

    if (mh.search(56) == true){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
    mh.erase(72);
    if (mh.search(72) == true){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}


/*
    How to handle the case when -1{Empty_slot} and -2{Deleted_slot} are input keys ?
        * Here in case of "-1" which is an empty slot, here it used pointer or refernces as the Keys.. 
            it can quick check using NULL if slot is empty then we insert use NULL..
        ** In case -2 in library uses Dummy node for checking the deleted node..
         
*/ 

/*
            Chaining                    Vs                   Open Addressing :=

        -> Hash Table never fills                 -> Table may become full and resizing becomes mandatory
        -> less sentive to Hash functions         -> Extra care required for clusting
means {one cluster doesn't impact on another}
        -> Poor cache performance                 -> cache friendly
        -> extra space for links                  -> extra space might be needed to achieve same performance as chaining
        -> performance for un-successful          -> performance for un-succesful search is 1/(1- Alpha).. which performance less than chaining.
                    search is (1+ Alpha).

*/