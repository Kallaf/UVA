import java.util.Scanner;
import java.math.BigInteger;

class Main {
    private static String areEqual(String num1,String num2)
    {
        char max1 = 0 ,max2 = 0;
        for(int i=0;i<num1.length();i++)
            max1 = num1.charAt(i)>max1?num1.charAt(i):max1;
        for(int i=0;i<num2.length();i++)
            max2 = num2.charAt(i)>max2?num2.charAt(i):max2;
        int m1 = max1 >= 'A'?max1-'A' + 11:Math.max(max1-'0'+1,2);
        int m2 = max2 >= 'A'?max2-'A' + 11:Math.max(max2-'0'+1,2);
        for(int i=m1;i<=36;i++)
        {
            BigInteger n1 = new BigInteger(num1,i);
            for(int j=m2;j<=36;j++)
            {
                BigInteger n2 = new BigInteger(num2,j);
                if(n1.equals(n2))return num1+" (base "+Integer.toString(i)+") = "+num2+" (base "+Integer.toString(j)+")";
            }
        }
        return num1+" is not equal to "+num2+" in any base 2..36";
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            System.out.println(areEqual(sc.next(),sc.next()));
        }
    }
}
