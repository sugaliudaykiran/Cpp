/*

Breadth First Search    :-

In this we discusses, the Breadth First Search algorithm in the graph.
We discuss following versions of B.F.S. :
    
1. Given an undirected graph and a source vertex 's' ,print B.F.S. from given source.
    a)          0
              /   \
             1     2
                 /  \
                3    4      and s = 0;
        O/p :-  0   1   2   3   4

    b) In this we first traverse from the s, which is at 0 and check it's adjancey, 1 and 2, now for 1 both adj are NULL then we check 2 has adj 3 and 4 
    c) This approach, we find item in level order traverse, like first s and it's adjancey and their adjancey..
    d) Each node should be printed ones.. and adjancey friends can print in any order..

2. B.F.S on disconnected graphs. and possible not provide any sources 's'.
    a) Traverse all vertices of graph with out 's'..
    b) Ex., vap crawling which has multiple pages are connected to each other.. and some pages are not connected to each other..
            and traverse to all the pages..
    c) Ex.,     
                0                   4
              /   \               /   \
             1     2             5 --- 6  
               \ /
                3 
        O/p :-  0   1   2   3   4   5   6

    Idea :- Using visitied array we need to find all the visitied graphs..
        1) Using two function One is for BFS and another for check the Disconnected graph..
        2) By this we check each vertex and it's adjancey which are not visited..
        3) Sum of lenght of all the adjacency list is :-
            It is twice the no. of edges in undirected graph and no. of edges in directed graph..
                        1
                      /  |
                    0 -- 2              for  0 -> 3, 1-> 2, 2 -> 3, 3 -> 2..
                     \   |                   (3+2+3+2) = 10., then of edges is 5, it's twice in undirected graph..
                        3   

3. Print number of islands in a graph (or number of connected components in a graph).
    1) We need to count the connected components in undirected graph..
    2) If component is Connectd when every vertex is reachable to every another vertex..
            0               3           5   
          /   \             |          / \
         1 --- 2            4         6   7
                                          |
    O/p :-  3                             8

    3) There are internal connected components.. and count of them is 3..

*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

// 1. Given an undirected graph and a source vertex 's' ,print B.F.S. from given source.
void BFS(vector <int> adj[], int v, int s){     
    bool visited[v+1];
    for (int i=0; i<v; i++){
        visited[i] = false;
    }

    queue <int> q;
    visited[s] = true;
    q.push(s);

    while (q.empty() == false){
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v: adj[u]){
            if (visited[v] == false){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

//      2. No source given and graph may be disconnected..  //  TC -> O(V+E)..
void BFS2(vector <int> adj[], int s, bool visited[]){
    queue <int> q;
    q.push(s);
    visited[s] = true;

    while (q.empty() == false){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v: adj[u]){
            if (visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFSdis(vector <int> adj[], int v){
    bool visited[v+1];
    for(int i=0; i<v; ++i){
        visited[i] = false;
    }

    for (int i=0; i<v; i++){
        if (visited[i] == false){
            BFS2(adj, i, visited);
        }
    }
}

// 3. Print number of islands in a graph (or number of connected components in a graph).
void BFS3(vector <int> adj[], int s, bool visited[]){
    queue <int> q;
    q.push(s);
    visited[s] = true;

    while (q.empty() == false){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v: adj[u]){
            if (visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }cout << endl;
}

int BFSdis2(vector <int> adj[], int v){
    bool visited[v+1];
    int cnt = 0;
    for(int i=0; i<v; ++i){
        visited[i] = false;
    }

    for (int i=0; i<v; i++){
        if (visited[i] == false){
            BFS3(adj, i, visited);
            cnt++;
        }
    }return cnt;
}
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int32_t main(){
/*
    int v = 5;
    vector <int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    int s = 0;
    // BFS(adj, v, s);
    // BFSdis(adj, v);
*/    
    int v=7;
	vector<int> adj[v];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);

	
    cout << BFSdis2(adj, v) << endl;
    return 0;
}


/*
     Application of BFS :-      //  Many algorithm like   Prims, Algo for minimum spanning tree, Dijstra's algo..
        1) Shortest path in an unweighted graph.
        2) Crawlers in search engines.
        3) Peer to peer N/w.
        4) Social N/w search.
        5) In garbage collection (cheney's algorithm).
        6) Cycle Detection.
        7) Ford Fulkerson Algorithm.
        8) Broadcasting.

*/ 
