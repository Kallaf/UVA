#include<bits/stdc++.h>
#define isPerfectSquare(n) (floor(sqrt(n)) == ceil(sqrt(n)))
using namespace std;

long long int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    while(scanf("%lld",&n),n)printf("%s\n",isPerfectSquare(n)?"yes":"no");
    return 0;   
}
