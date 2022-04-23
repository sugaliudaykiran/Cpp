/*

Kruskal's Algorithm     :-
    In this about Kruskal's algorithm and its implementation using Disjoint Set Data Structure is discussed..

    Ref :-  https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
    Ref2:-  https://www.geeksforgeeks.org/kruskals-algorithm-simple-implementation-for-adjacency-matrix/
    Ref3:-  https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/

    Kruskal's algorithm to find Minimum spanning Tree of a given connected, undirected, and weighted graph..

*/ 

#include<bits/stdc++.h>
using namespace std;

class Edge  // a structure to represent a weighted edge in graph
{
    public:
    int src, dest, weight;
};

class Graph     // a structure to represent a connected, undirected and weighted graph
{
    public:
    int V, E;   	// V-> Number of vertices, E-> Number of edges 
    // graph is represented as an array of edges. Since the graph is undirected, the edge 
        // from src to dest is also edge from dest to src. Both are counted as 1 edge here.

    Edge* edge;
};

Graph* createGraph(int V, int E)    // Creates a graph with V vertices and E edges 
{
    Graph* graph = new Graph;
    graph -> V = V;
    graph -> E = E;

    graph -> edge = new Edge[E];
    return graph;
}

class subset    // A structure to represent a subset for union-find 
{
    public:
    int parent;
    int rank;
};

int find(subset subsets[], int i)    //  A utility function to find set of an element i (uses path compression technique)
{     
    if (subsets[i].parent != i)
    {       //  	// find root and make root as parent of i (path compression) 
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)      //  A function that does union of two sets of x and y (uses union by rank) 
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);   // Attach smaller rank tree under root of high rank tree (Union by Rank)

    if (subsets[xroot].rank < subsets[yroot].rank)  
    {
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else{       //  If ranks are same, then make one as root and increment its rank by one 
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
    // Compare two edges according to their weights.  Used in qsort() for sorting an array of edges 
int myComp(const void *a, const void *b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1 -> weight > b1 -> weight;
}

void KruskalMst(Graph* graph)
{
    int V = graph->V;
    Edge result[V]; // This will store the resultant MST 
	int e = 0; // An index variable, used for result[] 
	int i = 0; // An index variable, used for sorted edges 

	// Step 1: Sort all the edges in non-decreasing order of their weight. If we are not allowed to 
	    // change the given graph, we can create a copy of array of edges 
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    subset* subsets = new subset[(V * sizeof(subset))]; 	// Allocate memory for creating V ssubsets 

    for (int v=0; v<V; v++) 	// Create V subsets with single elements 
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int res = 0;

    while (e<V-1 && i < graph->E){       	// Number of edges to be taken is equal to V-1 
        Edge next_edge = graph->edge[i++];
        		// Step 2: Pick the smallest edge. And increment the index for next iteration
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        		// If including this edge does't cause cycle,  include it in result and increment the index 
		            // of result for next edge 
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
            res += next_edge.weight;
        }
        	// Else discard the next_edge 
	} 
	// print the contents of result[] to display the built MST 
    cout << "Weight of MST is : " << res << endl;
    return;
}

int32_t main(){
    int V = 5; // Number of vertices in graph 
	int E = 7; // Number of edges in graph 
    Graph* graph = createGraph(V, E);

        //  addEdge   0-1
        graph -> edge[0].src = 0;
        graph -> edge[0].dest = 1;
        graph -> edge[0].weight = 10;

		// add edge 0-2 
		graph->edge[1].src = 0; 
		graph->edge[1].dest = 2; 
		graph->edge[1].weight = 8; 

		// add edge 0-3 
		graph->edge[2].src = 1; 
		graph->edge[2].dest = 2; 
		graph->edge[2].weight = 5; 

		// add edge 1-3 
		graph->edge[3].src = 1; 
		graph->edge[3].dest = 3; 
		graph->edge[3].weight = 3; 

		// add edge 2-3 
		graph->edge[4].src = 2; 
		graph->edge[4].dest = 3; 
		graph->edge[4].weight = 4; 
		
		//add egde 2-4
		graph->edge[5].src = 2; 
		graph->edge[5].dest = 4; 
		graph->edge[5].weight = 12;
		
		// add edge 3-4
		graph->edge[6].src = 3; 
		graph->edge[6].dest = 4; 
		graph->edge[6].weight = 15; 

	KruskalMst(graph); 
    return 0;
}