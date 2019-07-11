#include<iostream>
#include<string.h>

using namespace std;

typedef long long int ll;
const char *premutation[6] = {"BCG","BGC","CBG","CGB","GBC","GCB"};

int main()
{
    ll arr[5][5];
    while(scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&arr[0][0],&arr[0][2],&arr[0][1],&arr[1][0],&arr[1][2],&arr[1][1],&arr[2][0],&arr[2][2],&arr[2][1]) != EOF)
    {
        char ans[5];
        ll sum = 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                sum += arr[i][j];
        ll mn = sum + 10l;
        int index = 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)if(j!=i)
                for(int k=0;k<3;k++)if(k!=i && k!=j)
                {
                    ll moves = sum - arr[0][i] - arr[1][j] - arr[2][k];
                    if(moves < mn)
                    {
                        mn = moves;
                        strcpy(ans,premutation[index]);
                    }
                    index++;
                }      
            
        printf("%s %lld\n",ans,mn );
    }
    return 0;
}
