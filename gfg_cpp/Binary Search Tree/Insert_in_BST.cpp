/*
    Insert in BST   :-
        In this video we learn how to insert a node in a BST, the basic idea is that wefirst search
            for the key and if the key is not present in the BST then we insert the key with the leaf node.
            Else if the key is already present in the BST then we do nothing.

    ** In this, we are given a BST, and key to be insert, we uses the search function to find the key is present or NOT..
        in case the key is not present in tree.. then we insert key, on the leaf is NULL
         then create a node to it and insert..
    ** In the case of key is already present in tree, then we does nothing..
    ** In case of root is NULL then we create node and insert key and return root as the new key..

                            10                                                  10
                          /    \                                              /    \
                         5      15              Insert(20)..                 5      15
                               /  \                                                /   \
                              12   18                                             12    18
                                                                                          \
                                                                                           20
    
    **** NOTE :- We alway insert the key at the Bottom of the tree (or) level of leaf.. and
                     in one case of NULL case we insert new node and return root..

                    NULL                insert(10)..                            10      -> root of tree..

                    10                                                          10
                  /    \                insert(12)..                          /    \     -> does no changes..
                 8      12                                                   8      12
*/ 

