import java.util.Scanner;
import java.util.Arrays;

class Main
{

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while(t-- > 0)
		{
			int n = scan.nextInt(),m=scan.nextInt();
			boolean[] bitmask = new boolean[1030];
			boolean[] next = new boolean[1030];
			Arrays.fill(next,true);
			for(int i=0;i<m;i++)
				next[scan.nextInt()] = false;
			
			int walkovers = 0;
			for(int players = (int)Math.pow(2,n);players>1;players>>=1)
			{
				for(int i=1;i<=players;i++)
					bitmask[i] = next[i];

				for(int i=1;i<=players;i+=2)
				{
					if((bitmask[i]&&!bitmask[i+1]) || (!bitmask[i]&&bitmask[i+1]))walkovers++;
					next[i/2+1] = bitmask[i] || bitmask[i+1];
				}
				
			}
			System.out.println(walkovers);
		}
	}
}
