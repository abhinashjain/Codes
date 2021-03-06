#!/usr/bin/perl

$t=<STDIN>;
for($i=0;$i<$t;$i++)
{
	($ht1, $mt1, $st1)=split(' ',<STDIN>);
	($ht2, $mt2, $st2)=split(' ',<STDIN>);
	$sec=(($ht2-$ht1)*3600)+(($mt2-$mt1)*60)+($st2-$st1);
	$mtr=$sec%400;
	if($mtr<100 || ($mtr>=200 && $mtr<300))
	{
		print "S\n";
	}
	else
	{
		print "C\n";
	}
}


=comment

Gopal is running in the 400m track, which is oval in shape and first 100 (0-99)meter is straight, next 100(100-199) meter is curved in a semicircular form, next 100(200-299) meter is again a straight and next 100(300-399) meter is curved and reaches the start point. Now Gopal starts running from the start point with 1 meter/second speed at time T1.

Now his coach comes to the track at time T2. You have to determine whether Gopal is running is a straight track or in curved track, when his coach visits the track.
INPUT

First line of the input contains the T, number of testcases.
Each test case contains two lines.
First line contains 3 space seperated integers HT1, MT1, ST1, representing hour, minute and second of T1 respectively.
Second line contains same information as in previous line, HT2, MT2, ST2 about T2.
OUTPUT

For each testcase output "S" (without quotes) if Gopal is running in a straight line, otherwise output "C" (without quotes), when his coach visits.
CONSTRAINTS

    1 ≤ T ≤ 10000
    0 ≤ MT1,MT1,ST1,ST2 ≤ 59
    0 ≤ HT1,HT2 ≤ 23

EXAMPLE

Input

2
10 0 0
10 2 0
11 25 0
11 26 30

Output

C
S 

= cut
