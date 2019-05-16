#include <iostream>

using namespace std;

int main()
{
	while(1)
	{
		int h,w,current,previous;
		cin >> h;
		if(!h)break;
		cin >> w >> previous;
		int cut = h - previous;
		for(int i=1;i<w;i++)
		{
			cin >> current;
			if(current<previous)
				cut += previous - current;
			previous = current;
		}
		cout << cut << endl;
	}
	return 0;
}

