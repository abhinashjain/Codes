#include "stdio.h"
#include "math.h"

int main()
{
	int t,n,i,j,r,f,time;
	double lftime;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		r=f=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&time);
			lftime=time;
			r+=(ceil(lftime/30))*10;
			f+=(ceil(lftime/60))*15;
			if(time%30==0)
				r+=10;
			if(time%60==0)
				f+=15;
		}		
		if(r<f)
			printf("Case %d: Respawn %d\n",i,r);
		else
			if(f<r)
				printf("Case %d: Frag %d\n",i,f);
			else
				printf("Case %d: Respawn Frag %d\n",i,f);
	}
	return 0;
}


/*

Burnout, a popular gaming arena in Manipal, has come up with new charging schemes for all the students that game there. Since there are different types of gamers, they are always seeking for packages that are best suited for them. To have an edge over their newly arising competitors, Burnout provides various packages. Two of the most popular packages are:

    Respawn
    Frag

Respawn charges every 30 minutes at a rate of Rs.10. That means if you play for 29 minutes or less, you will be charged with Rs.10. If you play for 30 to 59 minutes, you will be charged with Rs.20 and so on.
Frag charges every 60 minutes at a rate of Rs.15. That means if you play for 59 minutes or less, you will be charged with Rs.15. Similarly, if you play for 60 minutes to 119 minutes, you will be charged with Rs.30 and so on.
Given a list of durations that students have played for, can you determine the package that is cheaper?

 
Input

The first line of input is an integer T, denoting the total number of test cases. Each case starts with a line containing an integer N. followed by a list of N durations (In minutes) in next line. Each duration is an integer in the range [1, 2000] which will be separated by a single space character.
Output

For each case, output the case number first. Then output the name of the cheaper package followed by the corresponding cost in Rupees. If both package gives the same total cost, then output both the names (Respawn preceding Frag) followed by the cost. Look at the output and sample input for details.
Constraints

    1 ≤ T ≤ 50
    1 ≤ N ≤ 20

Example

Input:
3
3
40 40 40
2
61 10
2
60 65


Output:
Case 1: Frag 45
Case 2: Respawn 40
Case 3: Respawn Frag 60

*/
