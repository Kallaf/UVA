import java.util.Scanner;

class Main
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		while(true)
		{
			int a = scan.nextInt(),b=scan.nextInt();
			if(a == -1 || b == -1)
				break;
			System.out.println(a < b? Math.min(b-a,a+100-b) : Math.min(a-b,b+100-a));
		}
	}
}
