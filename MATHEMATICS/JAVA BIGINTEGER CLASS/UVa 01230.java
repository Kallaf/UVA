import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            BigInteger x = BigInteger.valueOf(sc.nextInt());
            BigInteger y = BigInteger.valueOf(sc.nextInt());
            BigInteger n = BigInteger.valueOf(sc.nextInt());
            System.out.println(x.modPow(y,n));
        }
    }
}
