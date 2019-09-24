#include <iostream>
#include <math.h>

using namespace std;

int t;
double d,v,u;

int main()
{
    cin >> t;
    for(int tc=1;tc<=t;tc++)
    {
    	cin >> d >> v >> u;
        if(u<=v || !v)
            printf("Case %d: can't determine\n", tc);
        else
            printf("Case %d: %.3lf\n", tc,d/sqrt(u*u - v*v) - d/u);
    }

    return 0;
}
