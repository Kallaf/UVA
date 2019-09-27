#include <iostream>

using namespace std;

int solve(int n)
{
    int l = -1,m=n;
    while(m)
    {
        l++;
        m>>=1;
    }
    if(1<<l == n)return n;
    return (n - (1<<l)) << 1;
}

int n;

int main()
{
    while(scanf("%d",&n),n)
        cout << solve(n) << endl;
    return 0;
}
