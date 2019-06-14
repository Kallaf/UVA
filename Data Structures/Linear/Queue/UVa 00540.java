import java.util.Scanner;
import java.util.LinkedList; 
import java.util.Queue;

class Main
{

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int n,tc = 1;
		while((n = scan.nextInt()) != 0)
		{
			System.out.printf("Scenario #%d\n",tc++);
			int[] elements = new int[1000005];
			Queue<Integer> teams = new LinkedList<>();
			Queue<Integer>[] teamElements = new LinkedList[1005];
			for(int i=0;i<n;i++)
			{
				int t = scan.nextInt();
				for(int j=0;j<t;j++)
					elements[scan.nextInt()] = i;	
				teamElements[i] = new LinkedList<>();
			}
			while(true)
			{
				String command = scan.next();
				if(command.equals("STOP"))break;
				if(command.equals("DEQUEUE"))
				{
					if(!teams.isEmpty())
					{
						System.out.println(teamElements[teams.peek()].remove());
						if(teamElements[teams.peek()].isEmpty())teams.remove();
					}
				}else
				{
					int element = scan.nextInt();
					if(!teams.contains(elements[element]))teams.add(elements[element]);
					teamElements[elements[element]].add(element);
				}
			}
			System.out.println();
		}
	}
}
