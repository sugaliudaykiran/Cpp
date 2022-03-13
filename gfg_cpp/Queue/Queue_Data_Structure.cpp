/*
     Queue Data Structure   :-

     Ref :-     https://www.geeksforgeeks.org/queue-data-structure/
     Ref_2 :-   https://www.geeksforgeeks.org/queue-cpp-stl/
     Ref_3 :-   https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/

     Queue DS follows "FIFO" in this Queue Insertion and Delection will be on different end..
        Ex :- Items inserted in Pipe chain..
                        ------------------------------------------
dequeue()   <--         |  10   |   15  |  20   |   30   |  40   |       <-- enqueue(X)
                        -----------------------------------------
                          front                             rear
    
    Operations  :-  enqueue(X)    => Insertion/add of items from the enqueue..  and every insert/add the rear changes..
                    dequeue()     => delection/remove of items from the dequeue..  and every delection/remove the front changes..
                    getFront()    => return the front/first item of queue..
                    getRear()     => return the rear/last item of queue..
                    size()        => return size of the queue..
                    isEmpty()     => if queue is empty then return "true.. else false"..
                    
    Applications of Queue :-
      1) Single resources and multiple consumers..
      2) Synchronization between "slow and fast devices"..
      3) In Operating Systems like.. Semaphores, (First comes First sevcer) FCFS Scheduling, Spooling, Buffers for devices like Keyboard..
      4) In Computer Networks (Routers/Switches and Mail Queues)
      5) Variations : Deque, Priority Queue and Double Ended Priority Queue..

*/ 