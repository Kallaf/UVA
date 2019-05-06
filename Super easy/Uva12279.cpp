#include<iostream>

using namespace std;

int main()
{
	int c = 1;
	while(1)
	{
		int n;
		cin >> n;
		if(!n)break;
		int zeros=0,non_zeros=0;
		for(int i=0;i<n;i++)
		{
			int input;
			cin >> input;
			if(input)non_zeros++;
			else zeros++;
		}
		cout << "Case " << (c++) << ": " << (non_zeros-zeros) << endl;
	}
	return 0;
}
