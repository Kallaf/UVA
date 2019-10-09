#include<bits/stdc++.h>
#include<cmath>

#define ll long long int
using namespace std;

ll N;

int main()
{
    for(int tc=1;cin >> N,N;tc++)cout << "Case " << tc <<": " << (ll)ceil((3+sqrt(9+8*N))/2) << endl;
    return 0;
}
