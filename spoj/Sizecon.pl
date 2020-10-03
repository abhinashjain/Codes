#!/usr/bin/perl

#$s=0;
$t=<STDIN>;
while($i<$t)
{
	$i++;
	$a=<STDIN>;
	$s+=$a if($a>0);
}
print "$s";


=comment

Given the set of integers, find the sum of all positive integers in it.
Input

t – number of test cases [t < 1000]
On each of next t lines given a integer N [-1000 <= N <= 1000]

Output

One integer equals to sum of all positive integers.

Score

Score equals to size of source code of your program except symbols with ASCII code <= 32.

Example

Input:
4
5
-5
6
-1
Output:
11

= cut
