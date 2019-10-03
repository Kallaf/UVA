#include <bits/stdc++.h> 

using namespace std;

int cnt[105];
int t,n,m,flag;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for(int tc = 1;tc<=t;tc++)
	{
		memset(cnt,0,sizeof(cnt));
		flag = 1;
		cin >> n;
		for(int i=0;i<n*n;i++)
		{
			cin >> m;
			cnt[m]++;
			if(cnt[m] > n)flag = 0;
		}
		cout << "Case " << tc << ": " << (flag?"yes":"no") << endl;
	}
	return 0;
}
