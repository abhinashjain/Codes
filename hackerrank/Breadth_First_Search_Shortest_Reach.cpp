#include "list"
#include "queue"
#include "vector"
#include "limits.h"
#include "iostream"
#include "algorithm"
#define rep(loop_var,begin,end) for(loop_var=begin;loop_var<end;loop_var++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<long long, long long> iPair;
vector<long long> nodes;

class Graph
{
    long long V;
    list<iPair> *adj;
    void DFSUtil(long long v, bool visited[]);
    
    public:
        Graph(long long);
        void addEdge(long long, long long, long long);
        void shortestPath(long long);
        void connectedComponents(long long);
};

Graph::Graph(long long V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::connectedComponents(long long src)
{
    long long i;
    bool *visited = new bool[V];
    
    rep(i,0,V)
    {
        visited[i] = false;
    }
    rep(i,0,V)
    {
        if (visited[i] == false)
        {
            // print all reachable vertices from v
            DFSUtil(i, visited);
            //            cout << "\n";
            sort(nodes.begin(),nodes.end());
            if(binary_search(nodes.begin(),nodes.end(),src))
            {
                break;
            }
            nodes.clear();
        }
    }
}

void Graph::DFSUtil(long long v, bool visited[])
{
    visited[v] = true;
    nodes.push_back(v);
    
    list<iPair>::iterator iter;
    for(iter=adj[v].begin();iter!=adj[v].end();iter++)
    {
        if(!visited[(*iter).first])
        {
            DFSUtil((*iter).first, visited);
        }
    }
}

void Graph::addEdge(long long u, long long v, long long w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(long long src)
{
    long long i,u,v,weight;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<long long> dist(V, LLONG_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty())
    {
        u = pq.top().second;
        pq.pop();

        list<iPair>::iterator iter;
        for(iter = adj[u].begin(); iter != adj[u].end(); iter++)
        {
            v = (*iter).first;
            weight = (*iter).second;

            if(dist[v] > (dist[u] + weight))
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    rep(i,0,V)
    {
        if(i!=src)
        {
            if(binary_search(nodes.begin(),nodes.end(),i))
            {
                cout << dist[i] << " ";
            }
            else
            {
                cout << "-1 ";
            }
        }
    }
    cout << "\n";
}

int main()
{
    dontsync()
    long long q,n,m,i,j,u,v,s;
    cin >> q;
    rep(i,0,q)
    {
        nodes.clear();
        cin >> n >> m;
        Graph g(n);
        rep(j,0,m)
        {
            cin >> u >> v;
            u--;
            v--;
            g.addEdge(u,v,6);
        }
        cin >> s;
        s--;
        g.connectedComponents(s);
        g.shortestPath(s);
    }
    return 0;
}


/*

Consider an undirected graph consisting of n nodes where each node is labeled from 1 to n and the edge between any two nodes is always of length 6. We define node s to be the 
starting position for a BFS.

Given q queries in the form of a graph and some starting node, s, perform each query by calculating the shortest distance from starting node s to all the other nodes in the graph. 
Then print a single line of n-1 space-separated integers listing node s's shortest distance to each of the n-1 other nodes (ordered sequentially by node number); if s is disconnected 
from a node, print -1 as the distance to that node.

Input Format
The first line contains an integer, q, denoting the number of queries. The subsequent lines describe each query in the following format:

1. The first line contains two space-separated integers describing the respective values of n (the number of nodes) and m (the number of edges) in the graph.
2. Each line i of the m subsequent lines contains two space-separated integers, u and v, describing an edge connecting node u to node v.
3. The last line contains a single integer, s, denoting the index of the starting node.

Constraints
1 <= q <= 10
2 <= n <= 1000
1 <= m <= (n*(n-1))/2
1 <= u,v,s <= n

Output Format
For each of the q queries, print a single line of n-1 space-separated integers denoting the shortest distances to each of the n-1 other nodes from starting position s. These 
distances should be listed sequentially by node number (i.e., 1,2,...,n), but should not include node s. If some node is unreachable from s, print -1 as the distance to that node.

Sample Input
2
4 2
1 2
1 3
1
3 1
2 3
2

Sample Output
6 6 -1
-1 6

Explanation
We perform the following two queries:

1. The given graph can be represented as:
                                            Breadth_First_Search_Shortest_Reach_1.png
where our start node, s, is node 1. The shortest distances from s to the other nodes are one edge to node 2, one edge to node 3, and an infinite distance to node 4 (which it's not 
connected to). We then print node 1's distance to nodes 2, 3, and 4 (respectively) as a single line of space-separated integers: 6, 6, -1.
                                            
2. The given graph can be represented as:
                                            Breadth_First_Search_Shortest_Reach_2.png
where our start node, s, is node 2. There is only one edge here, so node 1 is unreachable from node 2 and node 3 has one edge connecting it to node 2. We then print node 2's distance 
to nodes 1 and 3 (respectively) as a single line of space-separated integers: -1 6.
 
Note: Recall that the actual length of each edge is 6, and we print -1 as the distance to any node that's unreachable from s.

*/
