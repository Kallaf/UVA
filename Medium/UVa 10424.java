import java.util.Scanner;

class Main
{

	public static double convert(int n)
	{
		if(n < 10)
			return Double.valueOf(n);
		int m = 0;
		while(n>0)
		{
			m += n%10;
			n/=10;
		}
		return convert(m);
	}

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		while(scan.hasNextLine())
		{
			String s = scan.nextLine();
			char[] s1 = s.toLowerCase().toCharArray();
			s = scan.nextLine();
			char[] s2 = s.toLowerCase().toCharArray();
			int n1=0,n2=0;
			for(int i=0;i<s1.length;i++)
				if( 'a' <= s1[i] && s1[i] <= 'z')
					n1 += s1[i] - 'a' + 1;
			for(int i=0;i<s2.length;i++)
				if( 'a' <= s2[i] && s2[i] <= 'z')
					n2 += s2[i] - 'a' + 1;
			double a = convert(n1),b = convert(n2);
			double c = Math.max(a,b) , d = Math.min(a,b);
			double result = d/c * 100;
			System.out.printf("%.2f %%\n",result);
		}
	}
}
