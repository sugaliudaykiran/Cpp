/*

Adjacency List implementation in CPP    :-
    In this we discusses the implementation of the Adjacency List in C++.

    ** In this, we created the array of vector, By initial values are empty..
    ** We also created vector of vectors..
*/ 

#include<bits/stdc++.h>
#include<vector>
using namespace std;

void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);    
    adj[v].push_back(u);    //  It is a Un directed graph..
}

void printGraph(vector <int> adj[], int v){
    for (int i=0; i<v; i++){
        for (auto x: adj[i]){   //  On each vertex printing it's adjaceny list..
            cout << x << " ";
        }cout << endl;
    }
}

int32_t main(){
    int v = 4;
    vector<int> adj[v]; //  In this approach we known the size in advances..

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    printGraph(adj, v);
    return 0;
}
