#include "list"
#include "queue"
#include "vector"
#include "iostream"
#include "limits.h"
#define rep(loop_var,begin,end) for(loop_var=begin;loop_var<end;loop_var++)
#define rep_stl(iter,begin,end) for(iter=begin;iter!=end;iter++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<long long, long long> iPair;

class Graph
{
    long long V;
    list<iPair> *adj;
    
    public:
        Graph(long long);
        void addEdge(long long, long long, long long);
        long long primMST(long long);
};

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

long long Graph::primMST(long long src)
{
    long long i,u,v,weight,totalsum=0;
    vector<long long> key(V, LLONG_MAX); //contains edge weight to reach at this node from parent node
    vector<long long> parent(V, -1);
    vector<bool> inMST(V, false);

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    pq.push(make_pair(0, src));
    key[src] = 0;
    
    while (!pq.empty())
    {
        u = pq.top().second;
        pq.pop();
        
        inMST[u] = true;
        
        list<iPair>::iterator iter;
        rep_stl(iter,adj[u].begin(),adj[u].end())
        {
            v = (*iter).first;
            weight = (*iter).second;
            
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    
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


/*

Given a graph which consists of several edges connecting the N nodes in it.
It is required to find a subgraph of the given graph with the following properties:
    1. The subgraph contains all the nodes present in the original graph.
    2. The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
    3. It is also required that there is exactly one, exclusive path between any two nodes of the subgraph.

One specific node S is fixed as the starting point of finding the subgraph.
Find the total weight of such a subgraph (sum of all edges in the subgraph)

Input Format
First line has two integers N, denoting the number of nodes in the graph and M, denoting the number of edges in the graph.

The next M lines each consist of three space separated integers x y r, where x and y denote the two nodes between which the undirected edge exists, r denotes the length of edge 
between the corresponding nodes.

The last line has an integer S, denoting the starting node.

Constraints
2 <= N <= 3000
1 <= M <= (N*(N-1))/2
1 <= x,y,S <= N
0 <= r <= 10^5
If there are edges between the same pair of nodes with different weights, they are to be considered as is, like multiple edges.

Output Format
Print a single integer denoting the total weight of tree so obtained (sum of weight of edges).

Sample Input 0
5 6
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7
1

Sample Output 0
15

Explanation 0
The graph given in the test case is shown as :

                                Prim's_(MST)_Special_Subtree.png

1. The nodes A,B,C,D and E denote the obvious 1,2,3,4 and 5 node numbers.
2. The starting node is A or 1 (in the given test case)

Applying the Prim's algorithm, edge choices available at first are:
A->B (WT. 3) and A->C (WT. 4) , out of which A->B is chosen (smaller weight of edge).

Now the available choices are:
A->C (WT. 4) , B->C (WT. 5) , B->E (WT. 2) and B->D (WT. 6) , out of which B->E is chosen by the algorithm.

Following the same method of the algorithm, the next chosen edges , sequentially are:
A->C and B->D.

Hence the overall sequence of edges picked up by prims are:
A->B : B->E : A->C : B->D

and Total weight of the hence formed MST is: 15

*/
