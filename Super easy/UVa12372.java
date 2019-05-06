import java.util.Scanner;
class Main
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		for(int c=1;c<=t;c++)
		{
			int l=scan.nextInt(),w=scan.nextInt(),h=scan.nextInt();
			if(l > 20 || w > 20 || h > 20)
				System.out.println("Case "+c+": bad");
			else
				System.out.println("Case "+c+": good");
		}
	}
}
