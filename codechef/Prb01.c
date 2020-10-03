#include "stdio.h"
#define number_of_witness 13
#define rep(i,begin,end) for(i=begin;i<end;i++)

long long witness[number_of_witness]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

long long mul_mod(long long a, long long b,long long c)
{
    long long x=0,y=a%c;
    while(b>0)
    {
        if(b&1)
        {
            x=(x+y)%c;
        }
        y=(y<<1)%c;
        b=b>>1;
    }
    return x%c;
}

long long modulo(long long a, long long b, long long c)
{
    long long x=1,y=a;
    while(b>0)
    {
        if(b&1)
        {
            x=mul_mod(x,y,c);
        }
        y=mul_mod(y,y,c);
        b=b >> 1;
    }
    return x%c;
}

int isprime_Miller_Rabin(long long p)
{
    long long i,a,temp,mod,s=p-1;
    rep(i,0,number_of_witness)
    {
        if(p==witness[i])
        {
            return 1;
        }
    }
    rep(i,0,number_of_witness)
    {
        if((p%witness[i])==0)
        {
            return 0;
        }
    }

    if(p<2)
    {
        return 0;
    }
    if(p!=2 && (p&1)==0)
    {
        return 0;
    }
    
    while((s&1)==0)
    {
        s=s >> 1;
    }
    
    rep(i,0,number_of_witness)
    {
        a=witness[i];
        temp=s;
        mod=modulo(a,temp,p);
        while(temp!=(p-1) && mod!=1 && mod!=(p-1))
        {
            mod=mul_mod(mod,mod,p);
            temp=temp << 1;
        }
        if(mod!=(p-1) && (temp&1)==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long t,n,i;
    scanf("%lld",&t);
    rep(i,0,t)
    {
        scanf("%lld",&n);
        if(isprime_Miller_Rabin(n)==1)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}


/*

Alice and Bob are meeting after a long time. As usual they love to play some math games. This times Alice takes the call and decides the game. The game is very simple, Alice says
out an integer and Bob has to say whether the number is prime or not. Bob as usual knows the logic but since Alice doesn't give Bob much time to think, so Bob decides to write a
computer program.
 
Help Bob accomplish this task by writing a computer program which will calculate whether the number is prime or not .
 
Input
The first line of the input contains T testcases, T lines follow
Each of T line contains an integer N which has to be tested for primality

Output
For each test case output in a separate line, "yes" if the number is prime else "no"

Constraints
1<=T<=20
1<=N<=10000
 
Input:
5
23
13
20
1000
99991
 
Output:
yes
yes
no
no
yes

*/
