/*

Shortest Path in DAG    :-  Ref - https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/
    In this we discusses the problem of finding the Shortest Path in Directed Acyclic Graph.

    1) Given a directed acyclic graph, we need to find the shortest distance of each vertices to its adjacent vertices..
    2)              Ex.,      
                               2     3     6
                            0 --> 1 --> 2 --> 3
                             \      2 .       .  1 
                           1   .     /   4    | 
                                 4    ------> 5
                    source : 0
                    
                    index:- 0  1  2  3  4  5 
                    O/p :-  0  2  3  6  1  5
    3) By applying standard shortest Path algorithm like bellman-ford which takes O(VE).. and Dijkstra which takes O(E logV)..
    4) By simplification of TC-> O(V +E) by using Topological sorting
    5) BY maintain distance[] of each vertex from source, initial the values are dist[] = {INF, INF, INF, ..INF};
    6) following According Topological sort..
    7) Check each vertices and it's adjancent distance[] as :-
        For every adjacent v of u..
            If(dist[v] > dist[u] + weight(u, v)){               // where v is adjancent nodes of u..
                dist[v] = dist[u] + weight(u, v);
            }
    8) TC -> O(V+E)..
*/

#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

class AdjListNode{
    int v;
    int weight;
    
    public:
    AdjListNode(int _v, int _w){
        v =_v;
        weight = _w;
    }
    int getV(){
        return v;
    }
    int getWeight(){
        return weight;
    }
};


class Graph{
    int V;
    list <AdjListNode> *adj;

    void topologicalSortUtil(int v, bool visited[], stack <int> &Stack);

    public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void shortestPath(int s);
};

Graph::Graph(int V){
    this -> V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight){
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack){
    visited[v] = true;

    list<AdjListNode>:: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        AdjListNode node = *i;
        if (!visited[node.getV()]){
            topologicalSortUtil(node.getV(), visited, Stack);
        }
    }
    Stack.push(v);
}

void Graph::shortestPath(int s){        //  TC -> O(V+E)..
    stack<int> Stack;
    int dist[V];

    bool *visited = new bool[V];
    for (int i=0; i<V; i++){
        visited[i] = false;
    }

    for (int i=0; i<V; i++){
        if (visited[i] == false){
            topologicalSortUtil(i, visited, Stack);
        }
    }

    for (int i=0; i<V; i++){
        dist[i] = INF;
    }
    dist[s] = 0;

    while (Stack.empty() == false){
        int u = Stack.top();
        Stack.pop();

        list<AdjListNode> :: iterator i;
        if (dist[u] != INF){
            for(i = adj[u].begin(); i != adj[u].end(); ++i){
                if (dist[i -> getV()] > dist[u] + i-> getWeight()){
                    dist[i -> getV()] = dist[u] + i-> getWeight();
                }
            }
        }
    }
    for (int i=0; i<V; i++){
        (dist[i] == INF)? cout << "INF" : cout << dist[i] << " ";
    }
}

int32_t main(){
    Graph g(6); 
	g.addEdge(0, 1, 2); 
	g.addEdge(0, 4, 1); 
	g.addEdge(1, 2, 3); 
	g.addEdge(4, 2, 2); 
	g.addEdge(4, 5, 4); 
	g.addEdge(2, 3, 6); 
	g.addEdge(5, 3, 1);

	int s = 0; 
	cout << "Following are shortest distances from source " << s <<" \n"; 
	g.shortestPath(s); 

	return 0; 
} 