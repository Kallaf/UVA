#include <stdio.h>
#include <string.h>
int countMistakes(char right[],char wrong[])
{
	int n = strlen(right);
	int mistakes = 0;
	for(int i=0;i<n;i++)
		mistakes += right[i] != wrong[i] ?1:0;
	return mistakes;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char wrong[10];
		scanf("%s",wrong);
		if(countMistakes("one",wrong) < 2)
			printf("1\n");
		else if(countMistakes("two",wrong) < 2)
			printf("2\n");
		else
			printf("3\n");
	}
	return 0;
}
