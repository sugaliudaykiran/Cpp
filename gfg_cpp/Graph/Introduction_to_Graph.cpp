/*

Introduction to Graph   :-
    This is an Introductory to Graph data structure.
    
    1) Linear Ds like array, linked list,.. Non linear DS like Tree, Used to represent the 
             Hierarchy.. it uses Parent and child to present Hierarchy.
    2) Graph is used for mainly random connection between the nodes.
    3) It is represted as pair of sets.. which conatin G = (vertex, edge)..
                v1 --- v3 
                 |     |  `v5           V = {v1, v2, v3, v4, v5}        we have 5 vertex so it's edges are 6 and pairs of edge are below..
                v2 --- v4 '             E = {(v1, v2), (v1, v3), (v2, v4),(v3, v4), (v3, v5)}

                v1 ---> v3 ---\
                \/      \/      >  v5           // Directed Graph..
                v2 ---> v4 ---/

    4)       un - Directed graph                   vs           Directed graph :-
        a) In case (v1, v2) are represented                a) (v1, v2) is only represented union direction..
                as (v2, v1)                                          which can't be (v2, v1).. which is not same..
        b) Ex., FaceBook.. v1 is                           b) Ex., WWW which one page is linked to
            friend of v2 and v2 is friend of v1..                    another one which is union direction..
        c) degree(vertex) is no of edges going             c) degree(vertex) is divided as two types there are :-
            through it.. Ex., degree(v3) is 3..                     1) In degree(v)  :- No of directed edges going to it..
                                                                    2) Out degree(v) :- No of directed edges going out of it..
                                                                Ex., In degree(v3) is 1 and Out degree(v3) is 2
        d) Sum of degrees = 2 * |E|                        d) Sum of In degrees is No of edges |E|..
                                                               Sum of Out degrees is No of edges |E|..
        e) Max No. of edges = |v| * (|v|-1)                e) Max No. of edges = |v| * (|v|-1)..    such graph is also called complete graph..
                              --------------                    Because Every vertex will have (v-1) edges..
                                    2                              By ingore of self loops.. 
            such graph also called complete graph..

                            ThereFore Min no. of edges is O in both cases..
    
    5) Walk :-  Sequence of vertex that we get by following edges of the graph..  Ex., v1, v2, v3, v1 in Un - Directed graph..
       Path :-  It is special path which doesn't allows the repetation of vertex.. Ex., v1, v2, v3  in Un - Directed graph..

        *** Note :- In some Text book Walk is defined as path and Path is defined as Simple path..
    6) graph is cyclic when ?
        Cyclic :- There exists a walk that beigns and ends with same vertex..
                    1) It may be directed or Un - directed graph..
    
    7) This classified as Cyclic Undirected, 
                          Cyclic directed,
                          Directed Acyclic Graph(DAG),  which huge no. of applications..
                          unDirected Acyclic Graph.

    8) Weighted Graphs(Ex., Graph of road N/w, computer N/w)  and unWeighted Graphs..

*/  