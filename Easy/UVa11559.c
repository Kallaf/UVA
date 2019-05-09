#include <stdio.h>

int main()
{
	int partNo,budget,hotelsNo,weeksNo,i;
	while(scanf("%d%d%d%d",&partNo,&budget,&hotelsNo,&weeksNo)!=EOF)
	{
		int min = 10001;
		char flag = 0;
		while(hotelsNo--)
		{
			int bedPrice;
			scanf("%d",&bedPrice);
			char localFlag = 0;
			for(i=0;i<weeksNo;i++)
			{
				int availablePlaces;
				scanf("%d",&availablePlaces);
				if(availablePlaces>partNo)
					localFlag = 1;
			}
			if(localFlag&&bedPrice*partNo <= budget)
			{
				flag=1;
				min = min>bedPrice?bedPrice:min;
			}
		}
		if(flag)printf("%d\n",min*partNo);
		else printf("stay home\n");
	}
	return 0;
}
