#!/usr/bin/perl

@input = <STDIN>;
chomp(@input);
$len=scalar(@input);
for($i=($len-1);$i>=0;$i--)
{
	print scalar reverse("$input[$i]")."\n";
}



=comment

Planet Zorg is inhabited by Koanes. Koanes vision is topsy turvy.

For example,

for humans the text is visible as

123
223
323
423
523
623

for Koanes, the same text is seen as

326
325
324
323
322
321

Task

Your task is to take a read a set of characters and print the Koanes format of the same characters as output.

Constraints

The testcases are similar to the ones mentioned in the example above. 

= cut
