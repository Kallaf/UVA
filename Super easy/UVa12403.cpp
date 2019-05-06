#include <iostream>
#include <string>


using namespace std;

int main()
{
	int t;
	cin >> t;
	int donate = 0;
	while(t--)
	{
		string input;
		cin >> input;
		if(!input.compare("donate"))
		{
			int x;
			cin >> x;
			donate += x;
		}else
			cout << donate << endl;
	}
	return 0;
}
