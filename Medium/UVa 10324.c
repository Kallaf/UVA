#include <stdio.h>
#include <string.h>

int min(int x,int y)
{
	return x<y?x:y;
}

int max(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int c = 1;
	char s[1000001];
	while(scanf("%s",s) != EOF)
	{
		int n,i;
		scanf("%d",&n);
		printf("Case %d:\n",c++);
		while(n--)
		{
			char ch;
			int start,end;
			scanf("%d%d",&start,&end);
			int a = min(start,end);
			int b = max(start,end);
			ch = s[a];
			int flag = 1;
			for(i=a+1;i<=b;i++)
				if(s[i] != ch)
				{
					flag = 0;
					break;
				}
			printf("%s\n",flag?"Yes":"No");
		}
	}
	return 0;
}
