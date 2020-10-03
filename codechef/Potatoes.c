#include "stdio.h"
#define maxnumber 2006

int arr[maxnumber]={0};
int prime[maxnumber]={0};
void primefunc()
{
   	int i,z,j;
	arr[0]=arr[1]=1;
   	for(i=3;i*i<maxnumber;i=i+2)
  		if(!arr[i])
      		{
			z=i<<1;
      			for(j=i*i;j<maxnumber;j+=z)
				arr[j]=1;
		}
	prime[2]=1;
   	for(i=3;i<maxnumber;i=i+2)
       		if(!arr[i])
	 	        prime[i]=1;
}

int main ()
{
	int t,x,y,i,j;
	primefunc();
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&x,&y);
		for(j=(x+y+1);j<maxnumber;j++)
			if(prime[j])
			{
				printf("%d\n",j-(x+y));
				break;
			}
	}
	return 0;
}



/*

Farmer Feb has three fields with potatoes planted in them. He harvested x potatoes from the first field, y potatoes from the second field and is yet to harvest potatoes from the third field. Feb is very superstitious and believes that if the sum of potatoes he harvests from the three fields is a prime number (http://en.wikipedia.org/wiki/Prime_number), he'll make a huge profit. Please help him by calculating for him the minimum number of potatoes that if harvested from the third field will make the sum of potatoes prime. At least one potato should be harvested from the third field.

Input
The first line of the input contains an integer T denoting the number of test cases. Each of the next T lines contain 2 integers separated by single space: x and y.

Output
For each test case, output a single line containing the answer.

Constraints
    1 ≤ T ≤ 1000
    1 ≤ x ≤ 1000
    1 ≤ y ≤ 1000

Example
Input:
2
1 3
4 3

Output:
1
4

Explanation
In example case 1: the farmer harvested a potato from the first field and 3 potatoes from the second field. The sum is 4. If he is able to harvest a potato from the third field, that will make the sum 5, which is prime. Hence the answer is 1(he needs one more potato to make the sum of harvested potatoes prime.)

*/
