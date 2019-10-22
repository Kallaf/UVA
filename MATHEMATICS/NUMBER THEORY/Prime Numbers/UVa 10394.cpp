#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll _sieve_size;
bitset<20000010> bs;
vector<int> primes;
vector<pair<int,int>> twin_prime;
void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);
            if(primes.size() > 2 && primes[primes.size()-1] == primes[primes.size()-2]+2)
                twin_prime.push_back( {primes[primes.size()-2],primes[primes.size()-1]} );
        }
}

int i;

int main()
{
    sieve(20000000);
    while(scanf("%d",&i) != EOF)
        printf("(%d, %d)\n",twin_prime[i-1].first,twin_prime[i-1].second);
    return 0;
}
