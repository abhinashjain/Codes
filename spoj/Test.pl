#!/usr/bin/perl
@userinput = <STDIN>;
foreach $ui (@userinput) 
{	
	last if($ui == 42);
        print "$ui";
}
