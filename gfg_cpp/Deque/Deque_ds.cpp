/*

Deque Data Structure    :-      Ref :   https://www.geeksforgeeks.org/deque-cpp-stl/
    The discusses Deque data structure and its applications

    ** Deque standards for doubly - end queue..
    ** Deque has two ends are front and rear by this insertion and delection can be on both sides..
    ** Some of main operations of Deque are :-  
        insertFront()   -> Which insert at front..
        deleteFront()   -> Which delect item from front..
        insertRear()    -> Which insert at rear..
        deleteRear()    -> Which delect item from rear..
    ** Additional Operations are getFront(), getRear(), isFull(), isEmpty(), size()..

    Ex :-   
        insertFront(10);    //  Initial deque is empty and we need to insert an item.. then both front and rear be the new added one..
        insertFront(20);
        insertRear(30);

        output :-      
            -----------------------------
            |   10  |       
            -------------------------------

            ----------------------------
            |   20  |   10  |
            ---------------------------

            ---------------------------
            |   20  |   10  |   30  |
            ---------------------------
    Similiar which follows in delection also..

    Implementation :-
        we can use both Linked List and array to implementation of deque..
    
    ** In this we need to use Doubly linked list because, In Single linked list insert/deletion
         at head will take linear..O(1).. but insert in tail which is linear But.. deletion will takes O(N)..
    ** For that reason, we uses the Doubly linked list .. with front and rear Pointer in c++ and Reference in java..

      In Array :- It is Difficult to implement the insert and delection in both ends in O(1)..
        So, we uses the Circular array, by this insert and delection in O(1)..
        *** In Circular array with front and rear indexes. we can also use front and size can get the rear using size.. //  (front + size - 1) % capacity

    Applications :-
        1) A Deque can be used as both stack and queue.
        2) Maintaining History of actions.
        3) A Steal Process Scheduling Algorithm.
        4) Implementing a Priority Queue with two types of Priorities.
        5) Maximum/Minimum of all subarrays of size of k in an array..
        
*/ 