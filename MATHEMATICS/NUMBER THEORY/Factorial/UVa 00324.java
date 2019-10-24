import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Main {

    private static String[] fact = new String[400];
    // Returns Factorial of N 
    private static void factorial() 
    { 
        // Initialize result 
        BigInteger f = new BigInteger("1"); // Or BigInteger.ONE 
        fact[0] = "1";fact[1] = "1";
        // Multiply f with 2, 3, ...N 
        for (int i = 2; i <= 366; i++) 
        {
            f = f.multiply(BigInteger.valueOf(i)); 
            fact[i] = f.toString();
        }
    } 

    private static final Scanner sc = new Scanner(System.in);
    private static int x;
    public static void main(String[] args){
        factorial();
        while(true)
        {
            x = sc.nextInt();
            if(x==0)break;
            int[] count = new int[10];
            char[] css = fact[x].toCharArray();
            for(char c:css)count[c-'0']++;
            System.out.println(x+"! --");
            for(int i=0;i<5;i++)
                System.out.print(" ("+i+") "+count[i]);
            System.out.println();
            for(int i=5;i<10;i++)
                System.out.print(" ("+i+") "+count[i]);
            System.out.println();
        }
    }
}
