#include "stdio.h"
#include "algorithm"
#include "list"
#include "cstdio"
using namespace std;

void scanint(int &x)
{
	register int c = getchar_unlocked();
	int neg = 0;
	x = 0;
	for(;((c<48 || c>57) && c != '-');
	c = getchar_unlocked());
	if(c=='-') 
	{
		neg=1;
		c=getchar_unlocked();
	}
	for(;c>47 && c<58;c = getchar_unlocked())
		x = (x<<1) + (x<<3) + c - 48;
	if(neg) 
		x=-x;
}

int main()
{
        int n,l,m,i,p,y,cam;
        list<int>::iterator up,j;
        scanint(n);
        scanint(l);
        scanint(m);
        int arr[n];
        for(i=0;i<n;i++)
	        scanint(arr[i]);
	for(i=0;i<m;i++)
        {
	        scanint(p);
	        scanint(y);
              	arr[p]=y;                
		list<int> mylist(arr,arr+n);
		mylist.unique(); //reduces array size which will helps in sorting 
	        mylist.sort();
	        cam=0;
	        for(j=mylist.begin();j!=mylist.end();j=up)
	        {
		        up=upper_bound(mylist.begin(),mylist.end(),(*j+l));
		        cam++;
		}
		printf("%d\n",cam);
        }               
        return 0;
}


/*

Dancing Elephants is a spectacular show in Pattaya that features N elephants dancing on a line, known
as the stage.

After years of training, elephants in this show are capable of many amazing dances. The show consists of a series of
acts. In each act, exactly one elephant performs a cute dance while possibly moving to a different position.

The show producers want to produce a photo book that contains pictures of the entire show. After each act, they want
to take pictures of all elephants as seen by the spectators.

At any time during the show, multiple elephants may share the same position. In that case, they simply stand behind
one another at the same position.

A single camera can take a picture of a group of elephants if and only if all their positions lie on some segment of
length L (including both its endpoints). As the elephants can spread out across the stage, multiple cameras
may be needed in order to take simultaneous snapshots of all the elephants.

As an example, suppose that L=10 and that the elephants are at positions 10, 15, 17, and 20 on the stage. At
this moment, a single camera can take their picture, as shown below.

In the following act, the elephant at position 15 dances to position 32. After this act, we need at least two cameras
to take the snapshot.

In the next act, the elephant at position 10 moves to position 7. For the new arrangement of elephants, we need three
cameras to photograph all of them.

In this task, you have to determine the minimum number of cameras needed to take the pictures after each
of the acts. Note that the number of cameras needed may increase, decrease, or stay the same between acts.

Let us assume that:

    N – the number of elephants. The elephants are numbered 0 through N-1.
    L – the length of the segment captured by a single camera. You may assume that L is an integer such that 1 ≤ L ≤ 1,000,000,000.
    M – the number of acts performed. You may assume that M is an integer such that 1 ≤ M ≤ 150,000.
    i – the number of the elephant that moves in the current act.
    y – the position where the elephant i will stand after the current act. You may assume that y is an integer such that 1 ≤ L ≤ 1,000,000,000.

Input

First line of input contains an integers N L M. This will be followed by N lines, each having 1 integer, representing the initial positions of N elephants. This will be followed by another M lines having 2 integers i and y.
Output

Output should consist of M integers in separate lines, denoting the minimum number of cameras needed to photograph all elephants after the corresponding act.
Examples

Example 1:

Input

4 10 5
10
15
17
20
2 16
1 25
3 35
0 38
2 0

Output

1
2
2
2
3

Example 2:

Input

2 12321 3
2
123
1 76543
0 66321
0 78754

Output

2
1
1

Subtasks

Subtask 1 (10 points)

    There are exactly N = 2 elephants.
    Initially, and after each act, the positions of all elephants will be distinct.

Subtask 2 (16 points)

    1 ≤ N ≤ 100.
    Initially, and after each act, the positions of all elephants will be distinct.

Subtask 3 (24 points)

    1 ≤ N ≤ 50,000
    Initially, and after each act, the positions of all elephants will be distinct.

Subtask 4 (47 points)

    1 ≤ N ≤ 70,000
    Elephants may share the same position.

Subtask 5 (3 points)

    1 ≤ N ≤ 1,50,000.
    Elephants may share the same position

*/
