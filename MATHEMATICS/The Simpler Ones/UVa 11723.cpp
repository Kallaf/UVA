#include <iostream>
#include <math.h>
using namespace std;

float r,n;
int tc = 0;

int main()
{
    while(scanf("%f%f",&r,&n),r||n)
    {
        r -= n;
        if(r/n > 26)
            printf("Case %d: impossible\n",++tc);
        else
            printf("Case %d: %d\n",++tc,(int)ceil(r/n));
    }
    return 0;
}
