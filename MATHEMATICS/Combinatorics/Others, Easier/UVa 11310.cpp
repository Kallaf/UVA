#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int n;
ll dp[45];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//---------------------------
	dp[0] = 1l;dp[1] = 1l;dp[2] = 5l;
	for(int i=3;i<=40;i++)
		dp[i] = dp[i-1] + 4*dp[i-2] + 2*dp[i-3];
	cin >> n;
	while(cin >> n)cout << dp[n] << endl;
    return 0;
}
