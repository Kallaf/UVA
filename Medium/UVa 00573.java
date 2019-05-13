import java.util.Scanner;

class Main
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		while(true)
		{
			double h = scan.nextDouble(), u=scan.nextDouble(), d = scan.nextDouble(),f=scan.nextDouble();
			if(h==0)
				break;
			double fatigue = u * f / 100.0;
			double h_c = 0;
			for(int day = 1;true;day++)
			{
				h_c += Math.max(u,0);
				if(h_c > h)
				{
					System.out.println("success on day "+day);
					break;
				}
				h_c -= d;
				u -= fatigue;
				if(h_c < 0)
				{
					System.out.println("failure on day "+(day));
					break;
				}
			} 
		}
	}
}
