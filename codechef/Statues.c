#include "stdio.h"

int main()
{
	int i,n,sum,mov,diff,t=0;
	scanf("%d",&n);
	while(n!=0)
	{
		int arr[n];
		sum=mov=0;
		t++;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		sum=sum/n;
		for(i=0;i<n;i++)
		{
			diff=sum-arr[i];
			if(diff>0)
				mov+=diff;
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n",t,mov);
		scanf("%d",&n);
	}
	return 0;
}


/*

The Princess of the Indian Royal Rajput clan loves her Royal Palace. There are N rooms in the palace. Every room has one or more statues. It is not necessary that every room has the same number of statues.

The Princess believes in total equality. It makes her sad to see some rooms with more statues than other rooms. Hence, she has decided to make the number of statues equal in all the rooms. Fortunately, the total number of statues in the palace, across all the rooms, is a multiple of N.

Your job is to figure out the minimum number of moves needed in order to equalize the number of statues in all the rooms. In one move, you may select a statue and move it to any other room. All the statues are indistinguishable.
Input

The input consists of multiple test cases. Each test case is described on two lines.

The first line contains a single positive integer N, the number of rooms.

The second line contains N positive integers { A1, A2, ..., AN } separated by single spaces, describing the number of statues in each of the N rooms respectively.

The end of input is signified by a special test case with N = 0. This will be the last test case in the input, and should not be processed.
Constraints

There are at most 50 test cases in a test file.
1 ≤ N ≤ 50
1 ≤ Ai ≤ 100
Sum of all Ai's is divisible by N

Output

For each test case, print two lines in the output. The first of such lines is the test case number, T in the form of "Set #T", without the quotes (see sample output for clarity). On the second line, print "The minimum number of moves is M.", without the quotes. Here, M is the minimum number of moves you must make to equalize the number of statues in all the rooms. Output a blank line after each test case.

Be careful about the case and punctuation in the above strings. Not adhering to the output format strictly will lead to the Wrong Answer verdict.
Sample Input

6
5 2 4 1 7 5
3
2 3 4
0

Sample Output

Set #1
The minimum number of moves is 5.

Set #2
The minimum number of moves is 1.

*/
