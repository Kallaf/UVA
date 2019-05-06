#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char input[1000];
		scanf("%s",input);
		long l = strlen(input);
		if(!strcmp(input,"1")||!strcmp(input,"4")||!strcmp(input,"78"))
			printf("+\n");
		else if(l>1 && input[l-2] == '3' && input[l-1] == '5')
			printf("-\n");
		else if(l>1 && input[0] == '9' && input[l-1] == '4')
			printf("*\n");
		else if(l>3 && input[0] == '1' && input[1] == '9' && input[2] == '0')
			printf("?\n");
	}
	return 0;
}
