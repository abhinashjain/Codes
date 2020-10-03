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
        Graph(long long);
        void addEdge(long long, long long, long long);
        void shortestPath(Graph, long long, long long, long long);
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

void Graph::shortestPath(Graph g, long long src, long long k, long long x)
{
    long long i,once=0,u,v,weight,distance;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<long long> dist(V, LLONG_MAX), visited(V,0);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty())
    {
        u = pq.top().second;
        distance = pq.top().first;
        pq.pop();

        if(visited[u])
        {
            continue;
        }
        visited[u]=1;

        if(u<k && once==0)
        {
            rep(i,0,k)
            {
                g.addEdge(u,i,x);
            }
            once=1;
        }
        
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
        rep(p,0,m)
        {
            cin >> a >> b >> c;
            a--;
            b--;
            g.addEdge(a,b,c);
        }
        g.shortestPath(g,s-1,k,x);
    }
    return 0;
}


/*

Bearland consists of N cities, numbered 1 through N. Cities are connected with bidirectional roads.

Cities 1 through K were built a long time ago, when citizens liked order and regularity. Each pair of those old cities is connected with a road of length X. Note that this 
description generates K*(K-1)/2 roads.

There are M newer roads, not necessarily of the same lengths. The i-th of them connects cities ai and bi and has length ci.

There is no road that connects a city to itself. All M+K*(K-1)/2 roads are distinct (ie. no two of them connects the same pair of cities). It's guaranteed that it's possible to get 
from every city to every other city, using one or more roads.

Limak, a bear, lives in the city S. In order to plan a trip to some other city, for every city he wants to know how quickly he can get there. Can you help him and find the distance 
from S to every city?

The distance between two cities is the minimum total length of a path (sequence of roads) between the two cities.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains five integers N, K, X, M and S, denoting the number of cities, the number of old cities, the length of a road between every two old cities, 
the number of newer roads, and the city where Limak lives, respectively.

Each of the following M lines contains three integers ai, bi and ci, denoting a road of length ci between cities ai and bi.
As guaranteed above: no two cities are connected with more than one road, no road connects a city to itself, and it's possible to get from every city to every other city.

Output
For each test case, output a single line containing N integers. The i-th of them should denote the distance from the city S to the city i. The distance from S to S is simply 0.

Constraints
1 ≤ T ≤ 3
2 ≤ K ≤ N ≤ 10^5
0 ≤ M ≤ 10^5
1 ≤ S, ai, bi ≤ N
1 ≤ X, ci ≤ 10^9

Subtasks
Subtask #1 (45 points): 2 ≤ K ≤ 500
Subtask #2 (55 points): Original constraints.

Example
Input:
3
5 4 100 2 3
1 5 50
5 3 160
5 4 100 2 3
1 5 50
5 3 140
8 3 15 7 5
3 4 10
4 5 20
5 6 10
6 1 7
3 7 1000
7 8 50
3 5 1000000000

Output:
100 100 0 100 150
100 100 0 100 140
17 32 30 20 0 10 1030 1080

Explanation
Test case 1. There are N = 5 cities. The first K = 4 of them are all connected with each other with roads of length X = 100. There are M = 2 extra roads:

Cities 1 and 5 are connected with a road of length 50.
Cities 5 and 3 are connected with a road of length 160.

We are asked to compute distances to all cities from the city S = 3. Note that the distance from a city to itself is 0, and this is why the third number in the ouput is 0.

*/
