#!/usr/bin/perl

$file="$ARGV[0]";
open(INPUT,"$file");
$t = <INPUT>;
for($i=1;$i<=$t;$i++)
{
	@str = split(undef,<INPUT>);
	@normal=();	
	@happy=();
	@sad=();
	$j=0;
	$r=0;
	$p=0;
	while($j < scalar(@str))
	{
		if(($str[$j] eq ":") && (($str[$j+1] eq "(") || ($str[$j+1] eq ")")))
		{
			if($str[$j+1] eq "(")
			{
				unshift(@sad, $j);
			}
			if($str[$j+1] eq ")")
			{
				unshift(@happy, $j);
			}
			$j++;
		}
		else
		{
			if($str[$j] eq "(")
			{
				unshift(@normal, $j);
			}			
			if($str[$j] eq ")")
			{
				if(scalar(@normal) > 0)
				{
					shift @normal;
				}
				else
				{
					$p=1;
					if(scalar(@sad) > 0)
					{
						shift @sad;
					}	
					else
					{
						$r=1;
						last;
					}				
				}
			}
		}
		$j++;
	}
	if($r==0)
	{
		$len=scalar(@normal);
		$haplen=scalar(@happy);
		if($len == 0)
		{
			if($p == 0)
			{
				print "Case #$i: YES"."\t"."Equal\n";
			}
			else
			{
				print "Case #$i: YES"."\t"."Equal with help of sad\n";
			}
		}
		else
		{
			if($len > $haplen)
			{
				print "Case #$i: NO"."\t"."Open more than happy\n";
			}
			else
			{
				@extra=();
				while($haplen>0)
				{
					$haplen--;
					$extra[$haplen] = (shift @happy);
				}
				$haplen=scalar(@extra);
				while($len>0)
				{
					$q=0;
					for($e=0;$e<$haplen;$e++)
					{
						$pop=(shift @normal);
						if($pop<$extra[$e])
						{
							$extra[$e]=-1;
							$q=1;
							last;
							#print "Case #$i: NO"."\t"."open not in proper with happy\n";	
						}
						else
						{
							unshift(@normal,$pop);
						}
					}
					if($q == 0)
					{
						print "Case #$i: NO"."\t"."open mis placed with happy\n";
						last;
					}
					$len--;
				}
				if($len == 0)
				{
					print "Case #$i: YES"."\t"."open balanced with happy\n";
				}
			}
		}
	}
	else
	{
		print "Case #$i: NO"."\t"."closed more than sad and open\n";
	}
}


=comment

Your friend John uses a lot of emoticons when you talk to him on Messenger. In addition to being a person who likes to express himself through emoticons, he hates unbalanced parenthesis so much that it makes him go :(

Sometimes he puts emoticons within parentheses, and you find it hard to tell if a parenthesis really is a parenthesis or part of an emoticon.

A message has balanced parentheses if it consists of one of the following:

    - An empty string ""
    - One or more of the following characters: 'a' to 'z', ' ' (a space) or ':' (a colon)
    - An open parenthesis '(', followed by a message with balanced parentheses, followed by a close parenthesis ')'.
    - A message with balanced parentheses followed by another message with balanced parentheses.
    - A smiley face ":)" or a frowny face ":("

Write a program that determines if there is a way to interpret his message while leaving the parentheses balanced.
Input

The first line of the input contains a number T (1 ≤ T ≤ 50), the number of test cases.
The following T lines each contain a message of length s that you got from John.
Output

For each of the test cases numbered in order from 1 to T, output "Case #i: " followed by a string stating whether or not it is possible that the message had balanced parentheses. If it is, the string should be "YES", else it should be "NO" (all quotes for clarity only)
Constraints

1 ≤ length of s ≤ 100

 
Example input

5
:((
i am sick today (:()
(:)
hacker cup: started :):)
)(

Example output

Case #1: NO
Case #2: YES
Case #3: YES
Case #4: YES
Case #5: NO

= cut
