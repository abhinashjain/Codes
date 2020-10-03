import java.math.BigInteger;
import java.util.Scanner;
public class Fctrl2
{
    public static void main(String[] args) 
    {
        int t;
        BigInteger bi=new BigInteger("1");
        BigInteger b=new BigInteger("1");
        BigInteger mul=new BigInteger("100");
        BigInteger [] n = new BigInteger [100];
        Scanner in = new Scanner(System.in);
        t = in.nextInt();
        if (t > 100 || t < 1)
        {
            System.exit(0);
        }
        for(int i = 0; i < t; i++)
        {
            n[i] = in.nextBigInteger();
            if (n[i].compareTo(mul) > 0 || n[i].compareTo(b) < 0)
            {
                System.exit(0);
            }
        }
        for(int i = 0; i < t; i++)
        {     
            bi=new BigInteger("1");
            while(n[i].compareTo(b)>0)
            {   
                bi=bi.multiply(n[i]);
                n[i]=n[i].subtract(b);
            }
            System.out.println(bi.toString());
        }            
    }
}

/* You are asked to calculate factorials of some small positive integers.
Input

An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.
Output

For each integer n given at input, display a line with the value of n!
Example
Sample input:

4
1
2
5
3

Sample output:

1
2
120
6 
*/
