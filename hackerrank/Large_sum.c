#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INDEX 50

int main()
{
    char tmp1[INDEX],tmp2[INDEX];
    int n,i,j,carry,tenth,num[INDEX+3]={0},sum[INDEX+3]={0},cal;
    scanf("%d",&n);
    scanf("%s",tmp1);
    for(j=0;j<INDEX;j++)
        sum[j+3]=tmp1[j]-'0';
    for(i=1;i<n;i++)
    {
        scanf("%s",tmp2);
        for(j=0;j<INDEX;j++)
            num[j+3]=tmp2[j]-'0';
        carry=0;
        for(j=INDEX+2;j>=0;j--)
        {
            cal=sum[j]+num[j]+carry;
            sum[j]=cal%10;
            carry=cal/10;
        }
    }
    if(sum[0]!=0)
        j=0;
    else
    {
        if(sum[1]!=0)
            j=1;
        else
        {
            if(sum[2]!=0)
                j=2;
            else
                j=3;
        }
    }
    tenth=j+10;
    for(;j<tenth;j++)
    {
        printf("%d",sum[j]);
    }
    return 0;
}



/*

Work out the first ten digits of the sum of N 50-digit numbers.
 
Input Format
First line contains N, next N lines contain a 50 digit number each.
 
Output Format
Print only first 10 digit of the final sum
 
Constraints
1<=N<=10^3
 
Sample Input
5
37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
74324986199524741059474233309513058123726617309629
91942213363574161572522430563301811072406154908250
23067588207539346171171980310421047513778063246676
 
Sample Output
2728190129
 
*/