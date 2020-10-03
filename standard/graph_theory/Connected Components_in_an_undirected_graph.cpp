#include "list"
#include "iostream"
#define rep(i,begin,end) for(i=begin;i<end;i++)
#define precision_with_no_exponents()   cout.setf(ios::fixed, ios::floatfield); cout.setf(ios::showpoint); cout.precision(9);
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int number_of_nodes_in_components;
// Graph class represents a undirected graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    
    // Pointer to an array containing adjacency lists
    list<int> *adj;
    
    // A function used by DFS
    void DFSUtil(int v, bool visited[]);
    public:
        Graph(int V);   // Constructor
        void addEdge(int v, int w);
        int connectedComponents();
};

// Method to print connected components in an undirected graph
int Graph::connectedComponents()
{
    int i,maxnodes=0;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    rep(i,0,V)
    {
        visited[i] = false;
    }
    rep(i,0,V)
    {
        number_of_nodes_in_components=0;
        if (visited[i] == false)
        {
            // print all reachable vertices from v
            DFSUtil(i, visited);
            maxnodes=max(number_of_nodes_in_components,maxnodes);
//            cout << "\n";
        }
    }
    return maxnodes;
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    number_of_nodes_in_components++;
//    cout << v << " ";
    
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator iter;
    for(iter=adj[v].begin();iter!=adj[v].end();iter++)
    {
        if(!visited[(*iter)])
        {
            DFSUtil((*iter), visited);
        }
    }
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

// method to add an undirected edge
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Drive program to test above
int main()
{
    dontsync()
    int i,n,m,u,v,ans;
    cin >> n >> m;
    Graph g(n+1);
    rep(i,0,m)
    {
        cin >> u >> v;
        g.addEdge(u,v);
    }
    ans=g.connectedComponents();
    cout << ans << "\n";
    return 0;
}
