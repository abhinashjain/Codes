#include<stdio.h>
#include<stdlib.h>
# define MAX 100000

typedef struct
{
	int pointer;
	struct node *next;
} node;

typedef struct
{
	int level;
	int finishingTime;
	int descendants;
	node *pointerList;
} array;

int dfs(int, int);
void initialize();
array arr[MAX];
int main()
{	
	int i,adminId,n,q,x,y;
	int parent,child,xft,yft;
	node *last;
	initialize();
	scanf("%d %d",&n,&q);
	scanf("%d",&adminId);
	for(i=0 ; i<n-1 ; i++)
	{
		scanf("%d %d",&x,&y);
		last = arr[x].pointerList;
		if(last == NULL)
		{
			last = (node*)malloc(sizeof(node));
			arr[x].pointerList = last;
		}
		else
		{
			while(last->next != NULL)
				last = last->next;
			last->next = (node*)malloc(sizeof(node));
			last = last->next;
		}
		last->pointer = y;
		last->next = NULL;
	}
	dfs(adminId, 0); // Find Levels, finishing times and no. of descendants
	for(i=0 ; i<q; i++)
	{	
		scanf("%d %d",&x,&y);
		if(arr[x].level == arr[y].level) // Same Level
			printf("0\n");
		else
		{	
			xft = arr[x].finishingTime;
			yft = arr[y].finishingTime;
			if(arr[x].level>arr[y].level && xft<yft && arr[y].descendants >= yft-xft)
				printf("1\n");
			else	if(arr[y].level>arr[x].level && yft<xft && arr[x].descendants >= xft-yft)
					printf("-1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}

int dfs(int id, int level)
{	
	static int time = 1;
	int desc = 0;
	arr[id].level = level;
	node *p = arr[id].pointerList;
	while(p != NULL)
	{
		desc = desc + dfs(p->pointer,level+1);
		p = p->next;
	}
	//printf("id - %d level- %d descendants - %d finishing time - %d\n", id, level, desc, time);
	arr[id].descendants = desc;
	arr[id].finishingTime = time++;
	return desc+1;
}

void initialize()
{	
	int i;
	for(i=0 ; i<MAX ; i++)
	arr[i].pointerList = NULL;
} 

/*
A group of students thought of creating a different VOIP network. The network, rather than being any general graph, was a tree. Every user was assigned a unique userid. This network was hierarchical, i.e there was an admin. The parent of a user is the user connected to it on the unique path when it calls the admin. All users had a parent user except the admin.

All was working fine, until a weird problem occurred in the network. It so happened that a user was only able to call his parent user. Every user (including admin) was unable to reach any of his children. Although we can see that some users can still send a message to other users. A user u can't call the parent g of his parent p (i.e. his grandparent g) but still he can send a message to his grandparent g. u can achieve this by calling p and asking p to call g and send u's message to g.

Your task is to tell, given the userid x and userid y, whether x will be able to send a message to y.
Input

The first line of the input contains two space separated integers N, the total number of users (including admin) in the VOIP network and Q, the number of queries.

The next line contains the userid U of the admin.

Each of the next N-1 lines contains two space separated integers x and y indicating that user x is the parent of user y.

Next in the input are the queries you need to answer. There are Q lines each containing two space separated integers x and y.
Output

For each query output a single line containing

1 if x can send a message to y

-1 if y can send a message to x

0 otherwise
Constraints

    1 ≤ N ≤ 105
    1 ≤ Q ≤ 105
    0 ≤ U ≤ N-1
    0 ≤ x,y ≤ N-1

Example

Input:
3 2
1
1 2
1 0
0 1
0 2

Output:
1
0
*/
