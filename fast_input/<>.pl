#!/usr/bin/perl

my($n,$k) = split(/ /,<>);
$cnt = 0;
for(1..$n)
{
	$cnt++ if(<> % $k ==0);
}
print $cnt;
