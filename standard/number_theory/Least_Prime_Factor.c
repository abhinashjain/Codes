#include "stdio.h"
#include "stdbool.h"
#define MAX 1000001

bool prime[MAX];
int lpd[MAX];
void leastprimedivisor()
{
    unsigned long long i,j,k;
    lpd[1]=1;
    for(i=3;i<MAX;i+=2)
    {
        lpd[i-1]=2;
        if(!prime[i])
        {
            lpd[i]=i;
            for(j=i;(k=(j*i))<MAX;j+=2)
            {
//                k=j*i;
                if(!prime[k])
                {
                    prime[k]=1;
                    lpd[k]=i;
                }
            }
        }
    }
    lpd[MAX-1]=2;
    for(i=3;i<MAX;i+=2)
    {
        printf("lpd[%llu] = %d\n",i,lpd[i]);
    }
}

int main()
{
    leastprimedivisor();
    return 0;
}