/*
    Kosaraju's Algorithm :- Ref :- https://www.geeksforgeeks.org/strongly-connected-components/
        
        A directed graph is strongly connected if there is a path between all pairs of vertices. 
        A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph
*/ 

#include<bits/stdc++.h>
#include<list>
#include<stack>
using namespace std;

class Graph{
    int V;
    list <int> *adj;

    void fillOrder(int v, bool visited[], stack<int>&st);
    
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    
    void addEdge(int v, int w);
    
    void printSCCs();
    
    Graph getTranspose();
};

Graph::Graph(int V){
    this-> V = V;
    adj = new list<int>[V];
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";

    list<int>:: iterator i;
    for (i=adj[v].begin(); i!=adj[v].end(); ++i){
        if (!visited[*i]){
            DFSUtil(*i, visited);
        }
    }
}

Graph Graph::getTranspose(){
    Graph g(V);
    for (int v=0; v<V; v++){
        list<int>:: iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i){
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[], stack<int>&st){
    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i]){
            fillOrder(*i, visited, st);
        }
    }
    st.push(v);
}

void Graph::printSCCs(){
    stack<int>st;
    bool *visited = new bool[V];
    for (int i=0; i<V; i++){
        visited[i] = false;
    }

    for (int i=0; i<V; i++){
        if (visited[i] == false){
            fillOrder(i, visited, st);
        }
    }

    Graph gr = getTranspose();

    for (int i=0; i<V; i++){
        visited[i] = false;
    }

    while(st.empty() == false){
        int v = st.top();
        st.pop();

        if (visited[v] == false){
            gr.DFSUtil(v, visited);
            cout << endl;
        }
    }
}

int32_t main(){

    Graph g(5);
    g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 

	cout << "Following are strongly connected components in given graph \n"; 
	g.printSCCs(); 
    
    return 0;
}