#include<iostream>
#include<math.h>

using namespace std;

const double sq2 = sqrt(2);
int t,n,c;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n == 1)printf("0.000\n");
        else printf("%.3lf\n",4*n-4 + sq2 * (n-2) * (n-2));
    }
    return 0;
}
