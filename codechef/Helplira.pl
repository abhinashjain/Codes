#!/usr/bin/perl

$n=<STDIN>;
$sm=1000000000;
$lar=-1;
$indsm=-1;
$indlar=-1;
for($i=0;$i<$n;$i++)
{
	($x1,$y1,$x2,$y2,$x3,$y3)=split(' ',<STDIN>);
	$area=($x1*$y2 - $x1*$y3 + $x2*$y3 - $x2*$y1 + $x3*$y1 - $x3*$y2);
	$area=(abs($area))/2;
	if($area>=$lar)
	{
		$lar=$area;
		$indlar=$i+1;
	}
	if($area<=$sm)
	{
		$sm=$area;
		$indsm=$i+1;
	}
}
print "$indsm $indlar\n";



=comment

Lira is a little girl form Bytenicut, a small and cozy village located in the country of Byteland.

As the village is located on a somewhat hidden and isolated area, little Lira is a bit lonely and she needs to invent new games that she can play for herself.

However, Lira is also very clever, so, she already invented a new game.

She has many stones with her, which she will display on groups of three stones on the ground on a triangle like shape and then, she will select two triangles, one with the smallest area and one with the largest area as the most beautiful ones.

While it's easy for Lira to "estimate" the areas of the triangles by their relative sizes, it's harder for her to actually calculate these areas.

But, it turns out, that Lira is also friends with YOU, an exceptional Mathematics student, and she knew that you would know exactly how to do such verification.

Lira also numbered the triangles from 1 to N, and now she wants to know the indices of the triangles with the smallest and largest area respectively.

It is now up to you, to help Lira and calculate the areas of the triangles and output their numbers.
Input

The first line of the input file contains an integer, N, denoting the number of triangles on the given input file.

Then N lines follow, each line containing six space-separated integers, denoting the coordinates x1, y1, x2, y2, x3, y3

    Output

    You should output two space separated integers, the indexes of the triangles with the smallest and largest area, respectively.

    If there are multiple triangles with the same area, then the last index should be printed.
    Constraints
        2 ≤ N ≤ 100
        -1000 ≤ xi, yi ≤ 1000

     
    Example

    Input:
    2
    0 0 0 100 100 0
    1 1 1 5 5 1

    Output:
    2 1
    
= cut