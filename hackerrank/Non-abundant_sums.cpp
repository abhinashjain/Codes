#include "stdio.h"
#include "math.h"
#include "vector"
#define RANGE 100001
using namespace std;

int arr[RANGE]={0};
vector<int> abundant;
vector<int>::iterator iter;

void sumofproperdivisor()
{
    int i,j,a,sum,sq;
    for(i=12;i<RANGE;i++)
    {
        sum=0;
        if(i>1)
        {
            sq=sqrt(i);
            for(j=2;j<=sq;j++)
            {
                if((i % j)==0)
                {
                    a=i/j;
                    sum+=a+j;
                }
            }
            if((sq*sq) == i)
            {
                sum-=sq;
            }
            sum+=1;
            if(sum>i)
            {
                arr[i]=1;
                abundant.push_back(i);
            }
        }
    }
}

int main()
{
    int t,n,i,j;
    sumofproperdivisor();
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        j=0;
        for(iter=abundant.begin();*iter<=(n-12);iter++)
        {
            if(arr[n-(*iter)])
            {
                j=1;
                break;
            }
        }
        if(j)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}


/*
 
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
which means that 28 is a perfect number.
 
A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 
As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown
that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known
that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 
Given N, print YES if it can be expressed as sum of two abundant numbers, else print NO.
 
Input Format
The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integer N.
 
Output Format
Print the values corresponding to each test case.
 
Constraints
1<=T<=100
0<=N<=10^5
 
Sample Input
2
24
49
 
Sample Output
YES
NO

*/