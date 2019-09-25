#include <iostream>
#include <math.h>
using namespace std;

int n;

int main()
{
    
    while(scanf("%d",&n),n >= 0)
    {
        int i = (int)sqrt(n)+1;
        for(;i>1;i--)
        {
            int ccc = n;
            for(int j=0;j<i;j++)
            {
                if(ccc%i != 1)
                    goto o1;
                ccc -= ccc/i + 1;
            }
            goto o2;
            o1:
                continue;
            o2:
                if(ccc%i == 0)
                    goto o3;
        }
        printf("%d coconuts, no solution\n",n);
        continue;
        o3:
            printf("%d coconuts, %d people and 1 monkey\n",n,i);
    }
    return 0;
}
