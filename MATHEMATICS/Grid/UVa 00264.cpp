#include <iostream>
#include <math.h>

using namespace std;

int n,level,diff;

int main()
{
    while(scanf("%d",&n) != EOF)
    {
        level = (floor(sqrt(1+8*n-1)) - 1)/2 + 1;
        diff = level*(level+1)/2 - n;
        if(level%2)
            printf("TERM %d IS %d/%d\n",n,1+diff,level-diff);
        else    
            printf("TERM %d IS %d/%d\n",n,level-diff,1+diff);
    }
    return 0;
}
