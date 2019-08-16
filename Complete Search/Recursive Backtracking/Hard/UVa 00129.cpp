#include<iostream>
#include<vector>

using namespace std;

int n,l,groups,m,x,y,currLen,matches;
char curr;
vector<vector<vector<char>>> hard_sequences(30);

bool currAdded(){
	hard_sequences[l][x].push_back(curr);
	currLen = hard_sequences[l][x].size();
	for(int len = 1;len<currLen;len++)
	{
		int i = currLen-len,j = i - len;
		if(j<0)return true;
		matches = 0;
		for(;i<currLen;i++,j++)
		{
			if(hard_sequences[l][x][i] == hard_sequences[l][x][j])matches++;
			else break;
		}
		if(matches == len){
			hard_sequences[l][x].pop_back();
			return false;
		}
	}
	return true;
}

void incCurr()
{
	curr++;
	while(curr == 'A'+l)
	{
		y = hard_sequences[l][x].size()-1;
		curr = hard_sequences[l][x][y]+1;
		hard_sequences[l][x].pop_back();
	}
}

int main()
{
	while(1)
	{
		scanf("%d%d",&n,&l);
		if(!n)return 0;
		if(hard_sequences[l].empty()){
			vector<char> temp;
			temp.push_back('A');
			hard_sequences[l].push_back(temp);
		}
		x = hard_sequences[l].size()-1;	
		while(hard_sequences[l].size() < n)
		{
			curr = 'A';
			hard_sequences[l].push_back(hard_sequences[l][x++]);
			while(!currAdded())incCurr();
		}
		groups = 1;m=hard_sequences[l][n-1].size();
		for(int i=0;i<m;i++)
		{
			if(groups == 17){
				groups = 1;
				printf("\n");
			}
			printf("%c", hard_sequences[l][n-1][i]);
			if(i%4==3 && i!=m-1)
			{
				groups++;
				if(groups == 17){
					groups = 1;
					printf("\n");
				}else
					printf(" ");
			}
		}
		printf("\n%d\n",m);
	}
	return 0;
}
