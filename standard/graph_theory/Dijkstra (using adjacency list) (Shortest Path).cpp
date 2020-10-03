#include "list"
#include "queue"
#include "vector"
#include "iostream"
#include "limits.h"
#define rep(loop_var,begin,end) for(loop_var=begin;loop_var<end;loop_var++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<long long, long long> iPair;

class Graph
{
    long long V;
    list<iPair> *adj;
    
    public:
        Graph(long long);  // Constructor
        void addEdge(long long, long long, long long);
        void shortestPath(long long);
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
void Graph::shortestPath(long long src)
{
    long long i,u,v,weight;

    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<long long> dist(V, LLONG_MAX);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    /* Looping till priority queue becomes empty (or all
     distances are not finalized) */
    while(!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        u = pq.top().second;
        pq.pop();

        // 'iter' is used to get all adjacent vertices of a vertex
        list<iPair>::iterator iter;
        for(iter = adj[u].begin(); iter != adj[u].end(); iter++)
        {
            // Get vertex label and weight of current adjacent of u
            v = (*iter).first;
            weight = (*iter).second;

            //  If there is shorted path to v through u.
            if(dist[v] > (dist[u] + weight))
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    // Print shortest distances stored in dist[]
    rep(i,0,V)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main()
{
    dontsync()
    long long t,n,k,x,m,s,a,b,c,i,p,q;
    cin >> t;
    rep(i,0,t)
    {
        cin >> n >> k >> x >> m >> s;
        Graph g(n);
        rep(p,0,k)
        {
            rep(q,p+1,k)
            {
                g.addEdge(p,q,x);
            }
        }
        rep(p,0,m)
        {
            cin >> a >> b >> c;
            a--;
            b--;
            g.addEdge(a,b,c);
        }
        g.shortestPath(s-1);
    }
    return 0;
}
