import java.util.*;
import java.math.*;
public class Main
{
 
        public static void main(String[] args)
        {
                Scanner scan = new Scanner(System.in);
                int t = scan.nextInt();
 
                for ( int i = 0; i < t; i++)
                {
                        BigInteger l = new BigInteger(scan.next());
                        scan.next();
                        BigInteger m = new BigInteger(scan.next());
                        BigInteger nwd = l.gcd(m);
                        l = l.divide(nwd);
                        m = m.divide(nwd);
                        System.out.println(l+ " / "+ m);
                }
        }
}