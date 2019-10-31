#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

bitset<1000010> isPrime;
vector<int> cnt(MAX,0);

void seive()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(long long int i=2;i<MAX;i++)
        if(isPrime[i])
            for(long long int j=i;j<MAX;j+=i)
            {
                isPrime[j] = 0;
                cnt[j]++;
            }
}

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    seive();
    //--------------------------
    while(scanf("%d",&n),n)printf("%d : %d\n",n,cnt[n]);
    return 0;   
}
