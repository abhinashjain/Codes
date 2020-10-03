bool Solution::isPower(int A)
{
    if(A==1)
    {
        return 1;
    }
    if(A==2 || A==3 || A==5 || A==7 || A==10)
    {
        return 0;
    }
    if(A!=2 && (A&(A-1))==0)
    {
        return 1;
    }
    int i,tmp,p;
    for(i=3;((i*i)>0 && (i*i)<=A);i++)
    {
        p=0;
        tmp=i*i;
        while(tmp>p && tmp<A)
        {
            p=tmp;
            tmp=tmp*i;
        }
        if(tmp==A)
        {
            return 1;
        }
    }
    return 0;
}


/*
 
Editorial:
 
int isPower(int A)
{
    int i,a;
    double p;
    if(A == 1)
        return 1;
    for(a = 1;a <= sqrt(A);a++)
    {
        p = log(A) / log(a);
        if(p - (int)p < 0.000000001)
            return 1;
    }
    return 0;
}
 
*/


/*
 
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.
 
Example
Input : 4
Output : True
as 2^2 = 4.
 
*/
