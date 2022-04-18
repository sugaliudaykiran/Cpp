/*

Topological Sorting (Kahn's BFS Based Algortihm)    :-
    In this we discusses the problem of Topological Sorting using Kahn's BFS Based Algorithm.

    1) Given an Directed and acyclic graph need to find Topological order., which has various order..
    2) Ex.,             
                    0      1            using BSF and by indegree of each vertices., indegree means incoming edges to the vertex.
                  /  \   /  \       where 0 and 1 has indegrees is '0' and 2 and 4 has '1' and 3 has '3'.. 
                 .    . .    .
                2 ---> 3     4
        
        O/p :-      0   1   2   3   4
    3) By maintain queue and store the zero indegree to it.. 
    4) while dequeu the zero indegree and making it's adjancey indegree's decrement by '1'..
    5) When traverse the queue and push vertex whose indegree be zero..
    6) It's also known as Kahn's Algorithm..
*/ 

#include<bits/stdc++.h>
using namespace std;

//      Using BFS   :-      TC -> O(V + E)..
void Topo(vector <int> adj[], int v){
    vector<int> inDegree(v, 0);
    for (int u=0; u<v; u++){        // takes O(E)..
        for (int x: adj[u]){    
            inDegree[x]++;
        }
    }

    queue <int> q;
    for(int i=0; i<v; i++){
        if (inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int x: adj[u]){
            if (--inDegree[x] == 0){
                q.push(x);
            }
        }
    }
}

//      Directed graph :-
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
}

int32_t main(){
    int v = 5;
    vector <int> adj[v];
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 4);

    Topo(adj, v);
    return 0;
}