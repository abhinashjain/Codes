#include "stdio.h"

int prime[104744],primelist[10001];
void primes()
{
    int i,j,z;
    prime[0]=1;
    prime[1]=1;
    for(i=3;(i*i)<104744;i+=2)          //for(i=3;i<SQROOT_of_SQROOT;i+=2)
    {
        if(prime[i]==0)
        {
            z=i<<1;
            for(j=i*i;j<104744;j+=z)    //for(j=i*i;j<SQROOT;j+=z)
            {
                prime[j]=1;
            }
        }
    }
    j=0;
    primelist[j]=2;
    for(i=3;i<104744;i+=2)
    {
        if(prime[i]==0)
        {
            primelist[++j]=i;
        }
    }
}

int main()
{
    int t,n,i;
    primes();
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("%d\n",primelist[n-1]);
    }
    return 0;
}
