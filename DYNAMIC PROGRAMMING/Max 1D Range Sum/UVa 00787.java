import java.util.Scanner;
import java.math.BigInteger;

class Main {
    private static BigInteger[] product = new BigInteger[105];
    private static int n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        product[0] = BigInteger.ONE;
        while (sc.hasNext()) {
            n=1;
            for(int in = sc.nextInt();in !=  -999999;in = sc.nextInt(),n++)
            {
                product[n] = BigInteger.valueOf(in);
                if(product[n-1].compareTo(BigInteger.ZERO) != 0)
                    product[n] = product[n].multiply(product[n-1]);
            }
            BigInteger mx = product[n-1];
            for(int i=1;i<n;i++)
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(product[j].compareTo(BigInteger.ZERO) == 0)
                        break;
                
                    BigInteger div = product[i].divide(product[j]);
                    if(mx.compareTo(div) < 0)
                        mx = div;
                }
            }
            System.out.println(mx);
        }
    }
}
