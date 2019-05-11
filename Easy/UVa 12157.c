#include <stdio.h>

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int j,n,mile=0,juice=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			int minutes;
			scanf("%d",&minutes);
			mile += (minutes/30 + 1) * 10;
			juice += (minutes/60 + 1) * 15;
		}
		printf("Case %d: %s%d\n",i,mile<=juice?(mile == juice ? "Mile Juice ":"Mile "):"Juice ",mile<=juice?mile:juice);
	}
	return 0;
}
