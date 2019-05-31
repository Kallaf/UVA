import java.util.Scanner;
import java.util.HashMap;
class Main
{

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while(t-- > 0)
		{
			int n = scan.nextInt();
			int[] front = new int[n+2];
			boolean[] frontUsed = new boolean[n+2];
			int[] side = new int[n+2];
			boolean[] sideUsed = new boolean[n+2];
			for(int i=0;i<n;i++)
			{
				front[i] = scan.nextInt();
				frontUsed[i] = false;
			}
			for(int i=0;i<n;i++)
			{
				side[i] = scan.nextInt();
				sideUsed[i] = false;
			}
			int N=0,M=0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					M += Math.min(front[i],side[j]);
					if(!frontUsed[i] && !sideUsed[j] && front[i] == side[j])
					{
						N += front[i];
						frontUsed[i] = true;
						sideUsed[j] = true;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(!frontUsed[i] && front[i] <= side[j])
					{
						frontUsed[i] = true;
						N += front[i];
					}else if(!sideUsed[j] && side[j] <= front[i])
					{
						sideUsed[j] = true;
						N += side[j];
					}
				}
			}
			M -= N;
			System.out.println("Matty needs at least "+N+" blocks, and can add at most "+M+" extra blocks.");	
		}
	}
}
