#include <stdio.h>

int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fib(n));
    return 0;
}

/*

The Fibonacci Sequence:
The Fibonacci sequence begins with fibonacci(0)=0 and fibonacci(1)=1 as its respective first and second terms. 
After these first two elements, each subsequent element is equal to the sum of the previous two elements.
 
Here is the basic information you need to calculate fibonacci(n):
1. fibonacci(0)=0
2. fibonacci(1)=1
3. fibonacci(n)=fibonacci(n-1)+fibonacci(n-2)

Task
Given n, complete the fibonacci function so it returns fibonacci(n).
 
Input Format
Locked stub code in the editor reads a single integer denoting the value of n and passes it to the fibonacci function.
 
Constraints
0<n<40
 
Output Format
Locked stub code in the editor prints the value of fibonacci(n) returned by the fibonacci function.
 
Sample Input
3
 
Sample Output
2
 
Explanation
Consider the Fibonacci sequence:
fibonacci(0)=0
fibonacci(1)=1
fibonacci(2)=(0+1)=1
fibonacci(3)=(1+1)=2
fibonacci(4)=(1+2)=3
fibonacci(5)=(2+3)=5
fibonacci(6)=(3+5)=8
...
 
We want to know the value of fibonacci(3). If we look at the sequence above, fibonacci(3) evaluates to 2. Thus, we print 2 as our answer.

*/
