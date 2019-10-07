#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//---------------------------
	int n;
	cin >> n;
	vector<vector<int>> grid(n+2,vector<int>(n+2,0));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin >> grid[i][j];
			grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
		}
	int mx = INT32_MIN;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=i;k++)
				for(int l=1;l<=j;l++)
					mx = max(mx,grid[i][j]-grid[i][l-1]-grid[k-1][j]+grid[k-1][l-1]);
	cout << mx << endl;
	return 0;
}
