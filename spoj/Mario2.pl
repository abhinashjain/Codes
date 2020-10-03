#!/usr/bin/perl

$t = <STDIN>;
for($i = 1; $i <= $t; $i++)
{
	$inp = <STDIN>;
	($m,$k) = split(' ',$inp);
	$m = ($m * $k) + 1;
	$k = $k + $m;
	$k = (1/$k);
	$k = sprintf("%.8f", $k);
	print "\nCase #$i: $k";
}

=comment

Mario usually relaxes himself by walking along the shady track near the Mushroom Kingdom. The evil King Koopa noticed that and placed a lot of mushroom on the road. There are two types of mushrooms, max mushrooms and bad mushrooms. The bad mushrooms will decrease Mario's HP by m points, on the other hand, max mushrooms will increase Mario's HP by one point. The mushrooms are randomly placed on the track and Mario will receive them one by one. Once Mario's HP becomes zero or below after he received a mushroom, he will die.

Notice that Mario begins with HP zero, so if the first mushroom is bad, Mario will die immediately. Fortunately, if Mario receives all the mushrooms, he will be alive with HP 1. In the other words, if there are k bad mushrooms on the way, there will also be m*k+1 max mushrooms.

Princess Peach wants to know the possibility for Mario staying alive. Please help her to calculate it out.
Input

There are several test cases. The first line contains only one integer denoting the number of test cases.

For each test case, there is only one line including two integers: m and k, denoting the amount of points of HP the Mario will decrease if he receives a bad mushroom, and the number of bad mushrooms on the track. (1 <= m <= 1000, 1 <= k <= 1000)
Output

For each test case, output only real number denoting the possibility that Mario will survive if he receives all the randomly placed mushrooms one by one. The answer should be rounded to eight digits after the decimal point.

The judge is "ignoring extra white spaces".
Example

Input:
2
1 1
60 80

Output:
Case #1: 0.33333333
Case #2: 0.00020488

= cut
