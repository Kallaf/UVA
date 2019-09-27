import java.util.Scanner;

class Main
{

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		while(true)
		{
			int x = scan.nextInt();
			int y = scan.nextInt();
			int c = scan.nextInt();
			if(x==0)break;
			int ans = (x-7)*(y-7);
			System.out.println(ans/2 + (ans%2==1?c:0));
		}
	}
}
