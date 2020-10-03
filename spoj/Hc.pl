#!/usr/bin/perl

$t=<STDIN>;
for($i=0;$i<$t;$i++)
{
	$l=0;
	$n=<STDIN>;
	for($j=0;$j<$n;$j++)
	{
		@m=split('',<STDIN>);
		$l++	if($m[0] eq 'l');
	}
	if($l%2==1)
	{
		print "lxh\n";
	}
	else
	{
		print "hhb\n";			
	}
}

=comment

A line of coins are given, some belongs to lxh while others belongs to hhb. Now the two guys are about to play a game. In every round of game, each player can select any two consecutive coins and change them into one coin, if the two coins belongs to the same person, the new one will be gained to hhb, or else it will belongs to lxh. The two guys take turns playing this game, lxh always play first. The game runs round by round. You can easily make sense that we will get only one coin at the end of game. Now the question is, suppose the two players perform optimally in the game, which person does the final coin belongs to?

Input
The first line of the input contains one integer T, which indicate the number of test cases.

Following each test, the first line contains an integer N (N ≤ 105), the number of coins. Following N lines, each line contains a name, lxh or hhb, the name of whom this coins belongs to.
Output
For each case, output a line contains the name of whom the final coin belongs to.
Sample Input

1
2
lxh
hhb

Sample Output

lxh

= cut
