import java.util.Scanner;
class Main
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		while(true)
		{
			int b = scan.nextInt(),n = scan.nextInt();
			if(b == 0 || n == 0)
				break;
			int[] banks = new int[b+2];
			for(int i=1;i<=b;i++)
				banks[i] = scan.nextInt();
			while(n-- > 0)
			{
				int i = scan.nextInt(),j=scan.nextInt(),value=scan.nextInt();
				banks[i] -= value;banks[j] += value;
			}
			boolean flag = true;
			for(int i=1;i<=b;i++)
			{
				if(banks[i]<0)
				{
					flag = false;
					break;
				}
			}
			System.out.println((flag?"S":"N"));
		}
	}
}
