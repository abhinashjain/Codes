#include "stdio.h"
#include "algorithm"
#include "vector"
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
	int n,m,i,j,l,z;
	long long p,q,t;
	while(1)
	{
		scanint(n);
		if(n==0)
			break;
		int a[n];
		for(i=0;i<n;i++)
			scanint(a[i]);
		scanint(m);
		int b[m];
		for(i=0;i<m;i++)
			scanint(b[i]);
		if(n>m)
			z=n;
		else			
			z=m;
		vector<int> intsec(z);
		vector<int>::iterator it;
		it=set_intersection (a, a+n, b, b+m, intsec.begin());
		intsec.resize(it-intsec.begin());
		i=j=-1;
		t=0;
		for (it=intsec.begin(); it!=intsec.end(); it++)
		{
			p=q=0;
			do
			{
				i++;				
				p+=a[i];				
			}while(a[i]!=*it);
			do
			{
				j++;
				q+=b[j];				
			}while(b[j]!=*it);
			if(p>q)
				t+=p;
			else
				t+=q;
		}
		l=z=0;
		for(i=i+1;i<n;i++)
			l+=a[i];
		for(j=j+1;j<m;j++)
			z+=b[j];
		if(l>z)
			t+=l;
		else
			t+=z;
		printf("%lld\n",t);
	}
	return 0;
}



/*

Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. Take for example the following two sequences where intersection points are
printed in bold:
First= 3 5 7 9 20 25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55 57 100
You can ‘walk” over these two sequences in the following way:
1. You may start at the beginning of any of the two sequences. Now start moving forward.
2. At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.
The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450  which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62
Input

Your program will be tested on a number of test cases. Each test case will be speciﬁed on two separate lines. Each line denotes a sequence and is speciﬁed using the following format:

                 n  v1 v2 ... vn

Where n is the length of the sequence and vi is the ith element in that sequence. Each sequence will have at least one element but no more than 10,000. All elements are between -10,000 and 10,000 (inclusive).
The last line of the input includes a single zero, which is not part of the test cases.
Output

For each test case, write on a separate line, the largest possible sum that can be produced.
Sample

input 
 
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
4 -30 -20 -10 10
4 -100 -80 -60 -30 
4 1 2 3 4         
4 5 6 7 8 
0
output 
 
450
2100
-30
26
*/
