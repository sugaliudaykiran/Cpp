/*  Ref :-  https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
    Ref2 :- https://www.geeksforgeeks.org/avl-tree-set-2-deletion/?ref=lbp    

AVL Tree    :-
In this, we discusses the AVL tree. This is a self-balancing Binary Search Tree (BST)
     where the difference between heights of left and right subtrees cannot be more than one for all nodes.

    ** AVL tree is a self-balancing Binary Search Tree (BST).. and follows below conditions :-

    ** It is a BST (for every node, it's left subtree is smaller, it's right subtree is greater..)
    ** It is balanced (for every node, difference between left and right "heights doesn't exceed one"..)
                    Balance Factor = |  Lh - Rh |  <= 1
                    Balance Factor  <= 1
    ** If tree is un-balanced then we do reconstruction/ rotation.. to make balance.
    
    ** Operation :- AVL search similiar to BST search but insertion/deletion are complex in maintaining height balance..
    ** Insert operation :-
        |-> Perform normal BST insert.
        |-> In each insertion node we need to check only the ancestors of each node which is to be height balanced..
        |-> Traverse all ancestors of the newly inserted node from the node of root.
        |-> If find any un-balanced node, check for any of the below cases be classified..
                    There are :-    1) Left left        //  Single rotation.
                                    2) Right right      //  Single rotation.
                                    
                                    3) Right left       //  Double rotation.
                                    4) Left right       //  Double rotation.
        
        Ex :-   Insert : 20, 15, 5, 40, 50, 18

            20           20 (1)         20 (|2 - 0| = 2) which is un-balanced.. height             
                        /              /                      now do the rotation.. in this case, we can see there 
                       15             15   (1)                are left left then we do right rotation.
                                     /
                                    5

    // After right rotation :-

            15    (1)                15     (|2 - 1| = 1)               15        (|3 - 1| = 2)    // we do rotation from un-balanced node..
          /    \                   /    \                             /    \
         5     20                 5     20  (1)                      5      20    (|2 - 0| = 2) which is un-balanced then
                                          \                                  \            we can see there is right right, now do left rotation.          
                                           40                                 40   (1)
                                                                                \
                                                                                 50
    //  After Left rotation :-              

             15                          15         (|3 - 1| = 2)  Which is un-balanced.. we can see it's Right Left un - balanced.. then 
           /   \                      /     \                        we do Two rotations they are right rotation on 40 node and next left rotation on 15 node
          5    40                    5       40     (|2 - 1| = 1)   
              /  \                          /   \
             20   50                 (1)   20    50  
                                          /
                                         18
    
    //  After Right rotation on (40) :-                           //  After Left rotation on (15) :-
                    15          (|3 - 1| = 2)  Left - rotation                   20         (0)
                  /    \                                                       /    \
                 5      20      (|1 - 2| = 1)                         (0)     15     40     (1)
                      /   \                                                  /  \      \  
                     18   40                                                5   18     50
                            \ 
                             50 
                                    //  After two rotations..
    
    **  In insertion we need to just fix the un - balance.. where in deletion we fix and check it's ancestor also..

    ** Delete Opertion :-
        |-> In these we do, normal BST delete and we move the level up.. while level up we see an
                 un-balanced state and check which case.. 
        |-> and do the rotation.. and again we need again travel to ancestor after fixing the node..
                 which is not required in Insertion.

    ** TC -> 0(Log n)..  and all the rotation take constant time.

   
   ***  Height of AVL tree :-

                            h < C log(n+2) + b

                        where c ~~ 1.4405
                              b ~~ 1.3277
            
            ** AVL tree is strict balanced BST when compare to another BST..
*/ 

