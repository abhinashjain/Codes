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
		if($dgt==4 || $dgt==7)
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
				if($dgt==4 || $dgt==7)
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
				if($dgt==4 || $dgt==7)
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

Maxim likes dividers of the numbers. Also Maxim is fond of lucky numbers of small elephant from Lviv city.

If you remember, lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky, 5, 17, 467 — aren't.

Now Maxim is interested in the next information: what is the number of the integer positive dividers of number n, which are overlucky.

We call number overlucky if it is possible to remove some, but not all, digits and during bonding the remaining digits we will receive a lucky number. For example, number 72344 — overlucky, because it is possible to remove digits 2 and 3, and get number 744, which is lucky. Number 223 isn't overlucky.

 
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. Single line of each test case contains an integer n.

 
Output

    For each test case on different lines print the answer to the problem.

Constraints

    1 ≤ T ≤ 10
    1 ≤ n ≤ 10^9

 
Example

Input:
10
1
2
3
4
5
6
7
8
9
10

Output:
0
0
0
1
0
0
1
1
0
0

= cut
