#!/usr/bin/perl 
use bigint;

$t=<STDIN>;
exit 0 if $t > 30;
@a=();
@b=();
@d=();
for($i=0;$i<$t;$i++)
{
	($a[$i],$b[$i])=split(' ',<STDIN>);
	if(($a[$i]<0)||($b[$i]<0)||($b[$i]>922000000000000000))
	{
		exit 0;
	}	
	$m=$a[$i]%10;
	if($b[$i]!=0)
	{
		if(($m==0)||($m==1)||($m==5)||($m==6))
		{
			$d=$m;
		}	
		if($m==2)
		{
			$n=$b[$i]%4;
			$d=2 if $n==1;
			$d=4 if $n==2;
			$d=8 if $n==3;
			$d=6 if $n==0;
		}	
		if($m==3)
		{
			$n=$b[$i]%4;
			$d=3 if $n==1;
			$d=9 if $n==2;
			$d=7 if $n==3;
			$d=1 if $n==0;
		}	
		if($m==4)
		{
			$n=$b[$i]%2;
			$d=4 if $n==1;
			$d=6 if $n==0;
		}	
		if($m==7)
		{
			$n=$b[$i]%4;
			$d=7 if $n==1;
			$d=9 if $n==2;
			$d=3 if $n==3;
			$d=1 if $n==0;
		}	
		if($m==8)
		{
			$n=$b[$i]%4;
			$d=8 if $n==1;
			$d=4 if $n==2;
			$d=2 if $n==3;
			$d=6 if $n==0;
		}	
		if($m==9)
		{
			$n=$b[$i]%2;
			$d=9 if $n==1;
			$d=1 if $n==0;
		}	
	}
	else
	{
		$d=0 if $a[$i]==0;
		$d=1 if $a[$i]!=0;
	}
	print "\n$d";
}

=comment

Pappu was doing the work of his math class about three days but he is tired of make operations a lot and he should deliver his task tomorrow. His math’s teacher gives two numbers a and b. The problem consist in find the last digit of the potency of base a and index b. Help Pappu with his problem. You are given two integer numbers: the base a (number of digits d, such that 1<=d<=1000) and the index b (0 <= b <= 922*10^15). You
have to find the last digit of a^b.

                                                         Input
The first line of input contains an integer t, the number of test cases (t <= 30). t test cases follow. For
each test case will appear a and b separated by space.

                                                         Output
For each test case output an integer per line representing the result.

Example
Input:
5
3 10
6 2
150 53
0 0
3 0
Output:
9
6
0
0
1
= cut
