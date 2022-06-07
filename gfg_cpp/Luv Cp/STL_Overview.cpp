/*

    STL -> Standard Template Library    Which is internal implemented library in Cpp 
        It classified into 4 types :-
            1) Containers 
            2) Iterators
            3) Algorithms
            4) Functors

    Containers :-
                Sequential                          Ordered                     UnOrdered
                - Vectors                           - Maps                      - Unordered_map    //  uses Hashing..
                - Stack                             - Multimap                  - Unordered_set
                - Queue                             - Set
                - Pair                              - Multiset
            (Not a container which is Class in Cpp)

                                        Nested Containers 
                                         - vector<vector<int>>
                                         - map<int, vector<int>>
                                         - set<pair<int, string>>
                                         - vector<map<int, set<int>>>

    Iterators :-
        - 'For pointing to memory address of containers'
        - begin(), end()
        - vector<int> :: iterator it;   how to write it in short ?      auto it;
        - continunity for containers [continuntiy are like vectors (it+2) and discontinunity are like map and set (it++)]

    Algorithm :-
        - upper_bound
        - lower_bound       // based on binary search O(logN)
        - sort (comparator) //  O(N logN) here we can defind the comparator.
        - min_element   
        - max_element
        - accumulate    // used to find the sum of containers.
        - reverse
        - count
        - find
        - next permutations
        - prev permutations
        - binary search

    Functors :-     //  Not Mostly used in 'CP'.
        - Classes which can act as functions.
        - Template

                            
*/ 