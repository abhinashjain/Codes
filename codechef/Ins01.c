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
		int eicc[vert];
		for(j=0;j<vert;j++)
		{
			rootarr[j]=j;
			eicc[j]=0;
		}
 		for(j=0;j<edge;j++) 
		{
			scanf("%d %d",&vertex1,&vertex2);
			root1=findroot(vertex1);
			root2=findroot(vertex2);
			rootarr[root2]=root1;
			
		}
//		cnt=0;
		for(j=0;j<vert;j++) 
		{
			eicc[rootarr[j]]++;
//			if(rootarr[j]==j)
//				cnt++;
		}
		count=f=0;
		for(j=0;j<vert;j++)
		{
			if(eicc[j] & 1)
				if(f!=0)
					count--;
				else
				{
					f=1;
					count++;
				}
			count+=eicc[j];
		}
		printf("%d\n",count);
	}
	return 0;
}



/*

Chef has a Pizza outlet and all of the people of Byteland are aware of the special offer by Chef on Wednesday (i.e buy 1 get 1 free). But people of Byteland are health conscious, they don't want to eat two pizzas and hence they always go in such groups (so that they always pay equally half of one pizza).

If a group is not formed they will go on next wednesday. Two people will go together if and only if they are friends (Yes, friendship is transitive). As you know, byteland consists of many special people, one of them is our own Punk-it, who loves Pecorino cheese burst Pizza a lot. He is ready to go with anyone if group can be formed. 
Input

The first line of the input contains a single integer T, denoting the number of test cases. The description of T test cases follows. The first line of each test case contains two space-separated integers N (the number of people excluding Punk-it) and M( the number of relations). Each of the following M lines contains two space-separated integers A and B denoting A and B are friends.
Output

For each test case, output a single line containing on interger, denoting the maximum number of people who will enjoy pizza.
Constraints

    1 ≤ T ≤ 5
    1 ≤ N ≤ 100000
    0 ≤ M ≤ 100000
    1 ≤ A,B ≤ N
    A != B

Example

Input:
2
6 4
1 2
2 3
3 4
5 6
7 4
1 2
2 3
3 4
6 7

Output:
6
8

*/
