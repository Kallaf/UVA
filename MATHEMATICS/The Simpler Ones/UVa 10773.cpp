#include <iostream>
#include <math.h>

using namespace std;

int t;
double d,v,u,h;

int main()
{
    cin >> t;
    for(int tc=1;tc<=t;tc++)
    {
    	cin >> d >> v >> u;
        h = sqrt(u*u - v*v);

        if(u<=v || v == 0)
            printf("Case %d: can't determine\n", tc);
        else
            printf("Case %d: %.3lf\n", tc,d/h - d/u);
    }

    return 0;
}
