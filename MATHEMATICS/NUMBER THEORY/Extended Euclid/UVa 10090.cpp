#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,c1,c2,n1,n2,m1,m2,g,d,t1,t2,cost,cost1,cost2;

void extendedEuclid(ll a, ll b) {
    if (b == 0) { m1 = 1; m2 = 0; d = a; return; }
    // base case
    extendedEuclid(b, a % b);
    // similar as the original gcd
    ll x = m2;
    ll y = m1 - (a / b) * m2;
    m1 = x;
    m2 = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    while(scanf("%lld",&n),n)
    {
        scanf("%lld%lld%lld%lld",&c1,&n1,&c2,&n2);
        extendedEuclid(n1,n2);
        if(n%d != 0){
            printf("failed\n");
            continue;
        }
        g = __gcd(n1,n2);
        m1 *= n/g;
        m2 *= n/g;
        // m2 = (temp*m2  / n1/gcd(n1,n2)) <= var <= (temp*m1 / n2/gcd(n1,n2));
        ll lw = ceil((double)-m1*g / n2);
        ll up = floor((double)m2*g  / n1);
        if(up < lw){
            printf("failed\n");
            continue;
        }


        t1 = m1 + n2/g*lw;
        t2 = m2 - n1/g*lw;
        m1 = m1 + n2/g*up;
        m2 = m2 - n1/g*up;

        cost1 = t1*c1 + t2* c2;
        cost2 = m1*c1 + m2* c2;
        if(cost1 < cost2)
            printf("%lld %lld\n",t1,t2);
        else
            printf("%lld %lld\n",m1,m2);
    }
    return 0;   
}
