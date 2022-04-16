/*

Depth First Search  :-
    In this we discusses the Depth First Search algorithm in a graph.
    
        a) DFS which is recursive in nature..
        b) Ex:-         0
                      /   \
                     1     4
                     |   /   \
                     2  5     6
                     |                  where s = 0;
                     3
                O/p :-   0   1   2   3   4   5   6

            Ex.,        0 --- 1 --- 4 --- 5
                        |     | 
                        2 --- 3             where s = 0;
                
                O/p :-    0   1    3    2   4   5    
                It start from 0 and recursive calls for it's adjancey 1 and 2 it picks lower one and then 1, now calls it's recursive adjancey.. which is 3
                    it's calls it's 2 and it's adjancey which all are visited so, return and 3 return to 1 then 1 calls 4 now then it's adjancey which is 5..
             In this it recursive calls the adjancey nodes.. with out repeation..

    1) DFS code 
    2) For Disconnected Graphs
    3) For finding connected components

    TC -> O(V+E).. because we going to traverse every adjancey of every vertex..
                1) for directed we get 'E' and for un directed we get '2E'..
                2) V were we have all vertices of not connected..
*/ 

#include<bits/stdc++.h>
using namespace std;

//      1) DFS code :-
void DFSrec(vector <int>adj[], int s, bool visited[]){
    visited[s] = true;
    // cout << s << " ";

    for (int u: adj[s]){
        if (visited[u] == false){
            DFSrec(adj, u, visited);
        }
    }
}

void DFS(vector <int>adj[],int s, int v){
    bool visited[v];
    for (int i=0; i<v; i++){
        visited[v] = false;
    }
    DFSrec(adj, s, visited);
}

//      2) For Disconnected Graphs :-
void DFS2(vector <int>adj[], int v){
    bool visited[v];
    for (int i=0; i<v; i++){
        visited[i] = false;
    }
    for (int i=0; i<v; i++){
        if (visited[i] == false){
            DFSrec(adj, i, visited);
        }
    }
}
//       3) For finding connected components    :-      TC -> O(V+E)..
int DFS3(vector <int>adj[], int v){
    bool visited[v];
    int cnt =0;
    for (int i=0; i<v; i++){
        visited[i] = false;
    }
    for (int i=0; i<v; i++){
        if (visited[i] == false){
            DFSrec(adj, i, visited);
            cnt++;
        }
    }
    return cnt;
}

void addEdge(vector <int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int32_t main(){
    int v = 5;
    vector <int> adj[v];
    // addEdge(adj,0,1); 
	// addEdge(adj,0,2); 
	// addEdge(adj,2,3); 
	// addEdge(adj,1,3); 
	// addEdge(adj,1,4);
	// addEdge(adj,3,4);
    // int s = 0;
    // DFS(adj, s, v);

	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);
    // DFS2(adj, v);
    cout << DFS3(adj, v);
    return 0;
}

/*

Application :-
    1) Cycle Detection.     
    2) Topological sorting. (Dependency graphs, used in make file utilize)..
    3) Strongly connected components.   (Kosaraju's takes 2 traversal, Torjan's algorithm takes 1 traversal)..
    4) Solving maze and similiar puzzles.   (Backtracking)
    5) Path finding.    (print the path we reached from source to destination..)
*/