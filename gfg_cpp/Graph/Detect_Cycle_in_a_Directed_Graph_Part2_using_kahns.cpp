/*

Detect Cycle in a Directed Graph (Part 2) :-
    In this problem we discusses the Detection of a Cycle in an directed Graph using Kahn's algorithm.

    1) In this, we are using Kahn's algorithm which works only for directed and acyclic graph..
    2) By simple modification of Kahn's algorithm when can find the cycle is found..
    3) By maintain a count variable and increment while poping item from the queue and comparing the count with v at last.. 
        a) If count is not equal to v, then a cycle is present..
        b) else no cycle is present..
*/ 



#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

//      Using BFS   :-      TC -> O(V + E)..
bool Topo(vector <int> adj[], int v){
    vector<int> inDegree(v, 0);
    int count = 0;                  //  for checking the cyclic or not..
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
        // cout << u << " ";
        for (int x: adj[u]){
            if (--inDegree[x] == 0){
                q.push(x);
            }
        }
        count++;    //  increment while pop() each item from the queue..
    }
    return (count != v);    // Compare with count by v.. because in a cylic graph..
}                           //   indegrees of cycle doesn't have indegree zero so by this we can say that is a cycle..

//      Directed graph :-
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
}

int32_t main(){
    int v = 5;
    vector <int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 3, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 2);
    
    if (Topo(adj, v)) { 
        cout << " cycle in the graph\n"; 
    }
    else{
        cout << " no cycle in the graph\n";
    }
    return 0;
}