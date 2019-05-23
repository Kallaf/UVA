#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <string.h>

using namespace std;

int ans(char* s)
{
	int n = strlen(s);
	int count = 0;
	for(int i=1;i<=n;i++)
	{
		vector<array<char,100>> used;
		for(int j=0;j<n-i+1;j++)
		{
			bool flag = 1;
			for(int k=j,m=0;k<=j+i/2;k++,m++)
			{
			 	if(s[k] != s[j+i-1-m])
			 	{
			 		flag = 0;
			 		break;
			 	}
			}
		 	if(flag)
		 	{
		 		
		 		array<char,100> temp;
		 		for(int k=0;k<i;k++)temp[k]=s[j+k];
				temp[i] = '\0';

				if(std::find(used.begin(), used.end(), temp) == used.end()) {
		 			count++;
		 			used.push_back(temp);
				}
		 	}
		}
	}
	return count;
}

int main()
{
	char s[100];
	while(scanf("%s",s) != EOF)
		printf("The string '%s' contains %d palindromes.\n",s,ans(s));
	return 0;
}

