#include "stdio.h"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
    long long n,c,i,b,m,tot=0,box=0;
    scanf("%lld %lld",&n,&c);
    vector< pair<long long,long long> > crate;
    vector< pair<long long,long long> >::iterator iter;
    for(i=0;i<c;i++)
    {
        scanf("%lld %lld",&b,&m);
        crate.push_back(make_pair(m,b));
    }
    sort(crate.begin(),crate.end());
    for(iter=(crate.end()-1);iter>=crate.begin();iter--)
    {
        box=((*iter).second);
        for(i=0;i<box;i++)
        {
            n--;
            if(n>=0)
            {
                tot+=((*iter).first);
            }
        }
    }
    printf("%lld",tot);
    return 0;
}


/*

A thief broke into a matchstick warehouse and wants to steal as many matchsticks as possible. The warehouse has c crates, and each crate i contains bi matchboxes with exactly mi 
matchsticks per box. The matchboxes are of uniform size, but the number of matchsticks per box can vary from crate to crate. The thief's bag can hold no more than n matchboxes.
 
Given n and the description of each crate's contents, find and print the maximum number of total matchsticks that the thief can steal by optimally choosing which boxes to take.
 
Input Format
The first line contains two space-separated integers describing the respective values of n (the number of matchboxes the thief can carry) and c (the number of crates in the 
warehouse).
Each line i of the c subsequent lines contains a pair of space-separated integers describing the respective values of bi (the number of matchboxes in crate i) and mi (the number of 
matchsticks per box in crate i).
 
Constraints
1<=n<=2*10^8
1<=c<=20
1<=bi<=10^8
1<=mi<=10

Output Format
Print a single integer denoting the maximum number of matchsticks that the thief can escape with.
 
Sample Input 0
3 3
1 3
2 2
3 1
 
Sample Output 0
7
 
Sample Input 1
7 3
5 10
2 5
3 6
 
Sample Output 1
62

*/
