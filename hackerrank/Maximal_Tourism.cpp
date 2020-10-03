#include "list"
#include "iostream"
#define rep(i,begin,end) for(i=begin;i<end;i++)
#define precision_with_no_exponents()   cout.setf(ios::fixed, ios::floatfield); cout.setf(ios::showpoint); cout.precision(9);
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int number_of_nodes_in_components;
class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

    public:
        Graph(int V);
        void addEdge(int v, int w);
        int connectedComponents();
};

int Graph::connectedComponents()
{
    int i,maxnodes=0;
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
            DFSUtil(i, visited);
            maxnodes=max(number_of_nodes_in_components,maxnodes);
        }
    }
    return maxnodes;
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    number_of_nodes_in_components++;

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

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

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


/*

A country has n cities numbered from 1 to n and m bidirectional bus routes for traveling between cities. A pair of cities may be connected by multiple bus routes, and one or more bus 
routes may connect a city to itself.

For example, the diagram below has n=8 cities and m=7 bus routes given by the pairs (4,4), (2,3), (2,3), (2,5), (2,7), (5,7), (6,8):

                                                    Maximal_Tourism-I.png

In the graph above, city 1 has no bus routes; city 4 is only connected to itself; cities 2, 3, 5, and 7 are connected to each other; and cities 6 and 8 are connected to each other.

Jason wants to fly into one of the country's cities and then travel to as many connected cities as possible via the bus system. Given a map of the country, can you find the maximum 
number of connected cities Jason can visit?

Input Format
The first line contains two space-separated integers describing the respective values of n and m.
Each line i of the m subsequent lines contains two space-separated integers, ui and vi, describing a bus route connecting cities ui and vi.

Constraints
1<=n,m<=10^5
1<=ui,vi<=n

Output Format
Print an integer denoting the maximum number of cities Jason can visit.

Sample Input 0
8 5
1 2
7 4
7 3
5 8
1 3

Sample Output 0
5

Explanation 0
The diagram below depicts a map of n=8 cities and m=5 bus routes:

                                        Maximal_Tourism-II.png

Jason has the following options:
1. Start from city 6 and only visit that 1 city.
2. Start from city 5 or city 8 and visit a total of 2 cities (i.e., cities 5 and 8).
3. Start from any city in {1,2,3,4,7} and visit a total of 5 cities (i.e., all the connected cities in that set).

Because we want the maximum number of cities he can visit, we print 5 as our answer.

*/
