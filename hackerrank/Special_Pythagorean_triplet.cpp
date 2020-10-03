#include "stdio.h"
#include "thread"
using namespace std;

int arr[1500];
void calculate(int i, int j)
{
    int a,b,c,n,div2,div4,max,asq,bsq,csq,ans;
    for(n=i;n<j;n+=2)
    {
        max=0;
        div2=n>>1;
        div4=n>>2;
        for(b=div2-1;b>div4;b--)
        {
            for(a=n-((b<<1)+1);a>0;a--)
            {
                c=n-(a+b);
                asq=a*a;
                bsq=b*b;
                csq=c*c;
                if(csq>(asq+bsq))
                    break;
                if(csq==(asq+bsq))
                {
                    ans=a*b*c;
                    if(ans>max)
                    {
                        max=ans;
                        break;
                    }
                }
            }
        }
        if(max)
            arr[(n>>1)-1]=max;
        else
            arr[(n>>1)-1]=-1;
    }
}

int main()
{
    int t,i,n;
    thread t1(calculate,2,1500);
    thread t2(calculate,1500,3001);
    t1.join();
    t2.join();
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        if(n&1)
            printf("-1\n");
        else
            printf("%d\n",arr[(n>>1)-1]);
    }
    return 0;
}


/*

A Pythagorean triplet is a set of three natural numbers, a<b<c, for which, a^2+b^2=c^2
For example, 3^2+4^2=9+16=25=5^2
Given N, Check if there exists any Pythagorean triplet for which a+b+c=N
Find maximum possible value of abc among all such Pythagorean triplets, If there is no such Pythagorean triplet print -1.
 
Input Format
The first line contains an integer T i.e. number of test cases.
The next T lines will contain an integer N.
 
Output Format
Print the value corresponding to each test case in seperate line.
 
Constraints
1<=T<=3000
1<=N<=3000

Sample Input
2
12
4

Sample Output
60
-1

*/