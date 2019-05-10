#include <stdio.h>

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		int up=0,down=0,previous,current,j;
		scanf("%d\n",&previous);
		for(j=1;j<n;j++)
		{
			scanf("%d",&current);
			if(current>previous)up++;
			else if(current<previous)down++;
			previous = current;
		}
		printf("Case %d: %d %d\n",i,up,down);
	}
	return 0;
}
