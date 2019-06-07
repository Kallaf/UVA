import java.util.Scanner;
import java.util.Arrays;

class Main
{

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int tc = 1;
		while(true)
		{
			int R = scan.nextInt(),C = scan.nextInt(),N = scan.nextInt();
			if(R == 0 && C==0 && N==0)break;
			boolean[] rows = new boolean[10010];
			boolean[] cols = new boolean[10010];
			Arrays.fill(rows,true);
			Arrays.fill(cols,true);
			for(int i=0;i<N;i++)
			{
				rows[scan.nextInt()] = false;
				cols[scan.nextInt()] = false;
			}
			int r=scan.nextInt(),c=scan.nextInt();
			boolean flag = false;
			if(rows[r] && (cols[c] || (c-1>=0 && cols[c-1]) || (c+1<C && cols[c+1]) ) )flag = true;
			if(cols[c] && ((r-1>=0 && rows[r-1]) || (r+1<R && rows[r+1]) ) )flag = true;
			System.out.printf("Case %d: %s\n",tc++,flag?"Escaped again! More 2D grid problems!":"Party time! Let's find a restaurant!");
		}
	}
}
