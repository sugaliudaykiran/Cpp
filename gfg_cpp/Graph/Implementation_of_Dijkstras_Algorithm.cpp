/*

Implementation of Dijkstra's Algorithm C++  :-
    1) Which is Similiar to Prim's Algorithm.. 
    2) In this implementation, we take the adjacent matrix to represent and we need to 
        find the minimum distance from the distance array and update it's adjacent edges by relax operation..
    3) Finally return the distance array..
    4) TC -> O(V^2)..
    5) By using Adjancey List O(V+E)*(LogV) and Min heap O(LogV).. 
            TC -> O(V+E)*(logV)..
*/ 

#include<bits/stdc++.h>
#define V 4
using namespace std;

vector <int> djikstra(int graph[V][V], int src){    //  TC -> O(V^2)..
    vector <int> dist(V, INT_MAX);
    dist[src] = 0;
    vector <bool> fin(V, false);

    for (int count=0; count<V-1; count++){
        int u = -1;
        for (int i=0; i<V; i++){                //  0(logV)
            if (!fin[i] && (u == -1 || dist[i] < dist[u])){
                u = i;
            }
        }
        fin[u] = true;

        for (int v=0; v<V; v++){                //  0(LogV)
            if (graph[u][v] != 0 and fin[v] == false){
                dist[v] = min(dist[v], dist[u]+graph[u][v]);    // Relax operation..
            }
        }
    }return dist;
}

int32_t main(){
    int graph[V][V] = { {0, 50, 100, 0},
                        {50, 0, 30, 200},
                        {100, 30, 0, 20},
                        {0, 200, 20, 0} };

    for (int x: djikstra(graph, 0)){
        cout << x << " ";
    }cout << endl;

    return 0;
}