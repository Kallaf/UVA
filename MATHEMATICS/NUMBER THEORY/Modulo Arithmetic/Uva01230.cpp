#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int tc=1;
ll x,y,n;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}

void input()
{
    scanf("%lld%lld%lld",&x,&y,&n);
}

void solve()
{   
    printf("%lld\n",binpow(x,y,n));
}

int main()
{
    preprocess();
    while(tc--){
        input();
        solve();
    }
    return 0;
}
