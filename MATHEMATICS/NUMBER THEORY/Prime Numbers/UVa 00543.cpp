#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000005
using namespace std;
bitset<MAX> notPrime;
vector<int> primes;

void setPrimes()
{
    for(int i=2;i*i<MAX;i++)
    {
        if(!notPrime.test(i))
        {
            for(int j=i*i;j<MAX;j+=i)notPrime.set(j);
            primes.push_back(i);
        }
    }
}

int n,comp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //----------------
    setPrimes();
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<primes.size();i++)
        {
            if(primes[i] > n/2)break;
            int comp = n - primes[i];
            if(!notPrime.test(comp))
            {
                printf("%d = %d + %d\n",n,primes[i],comp);
                break;
            }
        }
    }
    return 0;
}
