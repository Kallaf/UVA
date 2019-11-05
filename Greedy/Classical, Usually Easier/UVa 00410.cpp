#include<bits/stdc++.h>
using namespace std;

int c,s,specimens[20];
double IMBALANCE=0,avg;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    for(int tc=1;scanf("%d%d",&c,&s) == 2;tc++,IMBALANCE=0)
    {
        memset(specimens,0,sizeof(specimens));
        for(int i=0;i<s;i++)scanf("%d",specimens+i);
        sort(specimens,specimens+2*c);
        avg=accumulate(specimens,specimens+2*c,0)/(double)c;
        printf("Set #%d\n",tc);
        for(int i=0;i<c;i++)
        {
            printf(" %d:",i);
            if(specimens[i])printf(" %d",specimens[i]);
            if(specimens[2*c-1-i])printf(" %d",specimens[2*c-1-i]);
            printf("\n");
            IMBALANCE += abs((specimens[i]+specimens[2*c-1-i]) - avg);
        }
        printf("IMBALANCE = %.5lf\n\n",IMBALANCE);
    }
    return 0;   
}
