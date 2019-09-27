#include <iostream>
#include <math.h>

using namespace std;

int in;

int main()
{
    while(scanf("%d",&in),in)
    {
        int level = ceil(sqrt(in));
        int l = (level - 1)*(level - 1) + 1;
        int r = level * level;
        int middle = l + (r-l)/2;
        int x,y;
        if(in == middle)
        {
            cout << level << " " << level << endl;
            continue;
        }
        else if(in > middle){
            if(level%2)
            {
                y = level;
                x = level - (in - middle);
            }else
            {
                x = level;
                y = level - (in - middle);
            }
        }else
        {
            if(level%2)
            {
                x = level;
                y = level - (middle - in);
            }else
            {
                y = level;
                x = level - (middle - in);
            }
        }
        
        cout << x << " " << y << endl;
    }
    return 0;
}
