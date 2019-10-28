#include<bits/stdc++.h>
#define ll  long long int
#define vi vector<int>
using namespace std;


ll _sieve_size;
bitset<1000000010> bs;
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

ll numDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    // start from ans = 1
    while (PF * PF <= N) {
        ll power = 0;
        // count the power
        while (N % PF == 0) { N /= PF; power++; }
        ans *= (power + 1);
        // according to the formula
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= 2;
    // (last factor has pow = 1, we add 1 to it)
    return ans;
}

ll n,k,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    sieve(1000000);
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld%lld",&k,&m);
        ll mx = 0,mxI;
        for(ll i=k;i<=m;i++)
        {
            ll curr = numDiv(i);
            if(curr > mx)
            {
                mx = curr;
                mxI = i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",k,m,mxI,mx);
    }
    return 0;   
}
