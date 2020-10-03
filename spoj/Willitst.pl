#!/usr/bin/perl
use bignum;

$n=<STDIN>;
while($n > 1)
{
	if (($n % 2) == 0)
	{
		$n=$n/2;
	}
	else
	{		
		print "\nNIE";
		exit 0;
	}		
}
print "\nTAK";

=comment

When Bob was in library in University of Warsaw he saw on one of facades caption :"Will it ever stop?" and below some mysterious code:

while n > 1
  if n mod 2 = 0 then
    n:=n/2
  else
    n:=3*n+3

Help him finding it out !
Input

In first line one number n<=10^14.

Output

Print "TAK" if program will stop, otherwise print "NIE"

Example

Input:
4

Output:
TAK

= cut
