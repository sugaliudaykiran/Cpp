/*

Shortest Path in an Unweighted Graph    :-
    Given an Unweighted Graph and a source point, the task is to find the shortest path between the source point and every other point in the graph.
        By using BST, which is always finds the shortest path.. and maintain the dist[] array for each vertex..

    1) Initialize dist[v] = {INF, INF, INF,.. INF};
    2) dist[s] = 0;
    3) create a queue q;
    4) Initialize : visited[v] = {false, false, .. false};
    5) q.push(s), visited[s] = true;
    6) Now checks the each vertex's adjancent vertex and picks the shortest path between the vertexs..
*/ 

#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

//      Shortest path in an un weighted graph and undirected graph :-   TC -> O(V+E)..
void BFS(vector<int>adj[], int s, int v, int dist[]){
    bool visited[v];
    for (int i=0; i<v; i++){        //  TC -> O(V+E)..
        visited[i] = false;
    }
    queue <int> q;

    q.push(s);
    visited[s] = true;

    while(q.empty() == false){
        int u = q.front();
        q.pop();
        
        for(int v: adj[u]){
            if (visited[v] == false){
                q.push(v);
                dist[v] = dist[u] +1;
                visited[v] = true;
            }
        }
    }
} 

void addEdge(vector <int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
} 

int32_t main(){
    int v = 4, s = 0;
    vector <int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);    

    int dist[v];
    for (int i=0; i<v; i++){
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    BFS(adj, s, v, dist);

    for (int x: dist){
        cout << x << " ";
    }cout << endl;

    return 0;
}