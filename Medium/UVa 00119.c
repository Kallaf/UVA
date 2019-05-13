#include <stdio.h>
#include <string.h>
int getIndex(char names[][15],char name[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!strcmp(names[i],name))
			return i;
	}
	return -1;
}

int main()
{
	int n,i,t=0;
	while(scanf("%d",&n) != EOF)
	{
		char names[11][15];
		int money[15] = {0};
		for(i=0;i<n;i++)
			scanf("%s",names[i]);
		for(i=0;i<n;i++)
		{
			char name[15];
			int spent,m,j;
			scanf("%s%d%d",name,&spent,&m);
			if(!m)continue;
			int index1 = getIndex(names,name,n);
			money[index1] -= spent - spent%m;
			for(j=0;j<m;j++)
			{
				scanf("%s",name);
				int index2 = getIndex(names,name,n);
				money[index2] += spent/m;
			} 
		}

		if(t++ > 0)printf("\n");

		for(i=0;i<n;i++)
			printf("%s %d\n",names[i],money[i]);
	}
	return 0;
}
