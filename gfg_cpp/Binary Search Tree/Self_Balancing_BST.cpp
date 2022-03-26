/*

Self Balancing BST  :-
In this, we discusses the working of a Self Balancing Binary Search Tree.

    Idea :- Is to keep the height as 0(log n).. then all operations are 0(log n).
    Backgroud :-  "Same set of keys can make different height BST's.."

    Order_1 :-    7, 10, 11, 15, 30, 35, 40            Order_2 :-    15, 10, 7, 11, 35, 30, 40

                     7                                                       15
                      \                                                   /     \    
                       10                                                10      35
                         \                                              /  \    /  \
                          11                                           7   11  30   40
                            \ 
                             15                                       "Perfect Balanced BST"
                               \
                                30
                                  \
                                   35
                                     \
                                      40

    This above has different order_1 and order_2 has differ heights.. which is almost O(n).. and another is 0(log n).

    ** If we know the keys in advance, we can make a Perfectly balanced BST..
            
            Ex.,      7, 10, 11, 15, 30, 35, 40     
                this order is sorted, then we can choose the middle of order as root, then left of it.. are left subtree..
                    and right of it.. are right subtree.. and check the next mid of it and make as root.. and it's left and right ..

                                    15
                                  /    \
                                 10      30
                               /   \    /  \
                              7    11  35   40
    
    ** How to keep it balanced, when random insert/deletions happening ?        //  Using rotation..
        The Idea is to do some "restructuring (or re-balancing) when doing insertions/delections".
        
        Ex  :-          Insert 100, 200, and 300 in a empty BST.
            
            100                 100                    100                              200            
                                    \                     \                           /     \
                                     200                   200                      100     300
                                                             \ 
                                                              300
            Insert(100)         Insert(200)             Insert(300)                   Restructure/  Rotation,
                                                    which is un-balanced.           "Left rotation../ CounterClock wise Rotation."

        Ex :-               Insert 300, 200, 100 in a empty BST.

                300                 300                    300                          200            
                                   /                      /                           /     \
                                 200                    200                         100     300
                                                        /        
                                                      100
           Insert(100)         Insert(200)             Insert(300)                   Restructure/  Rotation,
                                                    which is un-balanced.          " Right rotation../ Clock wise Rotation.

    Rotation :-     Which doesn't make any changes to BST rules..

                    p                                                               p
                    .                                                               .
                    .                       Right rotation                          .
                    x                       ----------------->                      y
                  /   \                 <----------------                         /   \
                 y     T3                   Left rotation                        T1    x
               /   \                                                                 /   \
              T1   T2                                                               T2    T3

            all the conditions are  [T1] < y < [T2] < x < [T3]  which are followed after/before rotation..

    ****    Self Balancing BST  :-  
                    1) AVL tree,            {It is very strict in term of height, it maintains very strict Balance..}
                    2) Red black tree..     {It is slight loose in terms of balance.. it's advantages are less-restructing 
                                                when we doing insert/delete.. mostly used.. and Map, Set follows it..}

                    .. and there are more SB BST.. some like split tree
*/ 