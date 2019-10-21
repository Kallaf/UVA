#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll _sieve_size;
bitset<1000010> bs;
vector<int> primes;
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
bool isPrime(ll N) {
if (N <= _sieve_size) return bs[N];
for (int i = 0; i < (int)primes.size() && primes[i]*primes[i] <= N; i++)
if (N % primes[i] == 0) return false;
return true;
}

int l,u;

int main()
{
    sieve(1000000);
    while(scanf("%d%d",&l,&u) == 2)
    {
        int mn = INT32_MAX,mx = INT32_MIN;
        int mna,mnb,mxa,mxb;
        bool ans = 0;
        int pre = -1;
        for(long long i=l;i<=u;i++)
        {
            if(isPrime(i))
            {
                if(pre == -1)
                    pre = i;
                else{
                    int distance = i - pre;
                    if(distance > mx){
                        mxa = pre;
                        mxb = i;
                        mx = distance;
                    }
                    if(distance < mn){
                        mna = pre;
                        mnb = i;
                        mn = distance;
                    }
                    pre = i;
                    ans = 1;
                }
            }
            
        }
        if(ans)
            printf("%d,%d are closest, %d,%d are most distant.\n",mna,mnb,mxa,mxb);
        else
            printf("There are no adjacent primes.\n");
    }
    return 0;
}
