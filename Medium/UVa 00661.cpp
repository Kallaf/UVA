#include <iostream>

using namespace std;

int main()
{
	for(int c=1;1;c++)
	{
		int n,m,fuseCapacity;
		cin >> n >> m >> fuseCapacity;
		if(!n)break;
		bool ON[22] = {0};
		int powers[22];
		for(int i=1;i<=n;i++)
			cin >> powers[i];
		int currentPow = 0,maxPow = -1;
		while(m--)
		{
			int machine;
			cin >> machine;
			if(ON[machine]) 
			{	
				ON[machine] = 0;
				currentPow -= powers[machine];
			}
			else 
			{
				ON[machine] = 1;
				currentPow += powers[machine];
			}
			maxPow = max(currentPow,maxPow);
		}
		printf("Sequence %d\n", c);
		if(maxPow > fuseCapacity)
			printf("Fuse was blown.\n\n");
		else
			printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",maxPow);
	}
	return 0;
}
