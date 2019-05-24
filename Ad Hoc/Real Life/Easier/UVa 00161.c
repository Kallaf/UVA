#include <stdio.h>

int main()
{
	while(1)
	{
		int signals[101],vSignals[101],isGreen[101],i,input;
		scanf("%d",&input);
		if(!input)break;
		for(i=0;input;i++)
		{
			signals[i] = input;
			vSignals[i] = input - 5;
			isGreen[i] = 1;
			scanf("%d",&input);
		}
		int count = i,s=0,start=0;
		while(1)
		{
			if(s>18000)
			{
				printf("Signals fail to synchronise in 5 hours\n");
				break;
			}
			int counter = 0;
			for(i=0;i<count;i++)
			{

				if(start)
					if(isGreen[i])counter++;
				vSignals[i]--;
				if(!vSignals[i])
				{
					vSignals[i] = signals[i] + (isGreen[i]?5:-5);
					isGreen[i] = isGreen[i]?0:1;
					start = 1;
				}
				
			}
			if(counter == count)
			{
				printf ("%02d:%02d:%02d\n", s/3600, s/60%60, s%60);
				break;
			}
			s++;
		}
	}
	return 0;
}
