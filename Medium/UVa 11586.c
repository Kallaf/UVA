#include <stdio.h>
#include <string.h>
int main()
{
	int t,i,j;
	scanf("%d\n",&t);
	while(t--)
	{
		char line[200];
		gets(line);
		char pieces[51][3];
		for(i=0,j=0;i<strlen(line);i+=3,j++)
		{
			pieces[j][0] = line[i];
			pieces[j][1] = line[i+1];
			pieces[j][2] = '\0';
		}
		if(j==1)goto notloop;
		int MF = 0,MM=0,FF=0;
		for(i=0;i<j;i++)
		{
			if(!strcmp(pieces[i],"MF") || !strcmp(pieces[i],"FM"))MF++;
			else if (!strcmp(pieces[i],"MM"))MM++;
			else FF++;
		}
		if(MM == FF)printf("LOOP\n");
		else 
			notloop:
			printf("NO LOOP\n");
	}
	return 0;
}
