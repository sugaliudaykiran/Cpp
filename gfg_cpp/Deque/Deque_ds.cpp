/*

Deque Data Structure    :-
    The discusses Deque data structure and its applications

    ** Deque standards for doubly - end queue..
    ** Deque has two ends are front and rear by this insertion and delection can be on both sides..
    ** Some of main operations of Deque are :-  
        insertFront()
        deleteFront()
        insertRear()
        deleteRear()
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
    
     
*/ 