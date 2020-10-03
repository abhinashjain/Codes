#include "stdio.h"

int gcd(int, int);

int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{		
		scanf("%d",&n);
		int a[n];
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		for(j=0;j<(n-1);j++)
		{
			a[j+1]=gcd(a[j],a[j+1]);
		}
		printf("%d\n",a[n-1]);
	}
	return 0;
}

int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = b;
		b = a % t;
		a = t;
	}
	return a;
}
