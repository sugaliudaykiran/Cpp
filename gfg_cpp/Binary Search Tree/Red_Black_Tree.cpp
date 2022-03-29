/*
    Ref :-  https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/?ref=lbp

    Red Black Tree :-

    Introduction:
        A red-black tree is a kind of self-balancing binary search tree where each node has 
         an extra bit, and that bit is often interpreted as the colour (red or black). 
         These colours are used to ensure that the tree remains balanced during insertions 
         and deletions. Although the balance of the tree is not perfect, it is good enough to 
         reduce the searching time and maintain it around O(log n) time, where n is the total number
         of elements in the tree. This tree was invented in 1972 by Rudolf Bayer. 

It must be noted that as each node requires only 1 bit of space to store the colour information, 
    these types of trees show identical memory footprint to the classic (uncoloured) binary search tree. 

Rules That Every Red-Black Tree Follows  :-
    1) Every node has a colour either red or black.
    2) The root of the tree is always black.
    3) There are no two adjacent red nodes (A red node cannot have a red parent or red child).
    4) Every path from a node (including root) to any of its descendants NULL nodes has 
        the same number of black nodes.
    5) All leaf nodes are black nodes.

Why Red-Black Trees?
Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that the height of the tree remains O(log n) after every insertion and deletion, then we can guarantee an upper bound of O(log n) for all these operations. The height of a Red-Black tree is always O(log n) where n is the number of nodes in the tree. 

Sr. No.	Algorithm	Time Complexity
    1.	Search	    O(log n)
    2.	Insert  	O(log n)
    3.	Delete	    O(log n)
“n” is the total number of elements in the red-black tree. 

------------------------------------------------------------------------------->
Red Black Tree  :-
In this, we discusses the Red-Black Tree. 
    This is a self-balancing Binary Search Tree (BST) where every node follows the following rules:

    ** Search is similiar as the BST search.. but insert/delete become complex.
    ** If insert/deletion cause un - balancing we need to reconstruct..
    ** In AVL tree which is strict in height balancing and where as Red Black tree is loose when compare to AVL tree.
    ** Red Black tree allows twice the no.of nodes on one path when compare to another path from node to it's descandent leaves..
    ** Be loose which "causes less rotation" when it is un-balance.. disadvantages is begin loose is height become high..

** In case, where insertion and deletion is less and search are more then in this we use AVL tree.. because AVL tree is better BST.
** In case, where insertion/deletion is more than/equal to search then we use Red Black tree..
"
    1) Every node has a color either red or black.
    2) The root of tree is always black.
    3) There are no two adjacent red nodes (A red node cannot have a red parent or red child).
    4) {No of black nodes from every node to all of its descendent leaves should be same..}

                                    [20]                      [] -> black node, {} -> red node
                                  /      \
                                [10]     {40}
                                       /     \
                                     [30]     [80]
                                    /   \     /   \
                                  {25}  {35} {70}  {100}

        From 20 we can see 5 path and having same no.of black node upto the descendent leaves.. which is 2..
        From 40 we can see 4 path and having same no.of black node upto the descendent leaves.. which is 1..
    ** That is Black height should be same through all the descendent leaves..
    4) Every path from a node (including root) to any of its descendent NULL node has the same number of black nodes.
** WE SHOULD FOLLOW ALL THE CONDITIONS..
    ** In above tree is Maximum un-balanced.. because, we can't add nodes on 25 , 35, 70, 100..

    ****  No. of nodes on the path from a node to its farthest descendent leaf should not be more 
                than twice than the no. of nodes on the path it's closest descendent leaf.
    
    ** In above tree we can for the node 20 the closest descendent leaf is 10 then no. of nodes is 2..
            the  farthest descendent leaf is 25 assuming, then no. of nodes is 4..
            we can say that (farthest leaf height) should be lesser or equal to twice (closest leaf height).
    ** In AVL height should be <= 1.. but were as in Red Black Tree height can be the twice.. that why this is
            less strict when we compare to AVL tree..
    
    ** It makes insertion/deletion faster ..
    ** In Insertion we use recoloring (or) else we use rotation in insertion operation..
    ** SET, MAP uses Red Black Tree.
"
*/ 