/*

    Ref1 :- https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
    Ref2 :- https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/

    Implementation of Prim's Algorithm  :-
        1) Input is Undirected and connected weight graph..
        2) Find the minimum spanning tree.. and it's weight..
        3) While it's an undirected graph the vertices are connected to each other viseversa..
        4) By using Prim's we maintain two sets which are in MST and not yet in MST..
        5) Check the minimum connecting edge and add to the MST..
        6) Ex.,             2      3
                        (0)----(1)----(2)
                      6 |   8/  |5   /   
                        |   /   |   /  7
                         (3)     (4)

            Initially, res = 0;
                MSTset = {0};
            ** At each step check the MSTset vertices which has minimum weight edge and connects to Not yet in MST..
                    and update the res and add vertex to the MST..
                        2       3
                    (0)----(1)----(2)
                    6 |       |5
                      |       |             res = 0 + 2 + 3 + 5 + 6 = 16
                     (3)     (4)            MSTset = {0, 1, 2, 4, 3}..
            
*/ 

#include<bits/stdc++.h>
using namespace std;
#define v 4

int primMST(int graph[v][v]){       //  TC
    int key[v], res = 0;
    fill(key, key+v, INT_MAX);
    bool Mset[v] ={false};
    key[0] = 0;

    for (int count=0; count<v; count++){    //  0(v^2).. BY using Adjanceny list and Min heap.. O(E logv)..
        int u = -1;

        for (int i=0; i<v; i++){
            if (!Mset[i] && (u == -1 || key[i]<key[u])){        //  Pick the min from the Key and it's index assign 'u'..
                u = i;
            }
        }
        Mset[u] = true;
        res += key[u];

        for (int V=0; V<v; V++){
            if (graph[u][V] != 0 and Mset[V] == false){
                key[V] = min(key[V], graph[u][V]);
            }
        }
    }
    return res;
}

int32_t main(){
    int graph[v][v] = { {0, 5, 8, 0},
                        {5, 0, 10, 15},
                        {8, 10, 0, 20},
                        {0, 15, 20, 0} };
    cout << primMST(graph) << endl;

    return 0;
}