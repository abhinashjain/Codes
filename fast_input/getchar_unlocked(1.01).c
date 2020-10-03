#include "stdio.h"

void scanint(int *z)
{
	int x, neg = 0;
	register int c = getchar_unlocked();
//	x=*z;    //don't think its needed.
	x=0;
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
	*z=x;
}

int main()
{  
	int i,n,k,cnt=0,num;
	scanint(&n);
	scanint(&k);
	for(i=0;i<n;i++)
	{
		scanint(&num);
		if(num%k==0)
			cnt++;
	}   
	printf("%d\n",cnt);
	return 0;            
}
