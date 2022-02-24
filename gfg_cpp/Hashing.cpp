//      Hashing which takes O(1) average time to search, insert or delete elements.

/*      Hashing Not useful for :=
                                    
            1) Finding Closest Value,   ---|  Self Balancing Binary Search Tree are..
            2) Sorted Data,             ---|    ==>  AVL Tree and Red Black Tree..
            3) Prefix Searching..               ---> Trie Data Structure.. which is an Dictionaries..

        Applications of Hashing :=
            1) Dictionaries,
            2) DataBase Indexing,
            3) Cryptography,
            4) Caches,
            5) Symbol Tables in Compilers/Interpreter,
            6) Routers,
            7) Getting Data from Databases {Fetching the Data..},
            8) And manymore..

****    Direct Address Table :=     It can handle smaller range values and like ASCII key value..
            Imagine a situation where you have 1000 keys with values from (0 to 999), how would you implement following in O(1) time.. 
                1) Search,
                2) Insert,
                3) Delete..

            Ex :- Operations like..
                insert(10);
                insert(20);
                insert(119);
                search(10);         //  Return "1" / True if the Value is Present..
                search(20);         //  Return "1" / True if the Value is Present..
                delete(119);        
                search(119);        //  Return "0" / False if the Value is Not Present..
        
        Then In this case we use boolean array which store, initially "0" and 
            if any element is Inserted and searchs the inserted one then return "1" True..
            
            psudo Code :=
                insert(i){
                    table[i] = 1;
                }
                delete(i){
                    table[i] = 0;
                }
                search(i){
                    return table[i];
                }
        Direct Address Table will not work better in the Large key Numbers like Phno and floating number case..
                    
    Hashing Functions :=

        Universe of Keys  -->   Hash Function  -->  Hash Table..
        
        How Hash Functions Work :-      "Hash Function Should be Uniformly Distributed.."

            1) Should always map a large key to same small key..    // Here we face Problem collision when similar Phno in differnet order..
            2) Should generate values from 0 to M-1..   (M is Size of the Hash Table..)
            3) Should be fast, 0(1) for Integers and 0(len) for String and its Lenght of String..
            4) Should be Uniformly distribute large keys into hash table slots..

        Examples of Hash Functions :=
            1) h(Large_Key) = Large_Key % M
                                          |--> M must be Prime Number and it should not be Power of 2 and 10.. most avoid Prime Number near to Power Numbers..
                                          |--> It is Not perfect..
            
            2) for strings, weighted sum     -->    str[] = "abcd"
                            |--> (str[0] * x_pow(0) + str[1] * x_pow(1) + str[2] * x_pow(2) + str[3] * x_pow(3)) % M
                            |--> To avoid premutation of Number collision..
                            |--> Here we do ASCII value that character and multiple with x_pow(value).. assume x = 33 and value is like 0,1,2..
                            |--> Sum(All the Indiviual characters) % M
            
            3) Universal Hashing :-
                    |-> Here we create random key and search should be O(1).. which should be fast..
                    |--> In Universe there commonly two keys have same Entire..
                    |---> "Hash Function Should be Uniformly Distributed.."

        "Hash Function Should be Uniformly Distributed.."

    Collision Handling :=
        |--> In example like phone Numbers if u don't phone Number keys then u will not able to Aviod Collision..
        |--> Birthday Paradox will say that if 23 people are present 2 people has same birthday of Probability is 50 %
        |-->  In case of 70 people has same birthday of Probability is 99.9 %..
        |--> By this we can say Collision bound to Happens when we don't Keys in advances..
        |==> If we Know Keys in advance, then we can get "Perfect Hashing.."
        |==> If we don't know keys then we use |
                    1) Chaining        {chain of colliding items..}
                    2) Open Addressing --> Linear Probling,     {here we use same array if position is occupied then we most position..}
                                           Quadratic Probling, 
                                           Double Hashing..
    Chaining :=
        |-> Method for collision handling..
        |-> Here we use Linked list here to store..
        |->     Hash(Key) = Key % M;  // M is Size of the Linked list..
        |-> for ex:-
                hash(key) = key % 7;     // N = 10 here we pick prime number which greater than N or closet to N..
                keys = {50, 21, 58, 17, 15, 49, 56, 22, 23, 25};       
                if there any collision happens we insert at end of linked list..
                _________                
               0|   21  |---> | 49 |--> | 56 |
               1|   50  |---> | 15 |--> | 22 |
               2|   58  |---> | 23 |
               3|   17  |
               4|   25  |
               5|       |
               6|       |
                _________   
            Hash Table (Array of Linked list Headers)..

        Performance of Chaining :=
            m = No of slots of Hash table..
            n = No of keys to be inserted..
            ** Load Factor (alpha) = n/m.. In cpp "Un-Ordered set and map" it default can insert the Load Factor.. 
                if load factor is small then collision will be less..
            Expected  Chain length = alpha {If the Keys are Uniformly distuributed} then it will n/n = 1..

            Expected Time to Search             --> O(1 + alpha)..  "1 for Hash computation and alpha for Chain length.."
            Expected Time to Insert and Delete  --> O(1 + alpha)..  
            
        Data Structure for Storing Chains :=
            Linked List     => Search, Delete, Insert -> O(l) "l -> chain length.."
                            => It is not cache friendly..

            Dynamic sized Arrays    => Vector in cpp   -> Which is cache friendly 
                                    => Search, Delete, Insert -> O(l) where "l -> chain length.."

            Self Balanced BST     => (AVL tree, Red Black tree) -> O(Log l) for Insert, Search, delete..
                                  => It is not cache friendly..
        
*/  