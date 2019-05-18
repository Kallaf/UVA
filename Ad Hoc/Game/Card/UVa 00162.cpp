#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	while(1)
	{
		deque<string> player[2];
		deque<string> middle;
		for(int i=0, j = 1;i<52;i++,j=(j+1)%2)
		{

			string card;
			cin >> card;
			if(!card.compare("#"))return 0;
			player[j].push_back(card);
		}
		bool face = 0;
		int counter = 1,j=1;
		while(1)
		{

			if(player[j].empty())
			{
				j = (j+1)%2;
				printf("%d%3d\n", j+1,int(player[j].size()));
				break;
			}
			middle.push_back(player[j].back());
			player[j].pop_back();
			counter--;
			switch(middle.back()[1])
			{
				case 'J':
					counter = 1;
					face = 1;
					j=(j+1)%2;
					break;
				case 'Q':
					counter = 2;
					face = 1;
					j=(j+1)%2;
					break;
				case 'K':
					counter = 3;
					face = 1;
					j=(j+1)%2;
					break;
				case 'A':
					counter = 4;
					face = 1;
					j=(j+1)%2;
					break;
				default:
					if(!counter)
					{
						if(face)
						{
							j=(j+1)%2;
							for(auto &card:middle)
								player[j].push_front(card);
							middle.clear();
							face = 0;
							counter = 1;
						}else
						{
							counter = 1;
							j=(j+1)%2;
						}
					}
					
			}

		}
	}
	return 0;
}

