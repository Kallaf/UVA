import java.util.Scanner;
class Main
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		while(true)
		{
			int n = scan.nextInt();
			double downPayment = scan.nextDouble(),loan = scan.nextDouble();
			int m = scan.nextInt();
			if(n<0)break;
			double[] depreciations = new double[102];
			for(int i=0;i<m;i++)
			{
				int month = scan.nextInt();
				depreciations[month] = scan.nextDouble();
				for(int j=month+1;j<101;j++)
					depreciations[j] = depreciations[month];
			}
			double carValue = (downPayment+loan) * (1-depreciations[0]);
			double perMonth = loan/n;
			int i;
			for(i=0;loan > carValue;i++)
			{
				carValue *= (1-depreciations[i+1]);
				loan -= perMonth;
			}
			System.out.println(i+" month"+(i==1?"":"s"));
		}
	}
}
