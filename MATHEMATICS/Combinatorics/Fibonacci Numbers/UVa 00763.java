import java.util.Scanner;
import java.math.BigInteger;

class Main {
    private static BigInteger[] fb = new BigInteger[500];
    private static void setFb()
    {
        fb[0] = BigInteger.ONE;
        fb[1] = fb[0].add(fb[0]);
        for(int i=2;i<=301;i++)
            fb[i] = fb[i-1].add(fb[i-2]);
    }

    private static int nearestSmallerEqFib(BigInteger key) {
        int len = fb.length;
        int lo = 0;
        int hi = len-1;
        int mid = (lo + hi)/2;
        while (true) {
            int cmp = fb[mid].compareTo(key);
            if (cmp == 0 || cmp < 0) {
                lo = mid+1;
                if (hi < lo)
                    return mid;
            } else {
                hi = mid-1;
                if (hi < lo)
                    return mid<len-1?mid-1:-1;
            }
            mid = (lo + hi)/2;
        }
    }

    private static String fbRep(BigInteger n)
    {
        if (n.equals(BigInteger.ZERO))
            return "0";
        if(n.equals(BigInteger.ONE)) 
            return "1";
        
        String res = "";
        boolean[] isOne = new boolean[300];
        int fmax = -1;
        while (n.compareTo(BigInteger.ZERO) > 0) { 
            // Find the greates Fibonacci Number smaller 
            // than or equal to n 
            int f = nearestSmallerEqFib(n);
            if(fmax == -1)fmax = f;
            isOne[f] = true;
            // Reduce n 
            n = n.subtract(fb[f]); 
        }
        for(int i=fmax;i>=0;i--)
            res += isOne[i]?"1":"0";
        return res;
    }

    public static void main(String[] args) {
        setFb();
        int n;
        Scanner sc = new Scanner(System.in);
        boolean isFirst = true;
        while (sc.hasNext()) {
            if(!isFirst)System.out.println();
            else isFirst = false;
            String s1 = sc.next();
            BigInteger num1 = BigInteger.ZERO;
            n = s1.length();
            for(int i=n-1;i>=0;i--)
                if(s1.charAt(i) == '1')
                    num1 = num1.add(fb[n-i-1]);
            String s2 = sc.next();
            BigInteger num2 = BigInteger.ZERO;
            n = s2.length();
            for(int i=n-1;i>=0;i--)
                if(s2.charAt(i) == '1')
                    num2 = num2.add(fb[n-i-1]);
            System.out.println(fbRep(num1.add(num2)));
        }
    }
}
