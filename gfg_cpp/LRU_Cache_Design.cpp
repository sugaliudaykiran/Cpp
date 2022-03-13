/*

    LRU Cache Design     Ref :- https://www.geeksforgeeks.org/lru-cache-implementation/
        ** Cache is memory which is closly to cpu and takes less access time.. but small in size compare to RAM..
        ** LRU is least recent used.. it is by temporay locatate..
        ** In this we add new item as most recent asked item and remove, least asked item..
    
    Ex :-   cache size :   "4"
            Reference sequence :  10, 20, 10, 30, 40, 50, 30, 40, 60, 30.
            identity by {miss, hit} //  "miss" which not in cache and ready to insert.. if size is free (or) remove least asked item and insert..
                                    //  "hit"  which is present and assing as most recent asked item
            
            Expected cache behaviour :  
            [10,]
            [20, 10,]
            [10, 20,]
            [30, 10, 20, ]
            [40, 30, 10, 20]
            [50, 40, 30, 10]
            [30, 50, 40, 10]
            [40, 30, 50, 10]
            [60, 40, 30, 50]
            [30, 60, 40, 50]                

    Naive - Apporach (using arrays):-   miss -> O(N).. hit -> O(N).. where N is capacity of cache..
        
    Efficient Implementation :-         miss -> O(1).. hit -> O(1)..
            (Using Hash table with Double Linked list and doing Hashing..)

        Refer(x)                            //  HT -> hash table..  DLL -> Doubly Linked list
        {
            look for x in the (HT).
            
            (a) if found(hit), find the reference of the node in DLL. move the node in front of DLL.
            (b) if not found(miss) :-
                    (1) Insert a new node at the front of DLL.
                    (2) Insert an empty into the HT.
        }
*/ 

#include<bits/stdc++.h>
#include<map>
using namespace std;

class Node{
    public:
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int k, int v){
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRU{
    public:
    unordered_map <int, Node*> map;
    Node *head, *tail;
    int capacity, count;

    LRU(int c){
        capacity = c;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head -> next = tail;
        tail -> prev = head;
        head -> prev = NULL;
        tail -> next = NULL;
        count = 0;
    }

    void deleteNode(Node *node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    void addTohead(Node *node){
        node -> next = head -> next;
        node -> next -> prev = node;
        node -> prev = head;
        head -> next = node;
    }

    int get(int key){
        if (map[key] != NULL){
            Node *node = map[key];
            int res = node -> value;
            deleteNode(node);
            addTohead(node);
            cout<<"Got the value : " << 
				res << " for the key: " << key<<endl; 
			return res; 
		} 
		cout<<"Did not get any value" <<
							" for the key: " << key<<endl; 
		return -1; 
    }

    void set(int key, int value){
        cout << "Going to set the (key, "<<
                    "value) : (" << key << ", " << value << ")" << endl;
        if (map[key] != NULL){
            Node *node = map[key];
            node -> value = value;
            deleteNode(node);
            addTohead(node);
        }
        else {
            Node *node = new Node(key, value);
            map[key] = node;
            if (count < capacity){
                count++;
                addTohead(node);
            }
            else {
                map.erase(tail->prev->key);
                deleteNode(tail -> prev);
                addTohead(node);
            }
        }
    }
};

int32_t main(){	
		LRU cache(2);  //  c is "2"..

		// it will store a key (1) with value 
		// 10 in the cache. 
		cache.set(1, 10); 

		// it will store a key (2) with value 20 in the cache. 
		cache.set(2, 20); 
		cout<<"Value for the key: 1 is " << cache.get(1)<<endl; // returns 10 

		// removing key 2 and store a key (3) with value 30 in the cache. 
		cache.set(3, 30); 

		cout<<"Value for the key: 2 is " << 
				cache.get(2)<<endl; // returns -1 (not found) 

		// removing key 1 and store a key (4) with value 40 in the cache. 
		cache.set(4, 40); 
		cout<<"Value for the key: 1 is " << 
			cache.get(1)<<endl; // returns -1 (not found) 
		cout<<"Value for the key: 3 is " << 
						cache.get(3)<<endl; // returns 30 
		cout<<"Value for the key: 4 is " << 
						cache.get(4)<<endl; // return 40 
						
    return 0;
}