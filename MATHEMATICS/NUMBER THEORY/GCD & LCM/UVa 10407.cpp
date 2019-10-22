#include<bits/stdc++.h>
using namespace std;

int f,s,gcd;

int main()
{
    while(scanf("%d\n",&f),f)
    {
        gcd = 0;
        while(scanf("%d",&s),s)
            gcd = __gcd(gcd,abs(s-f));
        printf("%d\n",gcd);
    }
    return 0;
}
