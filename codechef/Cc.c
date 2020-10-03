#include <stdio.h>
 
int rootarr[100001];

int findroot(int a)
{
	int root1,root2;
	root1=a;
	while(rootarr[a]!=a) 
		a=rootarr[a];
	while(root1!=a) 
	{
		root2=rootarr[root1];
		rootarr[root1]=a;
		root1=root2;
	}	
	return a;
}		

int main()
{
	int t,i,j,vert,edge,vertex1,vertex2,root1,root2,cnt,f,count;
	scanf("%d",&t);
	for(i=0;i<t;i++) 
	{
		scanf("%d %d",&vert,&edge);
		for(j=0;j<vert;j++)
		{
			rootarr[j]=j;
		}
 		for(j=0;j<edge;j++) 
		{
			scanf("%d %d",&vertex1,&vertex2);
			root1=findroot(vertex1);
			root2=findroot(vertex2);
			rootarr[root2]=root1;		
		}
		cnt=0;
		for(j=0;j<vert;j++) 
		{
			if(rootarr[j]==j)
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}



/*

Given a undirected graph find the number of connected components.

Input
First line of the input is 't'- number of test case.
Followed by N, the number of vertices (Numbered 0 to N-1).
Followed by 'e' number of edges.
Followed by description of 'e' edges in the form 'a b' I.e. an edge exist between vertex a and b.

Constraints:
T=10

2 <= N <= 100000

0 <= e <= N/2

Output

One line per test case, number of connected components in the graph.

Example
Input:
2
4
2
0 1
0 2
8
0

Output:
2
8

*/
