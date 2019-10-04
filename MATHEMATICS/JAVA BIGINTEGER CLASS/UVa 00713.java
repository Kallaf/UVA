import java.util.Scanner;
import java.math.BigInteger;

class Main {
    /* UVa 10235 - Simply Emirp */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        while (N-- > 0) {
            BigInteger num1 = sc.nextBigInteger();
            BigInteger num2 = sc.nextBigInteger();
            String num1S = new StringBuffer(num1.toString()).reverse().toString();
            String num2S = new StringBuffer(num2.toString()).reverse().toString();
            num1 = new BigInteger(num1S);
            num2 = new BigInteger(num2S);
            System.out.println(new BigInteger(new StringBuffer(num1.add(num2).toString()).reverse().toString()));
        }
    }
}
