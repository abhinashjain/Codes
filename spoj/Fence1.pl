#!/usr/bin/perl

while(($t=<STDIN>) != 0)
{
	$r=$t/3.14159;
	$a=sprintf('%.2f',($r*$t)/2);
	print "$a\n";
}

=comment

There is a wall in your backyard. It is so long that you can’t see its endpoints. You want to build a fence of length L such that the area enclosed between the wall and the fence is maximized. The fence can be of arbitrary shape, but only its two endpoints may touch the wall.
Input

The input consists of several test cases.

For every test case, there is only one integer L (1<=L<=100), indicating the length of the fence.

The input ends with L=0.
Output

For each test case, output one line containing the largest area. Your answer should be rounded to 2 digits after the decimal point.
Example

Input:
1
0

Output:
0.16

= cut
