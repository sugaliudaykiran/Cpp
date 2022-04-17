/*

Detect Cycle in Undirected Graph    :-
    This problem discusses the Detection of a Cycle in an Undirected Graph.

    1) Here we maintain each vertex's parent and compare with the adjacent vertex, if adjacent vertex which is visited and not equal to it's parent then we return true.. which forms cycle.
    2) Else wouldn't formed..

    Time Complexity :- 
        O(V + E)    for both bfs, dfs approachs..
*/ 


#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

//        Using DFS :-  TC -> O(V + E)..

bool DFSrec(vector <int>adj[], int s, bool visited[], int parent){
    visited[s] = true;

    for (int u: adj[s]){
        if (visited[u] == false){
            if (DFSrec(adj, u, visited, s) == true){
                return true;
            }
        }
        else if (u != parent){  //  for check the parent of it's.. which also the adjacent of it.
            return true;
        }
    }
    return false;
}

bool DFS(vector <int>adj[], int v){
    bool visited[v];
    for (int i=0; i<v; i++){
        visited[i] = false;
    }
    for (int i=0; i<v; i++){    //  For handling the disconnected graphs..
        if (visited[i] == false){
            if (DFSrec(adj, i, visited, -1) == true){        //  for parent of disconnect graph assuming that it's parent is '-1'..
                return true;
            }
        }
    }
    return false;
}


void addEdge(vector <int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
} 

int32_t main(){
    int v = 6;
    vector<int> adj[v];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);

	if(DFS(adj,v))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";
    return 0;
}