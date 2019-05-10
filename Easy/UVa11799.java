import java.util.Scanner;
class Main
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		for(int i=1;i<=t;i++)
		{
			int n = scan.nextInt();
			int max = 0;
			for(int j=0;j<n;j++)
			{
				int s = scan.nextInt();
				max = Math.max(max,s);
			}
			System.out.println("Case "+i+": "+max);
		}
	}
}
