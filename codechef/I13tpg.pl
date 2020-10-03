#!/usr/bin/perl

$s=<STDIN>;
chomp($s);
@arr=split('',$s);
%hash=();
for($i=0;$i<scalar(@arr);$i++)
{
	if(!exists $hash{$arr[$i]})
	{
		$hash{$arr[$i]}=1;
	}
	else
	{
		$hash{$arr[$i]}++;
	}
}
while (($key, $value) = each(%hash))
{
	$odd++ if($value%2 == 1);
}
if(($odd==0) || (($odd%2) == 1))
{
	print "Ram";
}
else
{
	print "Shyam";
}

=comment
 There was a big fight between the brothers Ram and Shyam as to who would play on the computer. Their mother got irritated and in order to quiten them thought up a game.
They were given a string s, consisting of lowercase English letters. They play a game that is described by the following rules:

The players move in turns; In one move the player can remove an arbitrary letter from string s.
If the player before his turn can reorder the letters in string s so as to get a palindrome, this player wins. A palindrome is a string that reads the same both ways (from left to right, and vice versa). For example, string "abba" is a palindrome and string "abc" isn't.
Determine which player will win, provided that both sides play optimally well the one who moves first(Ram) or the one who moves second(Shyam).The brother winning will play his favourite game!

Input:
The input contains a single line, containing string s . String s consists of lowercase English letters.

Output:
In a single line print word "Ram" if the first player wins (provided that both players play optimally well). Otherwise, print word "Shyam". Print the words without the quotes.

Sample Input 1:
aba

Sample Output 1:
Ram

Sample Input 2:
abca

Sample Output 2:
Shyam

Constraints:
1<=|s|<=10^6
Time Limit:1 s

You will also be judged on the size of your code.

= cut
