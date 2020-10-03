#include <stdio.h>
#define size 65536

void scanint(int *z)
{
	int x, neg = 0;
	register int c = getchar_unlocked();
	x=*z;
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
	*z=x;
}

int main()
{  
	char b[size];
	int t=0,n,k,cnt=0,c,j;
	scanint(&n);
	scanint(&k);
	while((c = fread(b,1,size,stdin))>0)
	{
		for(j=0;j<c;j++)
	                if(b[j]=='\n')
	                {
				if(t%k==0)
					cnt++;
	                        t = 0;
			}
	                else
				t = (t*10) + (b[j]-'0');               
	}
	printf("%d\n",cnt);   
	return 0;
}
