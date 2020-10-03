#include "stdio.h"
#include "string.h"
#include "math.h"
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list;
vector<bool> prime(10000000,1);
int main()
{
	int t,i,z;
	char a[10],b[10];
	vector<int>::iterator low,iter;
	void primes();
	primes();
	scanf("%d",&t);
	low = lower_bound(list.begin(), list.end(), t);	
	for(iter=low;iter<=list.end();iter++)
	{
		for(i=0;i<10;i++)
		{
			b[i]=0;
		}
		sprintf(a, "%d", *iter);
		z=strlen(a)-1;
		for(i=z;i>=0;i--)
		{
			b[z-i]=a[i];			
		}
		if((strcmp(a, b)) == 0)
		{
			printf("%d\n",*iter);
			break;
		}
	}
	return 0;
}

void primes()
{
	int i,z;
	prime[0]=0;
	prime[1]=0;
   	prime[2]=1;
   	for(i=3;i<=sqrt(10000000);i=i+2)
	{
   		if(prime[i])
      		{
			z=i<<1;//i*2
      			for( int j = i*i; j <=10000000; j += z )
			{
				prime[j]=0;	
			}       
		}
   	}
	list.push_back(2);
   	for(i=3;i<=10000000;i=i+2)
   	{
       		if(prime[i]!=0)
       		{
	 	        list.push_back(i);         	        
		}
    	}	
}	

/*

 An integer is said to be a palindrome if it is equal to its reverse. For example, 79197 and 324423 are palindromes. In this task you will be given an integer N, 1 ≤ N ≤ 1000000. You must find the smallest integer M ≥ N such that M is a prime number and M is a palindrome.

For example, if N is 31 then the answer is 101.
Input

A single integer N, (1 ≤ N ≤ 1000000), on a single line.
Output

Your output must consist of a single integer, the smallest prime palindrome greater than or equal to N.
Example

Input:
31
Output:
101

*/
