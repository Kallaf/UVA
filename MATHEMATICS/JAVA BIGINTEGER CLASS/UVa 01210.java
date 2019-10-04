import java.util.Scanner;
import java.util.ArrayList;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        ArrayList<Integer> primes = new ArrayList<>();
        for(int i=2;i<=10000;i++)
            if(BigInteger.valueOf(i).isProbablePrime(10))primes.add(i);
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            if(n==0)break;
            int ans = 0;
            for(int i=0;i<primes.size();i++)
            {
                int m = n - primes.get(i);
                for(int j=i+1;j<primes.size() && m >= 0;j++)
                {
                    if(m == 0)ans++;
                    m -= primes.get(j);
                }
            }
            System.out.println(ans);
        }
    }
}
