#!/usr/bin/perl
use bigint;
$t=<STDIN>;
@k=();
for($i = 0; $i < $t; $i++)
{
	$k[$i] = <STDIN>;
	exit 0 if $k[$i] < 1;
	exit 0 if $k[$i] > 2000000000000;
}
for($i=0;$i<$t;$i++)
{
	$b=192;
	$b=$b+(250*($k[$i]-1));
	print "\n$b";
}

=comment

Pattern Matchers have been designed for various sorts of patterns. Mr. HKP likes to observe patterns in numbers. After completing his extensive research on the squares of numbers, he has moved on to cubes. Now he wants to know all numbers whose cube ends in 888.

Given a number k, help Mr. HKP find the kth number (indexed from 1) whose cube ends in 888.

Input

The first line of the input contains an integer t, the number of test cases. t test cases follow.

Each test case consists of a single line containing a single integer k (1 <= k <= 2000000000000).

Output

For each test case, output a single integer which denotes the kth number whose cube ends in 888. The result will be less than 263.

Example

Input:
1
1

Output:
192
= cut

