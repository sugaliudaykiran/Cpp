/*
    Tree Data Structure
        Tree is used to organise data in hierarchical manner.

    *** Ref :-  https://www.geeksforgeeks.org/introduction-to-tree-data-structure/

    ** Consider a problem where we use the Hierarchice for ex. Orginization structure.. and File storage/Folder structure.. etc
    ** Tree Ds is an Non - Linear data structure.. and previous Ds are Linear ds..
    ** Tree Stores the data in hierarchical fashion..
    ** if a Tree has n node then it has n-1 edges..

    Depth of x => Length of path from the root to x.
               => No. of edges in path from root to x.
    
    Height of x => No. of edges in longest path from x to a leaf..
                => From x node to leaf node which should longest path to reach to leaf..

    In this we discuss about:
        node :-  Every item is represented as node.. 
        root :-  At top of hierarchice is the root node..
        leaf :-  Node which is bottom of hierarchice is the leaf node and has no child node..
       child :-  Node/Nodes which derived from the top of node/ parent node..
      parent :-  Child Node which is link from top node its.. is known as parent node..
    slibling :-  A node having same PARENT..
     subtree :-  Tree is an Recursive in Nature so, root node may have two have sub - root node it is recursive called..
      degree :-  No of children it has.. leaf has zero degree..
internal nodes :- A node which is not leaf is called internal nodes.. 

**  In case of If we can go from A to B :-
        A is ancestors of B.
        B is descendants of A.


**** we discuss applications of Trees :-
        To represent hierarchical data.
            |-> Orgainization Structure.
            |-> Folder Structure.
            |-> XML/HTML content (Json objects) 
            |-> In oop  (Inheritance)
    **  Binary Search Trees.
        Binary heap     {used mainly for Priorty Queues used like Huffman Algo, Djisktra's Algo, Prims Algo..}
        B and B+ Trees in DBMS           //  Indexing or use Hashing..
        Spanning and Shortest path in computer networks     // Bridge uses Spanning trees.. Routers uses Shortest path..
        Parse Tree and Expression Tree in Compilers.        //  parse the source code..
        Trie        //  USED FOR DICTORIES AND USED PREFIX SEARCH..
        Suffix tree
        Binary index tree
    **  Segment tree
        
*/


