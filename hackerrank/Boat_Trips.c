#include "stdio.h"

int main()
{
    int n,c,m,i,max,num,tmp=0;
	scanf("%d %d %d",&n,&c,&m);
    max=c*m;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        if(num>max)
            tmp=1;
    }
    if(tmp)
        printf("No\n");
    else
        printf("Yes\n");
	return 0;
}

/*

Alice owns a company that transports tour groups between two islands. She has n trips booked, and each trip i has pi passengers. Alice has m boats for transporting people, and each 
boat's maximum capacity is c passengers.
 
Given the number of passengers going on each trip, determine whether or not Alice can perform all n trips using no more than m boats per individual trip. If this is possible, print 
Yes; otherwise, print No.
 
Input Format
The first line contains three space-separated integers describing the respective values of n (number of trips), c (boat capacity), and m (total number of boats).
The second line contains n space-separated integers describing the values of p0,p1,....,pn-1.
 
Constraints
1<=n,c,m<=100
1<=pi<=100

Output Format
Print Yes if Alice can perform all n booked trips using no more than m boats per trip; otherwise, print No.
 
Sample Input 0
5 2 2
1 2 1 4 3
 
Sample Output 0
Yes
 
Explanation 0
Alice has m=2 boats and a maximum capacity of c=2 passengers per boat. This means she can transport at most m*c=4 passengers at a time.
There are n=5 tour groups, and the largest tour group contains p3=4 passengers. Because Alice will be able to transport each group using <=m boats per group, we print Yes.
 
Sample Input 1
5 1 2
1 2 1 4 1
 
Sample Output 1
No
 
Explanation 1
Alice has m=2 boats and a maximum capacity of c=1 passenger per boat. This means she can transport at most m*c=2 passengers at a time.
There are n=5 tour groups, and the largest tour group contains p3=4 passengers. Because Alice does not have enough boats to transport a group of four passengers, we print No.

*/
