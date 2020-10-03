#!/usr/bin/perl

while($i<10)
{
	$i++;
	$c=1;
	@a=split("",<STDIN>);
	foreach $b(@a)
	{
		$c*=2 if(($b eq "T")||($b eq "L")||($b eq "D")||($b eq "F"));
	}
	print "\n$c";
}
