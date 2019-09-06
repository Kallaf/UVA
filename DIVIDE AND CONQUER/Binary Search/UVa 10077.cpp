#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
double num;


int main(){

	while(scanf("%d%d",&n,&m),n!=1 || m!=1)
	{
		num = (double)n/(double)m;
		pair<int,int> left = {0,1},right= {1,0},curr= {1,1};
		while(1)
		{
			double frac = (double)curr.first/(double)curr.second;
			if(frac == num){printf("\n");break;}
			if(frac > num)
			{
				right = curr;
				curr.first += left.first;
				curr.second += left.second; 
				printf("L");
			}
			else 
			{
				left = curr;
				curr.first += right.first;
				curr.second += right.second;
				printf("R");
			}
		}
	}

    return 0;
}
