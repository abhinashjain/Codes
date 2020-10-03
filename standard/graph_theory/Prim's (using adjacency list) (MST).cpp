#include "list"
#include "queue"
#include "vector"
#include "iostream"
#include "limits.h"
#define rep(loop_var,begin,end) for(loop_var=begin;loop_var<end;loop_var++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<long long, long long> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    long long V;    // No. of vertices
    
    // In a weighted graph, we need to store vertex and weight pair for every edge
    list<iPair> *adj;
    
    public:
        Graph(long long);  // Constructor
    
        // function to add an edge to graph
        void addEdge(long long, long long, long long);
    
        // Print MST using Prim's algorithm
        long long primMST(long long);
};

// Allocates memory for adjacency list
Graph::Graph(long long V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(long long u, long long v, long long w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
long long Graph::primMST(long long src)
{
    long long i,u,v,weight,totalsum=0;

    // Create a vector for keys and initialize all keys as infinite (LLONG_MAX)
    vector<long long> key(V, LLONG_MAX); //contains edge weight to reach at this node from parent node
    
    // To store parent array which in turn store MST
    vector<long long> parent(V, -1);
    
    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Create a priority queue to store vertices that
    // are being preinMST. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    
    // Insert source itself in priority queue and initialize its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;
    
    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item in pair)
        u = pq.top().second;
        pq.pop();
        
        inMST[u] = true;  // Include vertex in MST
        
        // 'iter' is used to get all adjacent vertices of a vertex
        list<iPair>::iterator iter;
        for (iter = adj[u].begin(); iter != adj[u].end(); iter++)
        {
            // Get vertex label and weight of current adjacent of u.
            v = (*iter).first;
            weight = (*iter).second;
            
            //  If v is not in MST and weight of (u,v) is smaller than current key of v
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    
    // Print edges of MST using parent array
    rep(i,0,V)
    {
//        cout << i << ": " << parent[i] << ": " << key[i] << "\n";
        totalsum+=key[i];
    }
    return totalsum;
}

int main()
{
    dontsync()
    long long n,m,s,u,v,w,i;
    cin >> n >> m;
    Graph g(n);
    rep(i,0,m)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        g.addEdge(u,v,w);
    }
    cin >> s;
    cout << g.primMST(s-1) << "\n";
    return 0;
}
