#include <iostream>

using namespace std;

int main()
{
	int t,n,a,b,diff;
	cin >> t;
	while(t--)
	{
		cin >> n;
		string ans = "yes\n";
		if(n>0)
		{
			cin >> a >> b;
			n--;
			diff = a-b;
		}
		while(n--)
		{
			cin >> a >> b;
			if(a-b != diff)
				ans = "no\n";
		}
		cout << ans;
		if(t)cout << endl;
	}
	return 0;
}
