#include <stdio.h>
#include <math.h>

int main()
{
	int t,a,sum,s,j,b,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
        scanf("%d",&a);
		sum=0;
        if(a>1)
        {
            s=sqrt(a);
            for(j=2;j<=s;j++)
            {
                if((a % j)==0)
                {
                    b=a/j;
                    sum+=b+j;
                }
            }
            if((s*s) == a)
            {
                sum-=s;
            }
            sum+=1;
        }
        printf("%d\n",sum);
	}
	return 0;
}