import java.util.Scanner;
import java.math.BigInteger;

class Main {
    private static int C(int n,int r)
    {
        BigInteger c = BigInteger.ONE;
        for(int i=1;i<=r;i++)
            c = c.multiply(BigInteger.valueOf(n-i+1)).divide(BigInteger.valueOf(i));
        return c.toString().length();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int r = sc.nextInt();
            System.out.println(C(n,r));
        }
    }
}
