/*
Binary Search Tree(Background)  :-
    In this, we compare time complexity of different operations on different 
        datastructures and deduce the importance of Binary Search Tree.
  
                                    Binary Search Tree(Background) :-
                            Array [Unsorted]    Array[sorted]   Linked List     BST[Balanced]   Hash table
        ------------------------------------------------------------------------------------------------------------>
    Search                     O(n)                 O(log n)        O(n)            O(log n)        O(1)

    Insert                     O(1)                 O(n)            O(1).,          O(log n)        O(1)
                                                                O(n) in Sorted
    Delete                     O(n)                 O(n)            O(n)            O(log n)        O(1)

    Find Closest               O(n)                 O(log n)        O(n)            O(log n)        O(n)

    Sorted traversal           O(nlog n)             O(n)           O(nlog n)       O(n)            O(nlog n)
                                                                    O(n) in case of 
                                                                      Sorted linked list



Binary Search Tree(Introduction)    :-
    In this, we take a brief introduction about Binary Search Trees.
        Also we briefly discuss about different operations on Binary Search Trees.

    1) Binary Search tree is organised in a way we can skip half of the item.. it is based on binary search.
    2) For every node, keys in left side are smaller and keys in right side are greater.
    3) All keys are typically considered as distinct.
    4) Like a Linked list, it is a linked data structure. that why it is not cache friendly.. 
        So, DS like Linked list, Binary tree, Binary Search tree are not cache friendly..
                             
                             50
                          /     \
                         30      70
                       /   \    /  \
                      10   15  60   80

    5) Implemented in C++ as map, set, multimap, and multiset which follows Self Balancing Binary search tree.
         and in java TreeSet, TreeMap.. there are containers.
    6) In Binary Search Tree Which are represented as similiar as Binary tree.. but it follows order.

Example Operations :-
    1) Create an Empty BST ..
    2) Insert  20, 15, 30, 40, 50, 12, 18, 35, 80.

                                        20
                                      /    \ 
                                     15     30
                                   /   \       \
                                 12    18       40    
                                               /   \
                                              35    50
                                                       \
                                                        80
    ** In this, If the item is smallest then we insert left most place,
         in case of greater than we insert right most place..
    ** We Consider first item as root and compare from next item if it smaller that root and
             we find the NULL place then we insert item..
    ** In case of comparsion item is greater than root and we find the NULL place then we insert item..

    ** Try :- 5, 10, 20, 40, 50
           :- 50, 40, 20, 10, 5
    
    ** In case of Balanced Binary search tree, it takes O(log n)..
    ** In other case it takes O(n) or  O(h)..
*/ 