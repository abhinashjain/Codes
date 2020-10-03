#!/usr/bin/perl

$t=<STDIN>;
for($i=0;$i<$t;$i++)
{
	$n=<STDIN>;
	$cnt=0;
	$k=$n;
	while($k>0)
	{
		$dgt=$k%10;
		if($dgt==3 || $dgt==5 || $dgt==6)
		{
			$cnt++;
			last;
		}
		$k=$k/10;
	}
	if($n&1)
	{
		$inc=2;
		$begin=3;
	}
	else
	{
		$inc=1;
		$begin=2;
	}
	for($j=$begin;$j*$j<=$n;$j+=$inc)
	{
		if($n % $j==0)
		{
			$k=$j;
			while($k>0)
			{
				$dgt=$k%10;
				if($dgt==3 || $dgt==5 || $dgt==6)
				{
					$cnt++;
					last;
				}
				$k=$k/10;
			}
			$k=$n/$j;
			while($k>0)
			{
				$dgt=$k%10;
				if($dgt==3 || $dgt==5 || $dgt==6)
				{
					$cnt++;
					last;
				}
				$k=$k/10;
			}
		}
	}
	print "$cnt\n";
}


=comment

You have a number N and you want to calculate how many divisors of N are special.

A number is said to be special if it is possible to remove some digits from it to get a number having 3, 5 or 6 only.For exemple number 38597 is special since it is posible to remove digits 8, 9, 7 to get 35. You can remove some digits but not all digits. You can remove digits from left, right or middle.
Constraints

1 <= T <= 10
1 <= N <= 10^9

Input

First line of input containes an integer T, number of test cases and then t test cases follow. Each test case is of one line containing an integer N.
Output

Output is of T lines, one for each test case. Each line contains number of special devisiors of respective test case.
Example
Input:
2
15
75

Output
3
5

= cut
