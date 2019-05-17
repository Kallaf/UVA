#include <stdio.h>
int main()
{
	int t,c,i;
	scanf("%d\n",&t);
	for(c=1;c<=t;c++)
	{
		char ch = getchar();
		char pointer = 0;
		char memory[101] = {0};
		while(ch != '>' && ch != '<' && ch != '+' && ch != '-' && ch != '.')
			ch = getchar();
		while(ch == '>' || ch == '<' || ch == '+' || ch == '-' || ch == '.')
		{
			if(ch == '+')memory[pointer]=(memory[pointer]+1)%256;
			else if(ch == '-')memory[pointer] = memory[pointer]?memory[pointer]-1:255;
			else if(ch == '>')pointer = (pointer+1)%100;
			else if(ch == '<')pointer = pointer?pointer-1:99;
			ch = getchar();
		}
		printf("Case %d:",c);
		for(i=0;i<100;i++)
			printf(" %02hhX",memory[i]);
		printf("\n");
	}
	return 0;
}
