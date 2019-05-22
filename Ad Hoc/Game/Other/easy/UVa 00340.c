#include <stdio.h>

int main()
{
	int game;
	for(game=1;1;game++)
	{
		int n,i,hidden[1001],hidden_count[10]={0};
		scanf("%d",&n);
		if(!n)break;
		printf("Game %d:\n",game);
		for(i=0;i<n;i++)
		{
			scanf("%d",&hidden[i]);
			hidden_count[hidden[i]]++;
		}
		while(1)
		{
			int pred[1001],pred_count[10] = {0};
			for(i=0;i<n;i++)
			{
				scanf("%d",&pred[i]);
				pred_count[pred[i]]++;
			}

			if(!pred[0])break;

			int matching = 0;
			for(i=1;i<10;i++)
				matching += pred_count[i] >= hidden_count[i] ? hidden_count[i]:pred_count[i];

			int inPlace=0;
			for(i=0;i<n;i++)
				if(hidden[i] == pred[i])inPlace++;
			printf("    (%d,%d)\n",inPlace,matching-inPlace);
		}

	}
	return 0;
}
