import java.util.Scanner;

class Main
{
	static class Cell{
		int cost,value;
		boolean isBumber;
		private Cell(int cost,int value)
		{
			this.cost = cost;
			this.value = value;
			this.isBumber = false;
		}
	}

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt(),m = scan.nextInt(),wallCost = scan.nextInt(),p = scan.nextInt();
		Cell[][] grid = new Cell[n+2][m+2];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				grid[i][j] = new Cell(0,0);
		for(int i=0;i<p;i++)
		{
			int x = scan.nextInt(),y = scan.nextInt();
			grid[x][y].value = scan.nextInt();
			grid[x][y].cost = scan.nextInt();
			grid[x][y].isBumber = true;
		}
		int points = 0;
		while(scan.hasNextInt())
		{
			int current_points = 0;
			int x = scan.nextInt(),y = scan.nextInt();
			int direction = scan.nextInt();
			int lifetime = scan.nextInt();
			while(--lifetime > 0)
			{
				int posX=x,posY=y;
				switch(direction)
				{
					case 0:
						posX++;
						break;
					case 1:
						posY++;
						break;
					case 2:
						posX--;
						break;
					case 3:
						posY--;
						break;
				}
				if(posX==n)
				{
					lifetime -= wallCost;
					direction = 3;
				}
				else if(posX==1)
				{
					lifetime -= wallCost;
					direction = 1;
				}
				else if(posY==m)
				{
					lifetime -= wallCost;
					direction = 0;
				}
				else if(posY==1)
				{
					lifetime -= wallCost;
					direction = 2;
				}
				else if(grid[posX][posY].isBumber)
				{
					lifetime -= grid[posX][posY].cost;
					current_points += grid[posX][posY].value;
					direction = (direction-1)&3;
				}else {
					x=posX;y=posY;
				}

			}
			points += current_points;
			System.out.println(current_points);
		}
		System.out.println(points);
	}
}
