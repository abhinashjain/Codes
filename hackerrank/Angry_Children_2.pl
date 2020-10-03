#!/usr/bin/perl

$tmp=0;
$sum=0;
$j=1;
@cand=();
$cand[0]=-1;
$n=<STDIN>;
$k=<STDIN>;
for($i=1;$i<=$n;$i++)
{
	$cand[$i]=<STDIN>;    
}
@cand=sort{$a <=> $b} @cand;
for($mul=$k-1;$mul>0;$mul-=2)
{
	$sum+=$mul*($cand[$mul+$j]-$cand[$j]);
	$j++;
}
$unfair=$sum;
for($i=2;$i<=$k;$i++)
{
	$tmp+=$cand[$i];
}
for($i=2;$i<=($n-$k+1);$i++)
{
	$sum+=((($k-1)*($cand[$i-1]+$cand[$k+$i-1]))-2*$tmp);
	$tmp+=$cand[$k+$i-1]-$cand[$i];
	$unfair=$sum	if($sum<$unfair);		
}
print "$unfair\n";



=comment

Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.

Suppose the K packets have (x1, x2, x3,….xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as

Summation of |xi-xj| where 1<= i<j <=k

where |a| denotes the absolute value of a.

Input Format
The first line contains an integer N.
The second line contains an integer K. N lines follow each integer containing the candy in the ith packet.

Output Format
A single integer which will be minimum unfairness.

Constraints
2<=N<=10^5
2<=K<=N
0<= number of candies in each packet <=10^9

Sample Input #00
7
3
10
100
300
200
1000
20
30

Sample Output #00
40

Explanation #00
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |30-10| = 40. It will be minimum as compared to any other distribution which can be verified .


Sample Input #01
10
4
1
2
3
4
10
20
30
40
100
200

Sample Output #01
10

Explanation #01
Bill Gates will choose 4 packets having 1,2,3 and 4 candies. So, unfairness will be |1-2| + |1-3| + |1-4| + |2-3| + |2-4| + |3-4| = 10

= cut
