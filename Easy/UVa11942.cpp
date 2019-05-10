#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	cout << "Lumberjacks:" << endl;
	while(t--)
	{
		int previous,current,biggerThan=0;
		cin >> previous;
		for(int i=1;i<10;i++)
		{
			cin >> current;
			if(current>previous)biggerThan++;
			previous = current;
		}
		cout << ((biggerThan == 9 || biggerThan == 0)?"Ordered":"Unordered") << endl;
	}
	return 0;
}
