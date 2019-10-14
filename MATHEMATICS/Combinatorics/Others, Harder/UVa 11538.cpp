#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,m;

int main()
{
    while(cin >> n >> m,n)
    {
        if(n>m)swap(n,m);
        ll inRow = m*(m-1);
        ll inCol = n*(n-1);
        ll inDiag = n*(n-1)*(m-n+1);
        for(ll i=2;i<n;i++)
            inDiag += 2*i*(i-1);
        inDiag *= 2;
        ll res = n * inRow + m * inCol + inDiag;
        cout << res << endl;
    }

    return 0;
}
