#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


int main()
{
	char s[100];
	std::map<char,int> cards;

	cards['A']=1;cards['2']=2;cards['3']=3;cards['4']=4;
	cards['5']=5;cards['6']=6;cards['7']=7;cards['8']=8;
	cards['9']=9;cards['T']=10;cards['J']=11;cards['Q']=12;
	cards['K']=13;

	while(1)
	{
		vector<pair<int,string>> deck[15];
		string input;
		cin >> input;
		if(!input.compare("#"))break;

		vector<pair<int,string>> reversed;
		reversed.push_back({cards[input.at(0)],input});
		for(int i=1;i<52;i++)
		{
			cin >> input;
			reversed.push_back({cards[input.at(0)],input});
		}

		for(int i=0;i<52;i++)
			deck[i%13+1].push_back(reversed[51-i]);

		int previous,current = 13;
		int count = 0;
		string last;
		while(!deck[current].empty())
		{
			count++;
			previous = current;
			current = deck[previous].back().first;
			last = deck[previous].back().second;
			deck[previous].pop_back();
		}
		printf("%.2d,%s\n",count,last.c_str());
	}

	return 0;
}

