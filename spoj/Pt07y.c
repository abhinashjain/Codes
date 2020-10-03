#include "stdio.h"

typedef struct Edge
{
        int u,v;
}Edge;

Edge E[20000];
int parent[10001];

void init(int n)
{
        int i=0;
        for(i=0;i<n;i++)
        {
                parent[i]=-1;
        }

}

int Find(int n)
{
        if(parent[n]==-1)return n;
        return parent[n] = Find(parent[n]);
}

int Union(int parent1,int parent2)
{
        parent[parent1] = parent2;
}

int tree(int n,int m)
{
        int u,v,totalEdges=0,edgePos=0;
        Edge now;
        while(m--)
        {
                now = E[edgePos++];
                u = now.u;
                v = now.v;

                int parent1 = Find(u);
                int parent2 = Find(v);
                if(parent1!=parent2)
                        Union(parent1,parent2);
                else
                        return 0;
        }
        return 1;
}

int main()
{
        int n,m,i,u,v,t;
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
                scanf("%d %d",&u,&v);
                E[i].u = u; 
                E[i].v = v; 
        }
        if(m>n-1)
                printf("NO\n");
        else
        {           
                init(n);
                t=tree(n,m);
                if(t==0)
                        printf("NO\n");
                else
                        printf("YES\n");                        
        }
        return 0;
}


/*

You are given an unweighted, undirected graph. Write a program to check if it's a tree topology.
Input

The first line of the input file contains two integers N and M --- number of nodes and number of edges in the graph (0 < N <= 10001, 0 <= M <= 20000). Next M lines contain M edges of that graph --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u,v <= N).
Output

Print YES if the given graph is a tree, otherwise print NO.
Example

Input:
3 2
1 2
2 3

Output:
YES

*/
