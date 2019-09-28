#include <iostream>
#include <math.h>

using namespace std;

int n,level,diff,up,df;

const int starts[][2] = { {1,0},{1,-1},{0,-1},{-1,0},{-1,1},{0,1} };
const int dir[][2] = { {0,-1},{-1,0},{-1,1},{0,1},{1,0},{1,-1} };

int main()
{
    while(scanf("%d",&n) != EOF)
    {
        if(n == 1)
        {
            printf("0 0\n");
            continue;
        }
        level = n==1?0:(-3 + floor(sqrt(9+4*3*(n-2)))) / 6 + 1;
        up = 6*(level*(level+1))/2 + 1;
        diff = up - n;
        df = diff%level;
        int x = level * starts[diff/level][0] + df*dir[diff/level][0];
        int y = level * starts[diff/level][1] + df*dir[diff/level][1];
        printf("%d %d\n",x,y);
    }
    return 0;
}
