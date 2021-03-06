#!/usr/bin/perl

@inp=();
@arr=();
$n=<STDIN>;
@inp=split(' ',<STDIN>);
$q=<STDIN>;
$t=0;
$cnt=0;
for($i=0;$i<$n;$i++)
{
	if($inp[$i]<0)
	{
		$arr[$t]=$inp[$i]*(-1);
		$cnt+=$arr[$t];
		$t++;
	}
}
if($q<$t)
{
	@arr=sort {$a <=> $b} @arr;
	$j=$t-($q+1);
	$cnt=$q*$arr[$j];
	for($i=$j+1;$i<$t;$i++)
	{
		$cnt+=($arr[$i]-$arr[$j]);
	}
}
print "$cnt\n";



=comment

Chef has an array of N integers. He wants to play a special game. In this game he needs to make all the integers in the array greater than or equal to 0.

Chef can use two types of operations. The first type is to increase all the integers of the given array by 1, but it costs X coins. The operation of the second type is to add 1 to only one integer of the given array and to use this operation you need to pay 1 coin. You need to calculate the minimal cost to win this game (to make all integers greater than or equal to 0)
Input

The first line of the input contains an integer N denoting the number of elements in the given array. The second line contains N space-separated integers A1, A2, ..., AN denoting the given array. The third line contains number X - cost of the first type operation.
Output

For each test case, output a single line containing minimal cost required to make all the integers greater than or equal to zero.
Constraints

    1 ≤ N ≤ 10^5
    -10^9 ≤ Ai ≤ 10^9
    0 ≤ X ≤ 10^9

Example

Input:
3
-1 -2 -3
2

Output:
5

Explanation

Example case 1: Use the first type operation twice and the second type once.

= cut
