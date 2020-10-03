#!/usr/bin/perl
$t = <STDIN>;
exit 0 if $t > 15;
exit 0 if $t < 1;
@arr=();
@m=();
@n=();
@o=();
for($i = 0; $i < $t; $i++)
{
	$inp = <STDIN>;
	exit 0 if $inp > 40;
	exit 0 if $inp < 2;
	for($j = 0; $j < $inp; $j++)
	{
		$arr[$i] = <STDIN>;
		($m[$i][$j], $n[$i][$j], $o[$i][$j]) = split(' ',$arr[$i], 3);
	}
	for($k = 0; $k < $inp; $k++)
	{
		$z = $k;
		$z++;
		if($k == ($inp - 1))
		{			
			$m[$i][$k] = "Begin";
			last;
		}
		if($m[$i][$z] eq "Left")
		{
			$m[$i][$k] = "Right";
		}
		else 
		{
			if($m[$i][$z] eq "Right")
			{
				$m[$i][$k] = "Left";
			}
		}
	}
}
for($i = 0; $i < $t; $i++)
{
	for($j = 40; $j >= 0; $j--)
	{
		print "\n$m[$i][$j]";
		print " $n[$i][$j]";
		print " $o[$i][$j]";
	}
}


=comment    problem statement


Chef recently printed directions from his home to a hot new restaurant across the town, but forgot to print the directions to get back home. Help Chef to transform the directions to get home from the restaurant.

A set of directions consists of several instructions. The first instruction is of the form "Begin on XXX", indicating the street that the route begins on. Each subsequent instruction is of the form "Left on XXX" or "Right on XXX", indicating a turn onto the specified road.

When reversing directions, all left turns become right turns and vice versa, and the order of roads and turns is reversed. See the sample input for examples.
Input

Input will begin with an integer T, the number of test cases that follow. Each test case begins with an integer N, the number of instructions in the route. N lines follow, each with exactly one instruction in the format described above.
Output

For each test case, print the directions of the reversed route, one instruction per line. Print a blank line after each test case.
Constraints

    1 ≤ T ≤ 15
    2 ≤ N ≤ 40
    Each line in the input will contain at most 50 characters, will contain only alphanumeric characters and spaces and will not contain consecutive spaces nor trailing spaces. By alphanumeric characters we mean digits and letters of the English alphabet (lowercase and uppercase).

Sample Input

2
4
Begin on Road A
Right on Road B
Right on Road C
Left on Road D
6
Begin on Old Madras Road
Left on Domlur Flyover
Left on 100 Feet Road
Right on Sarjapur Road
Right on Hosur Road
Right on Ganapathi Temple Road

Sample Output

Begin on Road D
Right on Road C
Left on Road B
Left on Road A

Begin on Ganapathi Temple Road
Left on Hosur Road
Left on Sarjapur Road
Left on 100 Feet Road
Right on Domlur Flyover
Right on Old Madras Road

Explanation

In the first test case, the destination lies on Road D, hence the reversed route begins on Road D. The final turn in the original route is turning left from Road C onto Road D. The reverse of this, turning right from Road D onto Road C, is the first turn in the reversed route.
= cut
