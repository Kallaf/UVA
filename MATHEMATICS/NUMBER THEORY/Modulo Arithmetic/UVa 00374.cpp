#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll mod;

ll moduloMultiplication(ll a,ll b) 
{ 
    ll res = 0;
    a %= mod; 
  
    while (b) 
    { 
        if (b & 1) 
            res = (res + a) % mod; 
        a = (2 * a) % mod; 
  
        b >>= 1;
    } 
  
    return res; 
} 

ll fastExp(ll base, ll p) {
    if (p == 0) return 1;
    if (p == 1) return base % mod;
    
    ll res = fastExp(base, p / 2);
    res = moduloMultiplication(res,res);
    if (p % 2 == 1) res = moduloMultiplication(res,base);
    return res; 
}

ll  b, p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    while(scanf("%lld%lld%lld",&b,&p,&mod) == 3)printf("%lld\n",fastExp(b,p));
    return 0;   
}
