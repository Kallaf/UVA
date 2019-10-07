#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int n;
ll dp[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//--------------------------
	dp[2] = 0;
	ll diff = 0;
	for(int i=3;i<=1000000;i++)
	{
		diff += (i-2)/2;
		dp[i] = dp[i-1] + diff;
	}
	while(cin>>n,n>=3)cout << dp[n] << endl;
    return 0;
}
