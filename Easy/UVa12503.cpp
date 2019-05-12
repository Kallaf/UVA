#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,p=0;
		cin >> n;
		int moves[102];
		for(int i=1;i<=n;i++)
		{
			string move;
			cin >> move;
			if(!move.compare("LEFT"))
				moves[i] = -1;
			else if(!move.compare("RIGHT"))
				moves[i] = 1;
			else
			{
				int index;
				cin >> move >> index;
				moves[i] = moves[index];
			}
			p += moves[i];
		}
		cout << p << endl;
	}
	return 0;
}
