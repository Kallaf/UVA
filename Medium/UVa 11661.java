import java.util.Scanner;

class Main
{

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		while(scan.nextInt() != 0)
		{
			char[] road = scan.next().toCharArray();
			int dIndex = -1;int rIndex = -1;
			int min = 2000001;
			for(int i=0;i<road.length;i++)
			{
				if(road[i] == 'Z')
				{
					min = 0;
					break;
				}
				if(road[i] == 'R')
				{
					rIndex = i;
					if(dIndex!=-1)
						min = Math.min(min,rIndex-dIndex);
				}
				else if(road[i] == 'D')
				{
					dIndex = i;
					if(rIndex!=-1)
						min = Math.min(min,dIndex-rIndex);
				}
			}
			System.out.println(min);
		}
	}
}
