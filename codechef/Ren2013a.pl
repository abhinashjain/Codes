#!/usr/bin/perl
use List::Util qw( min max );

$t=<>;
for($i=0;$i<$t;$i++)
{
	($a,$b)=split(' ',<>);
	@arr=split('',$a);
	$len=scalar(@arr)-1;
	$max=max @arr;
	$base=1;
	$sum1=0;
	for($j=$len;$j>=0;$j--)
	{
		$sum1+=($arr[$j]*$base);
		$base*=($max+1);
	}
	@arr=split('',$b);
	$len=scalar(@arr)-1;
	$max=max @arr;
	$base=1;
	$sum2=0;
	for($j=$len;$j>=0;$j--)
	{
		$sum2+=($arr[$j]*$base);
		$base*=($max+1);
	}
	$ans=$sum1+$sum2;
	print "$ans\n";
}

=comment

Given two integers A and B that are not necessarily in base-10, find the smallest possible A + B in base-10.

For example,
A = 213, possibly base-4 (39 in base-10)
B = 4721, possibly base-8 (2513 in base-10)
A + B = 39 + 2513 = 2552 

Input
First line of the input contains a positive integer T (1 <= T <= 100), the number of cases. Each case contains
two positive integers A and B. A and B will contain at most 5 digits, each digit will be between 0 and 9,
inclusive, and no leading zeroes.

Output
For each case, output an integer in base-10 denoting the smallest possible A + B.

Example
Input:
3
213 4721
1001 90
638 241

Output:
2552
99
592

= cut
