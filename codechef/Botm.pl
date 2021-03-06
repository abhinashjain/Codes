#!/usr/bin/perl

$t=<STDIN>;
for($i=0;$i<$t;$i++)
{
	$n=<STDIN>;
	@p=split(' ',<STDIN>);
	@p=sort{$a <=> $b} @p;
	$mid=$n/2;
	$mov=0;
	for($j=0;$j<scalar(@p);$j++)
	{
		if($p[$j]>$p[$mid])
		{
			$mov+=$p[$j]-$p[$mid];
		}
		else
		{
			$mov+=$p[$mid]-$p[$j];
		}
	}
	print "$mov\n";
}


=comment

A lazy guy in UVCE is designing a robot that could collect all useful things from different places and put them in one place. In its testing stage robot is given a task. 10^5 boxes are arranged is straight line and they numbered from 1 to 10^5. Some boxes contain useful things, bot has to collect all the useful things and put them in one box (any one from 1 to 10^5) in minimum number of moves.

A move is said to be done if the robot moves from one box to its adjacent box with an useful thing in its hand. It can carry only one useful thing at a time.

As we know the owner of that bot is very lazy and want some help. You are given the positions of boxes which has the useful things in the test setup. Print the minimum number of moves required to complete the task.
INPUT

First line of input contains T, number of test cases,

First line of each test case contains N, number of useful boxes.
Next line contains N space separated integers Pi, positions of useful things.
OUTPUT

For each test case output the minimum number of moves required to complete the task.
CONSTRAINTS

    1 ≤ T ≤ 100
    1 ≤ N ≤ 10^5
    1 ≤ Pi ≤ 10^5

EXAMPLE

Input

2
5
1 2 3 4 5
6
0 1 2 3 4 5

Output

6
9
 
= cut
