#include "stdio.h"
#include "math.h"
using namespace std;
 
long long getMid(long long s, long long e) 
{  
	return s + (e -s)/2;  
}

long long getSumUtil(long long *st, long long ss, long long se, long long qs, long long qe, long long index)
{
	if (qs <= ss && qe >= se)
		return st[index];
	if (se < qs || ss > qe)
		return 0;
	long long mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2*index+1) + getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}

void updateValueUtil(long long *st, long long ss, long long se, long long i, long long diff, long long index)
{
	if (i < ss || i > se)
		return;
	st[index] = st[index] + diff;
	if (se != ss)
	{
		long long mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
		updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
	}
}

void updateValue(long long arr[], long long *st, long long n, long long i, long long new_val)
{
	long long diff = new_val - arr[i];
	arr[i] = new_val;
	updateValueUtil(st, 0, n-1, i, diff, 0);
}

long long getSum(long long *st, long long n, long long qs, long long qe)
{	
	return getSumUtil(st, 0, n-1, qs, qe, 0);
}

long long constructSTUtil(long long arr[], long long ss, long long se, long long *st, long long si)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}
 
	long long mid = getMid(ss, se);
	st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) + constructSTUtil(arr, mid+1, se, st, si*2+2);
	return st[si];
}
 
long long *constructST(long long arr[], long long n)
{
	long long x = (long long)(ceil(log2(n)));
	long long max_size = 2*(long long)pow(2,x) - 1;
	long long *st = new long long[max_size];

	constructSTUtil(arr, 0, n-1, st, 0);
	return st;
}

int main()
{
	long long i,j,k,n,q;
	char ch;
	scanf("%lld %lld",&n,&q);
	long long arr[n];
	for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	long long *st = constructST(arr, n);
	for(i=0;i<q;i++)
	{
		scanf(" %c %lld %lld",&ch,&j,&k);
		if(ch=='S')
			printf("%lld\n",getSum(st,n,j,k));
		else
			if(ch=='G')
				updateValue(arr,st,n,j,arr[j]+k);
			else
				updateValue(arr,st,n,j,arr[j]-k);
	}
	return 0;
}


/*

Story-line :-
Lira loves marbles very much and she especially loves to play with them with her school friends.

Today, Lira is very excited, as her mom said she would give her and her friends some new marbles for her to play with. She immediately requested her mom to give her the new marbles, but, her mom had some tricks kept up her sleeve:

Mom: "Not so fast, young girl!! These won't come for free! If you want to keep playing with them, you must prove you deserve them!!"

Lira: *moans* "Alright, mom, what do I have to do now?"

(Yes, Lira's mom can be quite annoying)

Mom: "Well, you can assume that I have an array A of size N , where N is the total number of students I will give marbles to, and A[i] is the number of marbles each student initially has."

Lira: *smiles slightly* "So you're feeling generous hum?"

Mom: "Well, not too generous... imagine I wanted to give more marbles to some of your school friends who do well on their exams, or, on the other hand take away some marbles from the greedier friends."

Lira: "Mom, c'mon that's too easy!!"

Mom: "Alright, so given a group of students, starting on student i and ending on student j, I want to know how many marbles they have together!"

Well, it turns out that Lira actually did solve this problem and she did it very efficiently!!

It's now your turn to solve the problem that Lira already did in a brilliant way!


Formal description :-
Lira is given array A, which contains elements between 1000 and 2000.

Three types of queries can be performed on this array: add a given value to a single element on it, subtract a given value from a single element on it and find the sum of the values between indexes i and j, i.e. A[i]+...+A[j]. Check input and example section for details.
Input

The first line of the input contains two integers: N and Q, denoting respectively, the number of students that there are present to receive the marbles as a gift and the number of actions Lira's mom will perform.

These actions can be of three different types:
S i j - if the mom wants to find the sum of the number of marbles from students i to j.
G i num_marbles - if the mom decides to give num_marbles to student i
T i num_marbles - if the mom decides to take away num_marbles from student i
Output

The output should contain as many lines as the number of queries S and it should contain the answer for each query on a separate line
Constraints

    2 ≤ N ≤ 1000000
    3 ≤ Q ≤ 50000
    The array is 0-indexed.
    1000 ≤ A[i] ≤ 2000
    A student can never have a negative value of marbles. (i.e. there's no data which can cause a student to have a negative value of marbles)
    0 ≤ i, j ≤ N-1, and i ≤ j for the sum query
    At any given time, it is assured that the maximum number of marbles each student can have (num_marbles) never exceeds the size of the int data type.

 
Example
Input:
5 3 
1000 1002 1003 1004 1005 
S 0 2 
G 0 3 
S 0 2 

Output: 
3005 
3008 

*/
