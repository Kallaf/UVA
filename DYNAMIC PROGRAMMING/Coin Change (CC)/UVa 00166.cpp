#include <iostream>
#include <vector>
#include <math.h>
#define INF 1000000009
using namespace std;

vector<int> shopkeeperMemo(105,-1);
int coinValue[] = {5,10,20,50,100,200};
int count[10];

int shopkeeperChange(int value)
{
    if(value == 0)return 0;
    if(value < 0)return INF;
    if(shopkeeperMemo[value/5] != -1)return shopkeeperMemo[value/5];
    int ans = INF;
    for(int i=0;i<6;i++)
        ans = min(ans,1+shopkeeperChange(value - coinValue[i]));
    return shopkeeperMemo[value/5] = ans;
}

int change(int value)
{
    if(value == 0)return 0;
    if(value < 0)return shopkeeperChange(value*-1);
    int ans = INF;
    for(int i=0;i<6;i++)
    if(count[i])
    {
        count[i]--;
        ans = min(ans,1+change(value - coinValue[i]));
        count[i]++;
    }
    return ans;
}

int main()
{
    while(1)
    {
        bool ext = true;
        for(int i=0;i<6;i++)
        {
            cin >> count[i];
            if(count[i])ext = false;
        }
        if(ext)break;
        double value;
        cin >> value;
        printf("%3d\n",change(value*100));
    }

    return 0;
}
