#include<bits/stdc++.h>
#define ll  long long int
#define vi vector<int>
using namespace std;


ll _sieve_size;
bitset<10000010> bs;
vi primes;
void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) 
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        } 
}

bool check(int n,int m)
{
    for(int i=0;primes[i]*primes[i]<=m;i++)
    {
        if(m%primes[i] == 0)
        {
            int cmt = 0,cnt = 0;
            for(;m%primes[i] == 0;cmt++,m/=primes[i]);
            for(int x=primes[i];x<=n;cnt+=n/x,x*=primes[i]);
            if(cnt < cmt)return false;
        }
    }
    if(m!=1 && n < m)return false;
    return true;
}

int main()
{
    sieve(100000);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(check(n,m))
            printf("%d divides %d!\n",m,n);
        else
            printf("%d does not divide %d!\n",m,n);
    }
    return 0;   
}
