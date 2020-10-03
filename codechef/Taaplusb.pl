#!/usr/bin/perl

@arr=();
@ans=();
$arr[1]=0.45;
$ans[1]=0.45;
for($i=2;$i<=100000;$i++)
{
	$arr[$i]=0.45+((10/100)*$arr[$i-1]);
	$ans[$i]=$arr[$i]+$ans[$i-1];
}
$t=<STDIN>;
for($i=0;$i<$t;$i++)
{
	$n=<STDIN>;
	$b=sprintf '%.6f', $ans[$n];
	print "$b\n";
}



=comment

Have you ever implemented a program adding two big integers that cannot be represented by the primitive data type of your programming language? The algorithm is just simulation of the column addition method that we have been taught in elementary school. Sometimes we forget the carry and the result is incorrect.

In this problem, you need to evaluate the expected value of the number of times we have non-zero carry when adding two non-negative integers that contain at most N digits each. Note that we are adding the numbers in their base 10 representation.

For example, the following table shows the number of carries when adding some pairs of numbers:

A 	B 	Number of carries

20 	4 	0
111 	119 	1
123 	923 	1
1235 	98765 	5

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case has a single line containing an integer N.
Output

For each test case, output a single line containing the required expected value.
Your answer will be accepted if the error is less than 10^-6.
Constraints

    1 ≤ T ≤ 100,000(10^5)
    1 ≤ N ≤ 100,000(10^5)

Example

Input:
3
1
2
3

Output:
0.45
0.945
1.4445

Explanation

Example case 1.
We have 10*10 = 100 cases of adding two 1-digit number.
The carry appears when adding 1 and 9, 2 and 9, 3 and 9 ... and so on,
there are 45 cases in total and in each case, the carry appears exactly once.

= cut
