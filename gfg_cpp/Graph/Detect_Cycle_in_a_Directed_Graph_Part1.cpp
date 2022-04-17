/*

Detect Cycle in a Directed Graph (Part 1)   :-
    In this problem discusses the Detection of a Cycle in an Undirected Graph using DFS.

        0 --> 1 --> 2 
               .    /
                \  .
                  3
        O/p :- Yes

        0 --> 1 --> 2 
               \    /
                .  .
                  3
        O/p :- No

        0 --> 1 <-- 2 -->  3  --> 4
                            .    /
                             \  .
                               5
        O/p :- Yes

        In this above ex., DFSRes(0)
                            |
                             ---> DFSRec(1)

                                                    DFSRec(2)
                                                        |
                                                        ---> DFSRec(3)
                                                             |  |
                                                             |  ---> DFSRec(4)
                                                             |        |
                                                             |        ---> DFSRec(5)
                                                             |             |
                                                             ---------------
                                                                Back edge 

     ** DFS has principle that any descdent has edge to it's any ancesent which form Back Edge which called a cycle in the graph..
*/ 


#include<bits/stdc++.h>
using namespace std;

//            Using DFS :-      TC -> O(V + E)..
bool DFSrec(vector<int> adj[], int s, bool visited[], bool recST[]){
    visited[s] = true;
    recST[s] = true;

    for (int u: adj[s]){
        if (visited[u] == false && DFSrec(adj, u, visited, recST)){
            return true;
        }
        else if (recST[u] == true){
            return true;
        }
    }
    recST[s] = false;
    return false;
}

bool DFS(vector <int> adj[], int v){
    bool visited[v];
    bool recST[v];

    for (int i=0; i<v; i++){
        visited[i] = false;
        recST[i] = false;
    }

    for (int i=0; i<v; i++){
        if (visited[i] == false){
            if (DFSrec(adj, i, visited, recST) == true){
                return true;
            }
        }
    }
}


void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int32_t main(){

    int v=6;
	vector<int> adj[v];
	addEdge(adj,0,1); 
	addEdge(adj,2,1); 
	addEdge(adj,2,3); 
	addEdge(adj,3,4); 
	addEdge(adj,4,5);
	addEdge(adj,5,3);

	if(DFS(adj,v))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

    return 0;
}
