#include "stdio.h"
#include "cstdio"

void scanint(int &x) //long long &x, bool neg.
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

	int i,n,k,cnt=0,num;
	scanint(n);
	scanint(k);
	for(i=0;i<n;i++)
	{
		scanint(num);
		if(num%k==0)
			cnt++;
	}   
	printf("%d\n",cnt);
	return 0;            
}
