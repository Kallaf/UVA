#include <iostream>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int len = 1 << n;
        int corners[32788];
        int potencies[32788]={0};
        for(int i=0;i<len;i++)
            cin >> corners[i];

        for(int i=0;i<len;i++)
            for(int j=0;j<n;j++)
                potencies[i] += corners[i ^ (1<<j)];

        int ans = 0;
        for(int i=0;i<len;i++)
            for(int j=0;j<n;j++)
                ans = max(ans,potencies[i]+potencies[i ^ (1<<j)]);
        cout << ans << endl;
    }
	return 0;
}

