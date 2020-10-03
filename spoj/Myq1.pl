#!/usr/bin/perl
use integer;

$t=<STDIN>;
for($i=0;$i<$t;$i++)
{
	$n=<STDIN>;
	if($n==1)
	{
		print "poor conductor\n";
	}
	else
	{
		$z=($n-1)/5;
		$z++	if(($n-1)%5!=0);
		if($n%5==1 || $n%5==2)
		{
			$sp='W';
		}
		else
		{
			if($n%5==4 || ($n%5==3 && $z%2==1) || ($n%5==0 && $z%2==0))
			{
				$sp='A';
			}
			else
			{
				$sp='M';
			}
		}
		if($z%2==1)
		{
			if($n%5==2 || $n%5==3)
			{
				$d='L';
			}
			else
			{
				$d='R';
			}
		}
		else		
		{
			if($n%5==0 || $n%5==1)
			{
				$d='L';
			}
			else
			{
				$d='R';
			}
		}
		print "$z $sp $d\n";
	}
}

=comment
The seats of an Ultra Deluxe Semi-sleeper bus in Thuvax country are numbered according to the following rules:
 
1. Seat number 1 is reserved for the bus conductor.
2. Remaining seats are numbered as shown in the figure below:
 
The seating arrangement is as shown below
 
RowNo Left   Right  
      W  A   A  M  W
                 
      01
1     02 03  04 05 06
2     11 10  09 08 07
3     12 13  14 15 16
4     21 20  19 18 17
5     22 ............
 
A blind person enters the bus with a reservation ticket mentioning his seat number. He meets you at the start of the passage and shows you his ticket. Based on the seat number, help him find his seat by telling him the row number (1,2,...), seat position(window or aisle or middle), and the direction(left or right).
Input

First line contains a positive integer t(t<=10^5) denoting the number of test cases.
Each of the next t lines contain a positive integer n(n<=10^9) denoting the blind person's seat number.
Output

Output one line for every test case in the following format:
If the seat number is same as the conductor's seat, print "poor conductor" else,
print <row_number> <seat_position> <direction>
row_number: represents the row number from the entrance (a positive integer)  
seat_position: can be one of "W" or "A" or "M" for window, aisle and middle respectively.
direction: can be either "L" or "R" for left or right respectively.
Example

Input:
3 
1 
2 
3

Output:
poor conductor 
1 W L 
1 A L
= cut
