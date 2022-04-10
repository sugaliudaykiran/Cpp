/*

Priority Queue in C++   :-      // By default it's Max Heap..
In this, we discusses the working and implementation of the Priority Queue in C++. 
    It also discusses the various general applications of Priority Queue.

** Priority Queue is implemented using Heap Data structure..
** In c++ Priority queue is default implements the Max Heap..

Max Heap (default)  :-

//        For Min Heap    :-    
    priority_queue <int> pq;    //  By default it's Max Heap..

    pq.push(10);
    pq.push(5);
    pq.push(15);                // push -> O(1), pop -> O(log n)..

    cout << pq.size() << endl;  
    cout << pq.top() << endl;       // return top which is largest element of queue..

    while (pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    }

//      For Min Heap    :-
    priority_queue <int, vector <int>, greater <int>> pq;   //  data type of queue.. vector acts as underline container.. 

    pq.push(10);
    pq.push(5);
    pq.push(15);

    cout << pq.size() << endl;
    cout << pq.top() << endl;   // return top which is smallest element of queue..

    while (pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    } 

//  Implementing priority queue using existing vector (or) array..
        Using Constructor :-
    
    int ar[] = {10, 5, 15};     //  In case of vector pq(v.begin(), pq.end());
    priority_queue <int> pq(ar, ar+3);   //  TC -> O(n).. which Better than pushing the items..

    cout << pq.size() << endl;
    while (pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    }

//      Implementing Min heap using constructor :-
    
    int ar[] = {10, 5, 15};
    int n = sizeof(ar)/sizeof(ar[0]);
    for (int i=0; i<n; i++){
        ar[i] = -(ar[i]);
    }

    priority_queue <int> pq(ar, ar+3);
    while (pq.empty() == false){
        cout << -(pq.top()) << " ";
        pq.pop();
    }


    Time Complexity :-  
        Push(x), pop()  -> O(log n)
        top(), empty(), size() -> O(1)

Imp :-
    1) In creation of pairs on priority_queue the elements are order on first of pair..
    2) We can also use constructor or any sort of compare functions..

Application :-
    1) Dijkstra Algorithm,
    2) Prim Algorithm,
    3) Huffman's Algorithm,
    4) Heap sort,
    5) And any other place where heap is used like max, min, extract max, extract min..

//  Decrease Key is not available in STL and we can modify the code while using it..

*/  

#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Person{
    int age;
    float height;
    Person(int a, float h){
        age = a;
        height = h;
    }
};

struct Mycmp{
    bool operator() (Person const &p1, Person const &p2)    //  Overloading comparsion..
    {
        p1.height < p2.height;          // Decreasing order..
    }
};
//   Using compare functions in user defined type :-
int32_t main(){
    priority_queue <Person, vector <Person>, Mycmp> pq;

    while (pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}

