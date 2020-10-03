#!/usr/bin/perl
use List::Util qw(reduce);

$t=<>;
for($i=0;$i<$t;$i++)
{
	$n=<>;
	@arr=split(' ',<>);
	$vvsum=$cnt=0;
	$aasum=reduce { $a + $b } @arr;
	@arr=sort {$a <=> $b} @arr;
	for($j=$n-1;$j>=0;$j--)
	{
		$cnt++;
		$vvsum+=$arr[$j];
		$aasum-=$arr[$j];
		last if($vvsum>$aasum);			
	}
	print "$cnt\n";
}


=comment

AA and VV are best friends, but not when there are chocolates at stake. So as the story goes, VV wins a competition at school and is awarded a box of N chocolates, each of varying taste. Now, AA demands that this box to be shared and after a heated discussion VV agrees to do so. However, he now plans of having the best from his box .

You are given a box of N chocolates, with their taste value given for each chocolate . The ith integer tells the taste value of the ith chocolate. VV plans to have a subset of these chocolates such that the sum value is strictly greater than the taste value of the remaining, and to keep AA happy, he tries to find the minimum such number of chocolates possible. He asks you for help .

Input
Number of test cases, T. Each test case consists of an integer N, and then N integers xi on the next line.

Output
Output the minimum number of chocolates such that the sum of taste value that VV gets is greater than the chocolates that AA gets .

Constraints
T <= 100
N <= 100
0 < xi <= 100

Sample Input :-
2

3
2 2 3

4
1 1 4 8

Sample Output :-
2
1

= cut
