#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll _sieve_size;
bitset<10000010> bs;
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

vector<int> primeFactors(int x)
{
    vector<int> res;
    int i = 0,cnt;
    while(primes[i]*primes[i]<=x)
    {
        cnt = 0;
        while(x%primes[i] == 0)
        {
            cnt++;
            x/=primes[i];
        }
        if(cnt){
            res.push_back(primes[i]);
            res.push_back(cnt);
        }
        i++;
    }
    if(x != 1)
    {
        res.push_back(x);
        res.push_back(1);
    }
    return res;
}

string line;
int p,e,num; 

int main()
{
    sieve(32768);
    while(getline(cin,line))
    {
        num = 1;
        if(line == "0")return 0;
        stringstream nums(line);
        while(nums >> p >> e)num *= pow(p,e);
        vector<int> res = primeFactors(num-1);
        cout << res[res.size()-2] << " " << res[res.size()-1]; 
        for(int i=res.size()-4;i>=0;i-=2)
            cout << " " << res[i] << " " << res[i+1];
        cout << endl;
    }
    return 0;
}
