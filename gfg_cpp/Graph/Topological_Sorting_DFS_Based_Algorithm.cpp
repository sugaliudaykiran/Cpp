/*

Topological Sorting (DFS Based Algorithm)   :-
    In this we discusses the Topological Sorting using the DFS Based Algorithm.

    1) In last one, we discusses using Kahn's algorithm using BFS.. in this using DFS..
    2) We are given directed and acylic graph., in this were vertices represents the JOB and Edges represented Dependency..
    3) We need to print finishing order of JOBS.. so there dependency are followed..
    4)          0       2
                |       |  \
                .       .   .
                1 ----> 3 -> 4

        O/p :-  2  0  1  3  4 , there are multiple topological order..
    5) In DFS approach in this, we create stack and do recursive DFS traversal of the graph..
            in this, onces all the dependency  of a vertices are push into the stack then we push the initially called DFS into the stack..
    6) Later print items from the stack..

*/ 

#include<bits/stdc++.h>
using namespace std;

//      Using DFS  :-        TC -> O(V + E)..
void DFS(vector<int>adj[], int u, stack <int> &st, bool visited[]){
    visited[u] = true;
    for (int v: adj[u]){
        if (visited[v] == false){       //  check the adjancents are push to the stack or not..
            DFS(adj, v, st, visited);   // calls recursive all it's adjacents..
        }
    }
    st.push(u); //  Push the initially called vertex to the stack.. after it's adjancents are pushed into the stack..
}

void Topo(vector<int> adj[], int v){
    stack <int> st;
    bool visited[v];
    for (int i=0; i<v; i++){
        visited[i] = false;
    }

    for (int u=0; u<v; u++){
        if (visited[u] == false){       //  checks all the vertices are visited are not..
            DFS(adj, u, st, visited);
        }
    }

    while (!st.empty()){    // contains all items in DFS's Topological soring order..
        int u = st.top();
        st.pop();
        cout << u << " ";
    }
}

void addEdge(vector<int>adj[],int u, int v){
    adj[u].push_back(v);
}

int32_t main(){

    int v = 5;
    vector <int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    addEdge(adj, 2, 4);  

    Topo(adj, v);
    return 0;
}