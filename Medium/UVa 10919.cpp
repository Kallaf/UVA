#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string input;
	while(1)
	{
		bool yes = 1;
		int k,m;
		cin >> k;
		if(!k)break;
		cin >> m;
		vector<string> v;
		while(k--)
		{
			cin >> input;
			v.push_back(input);
		}
		while(m--)
		{
			int r,c;
			cin >> r >> c;
			int available = 0;
			while(r--)
			{
				cin >> input;
				if (std::find(v.begin(), v.end(), input) != v.end())
				  available++;
			}
			if(available<c)yes=0;
		}
		cout << (yes?"yes":"no") << endl;
	}
	return 0;
}

