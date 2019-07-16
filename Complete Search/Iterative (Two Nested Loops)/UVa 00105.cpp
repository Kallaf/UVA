#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

int main()
{
    int l,h,r;
    vector<tuple<int,int,int>> buildings;
    int last = 0,start = INT32_MAX,end = INT32_MIN;
    while(scanf("%d%d%d",&l,&h,&r) != EOF)
    {
        buildings.push_back(make_tuple(l,h,r));
        start = min(start,l);end = max(r,end);
    }
    for(int i=start;i<end;i++)
    {
        int height = 0;
        for(auto it = buildings.begin();it != buildings.end();it++)
        {
            if(get<0>(*it) <= i && i < get<2>(*it))
                height = max(height,get<1>(*it));
        }
        if(height != last)
        {
            cout << i << " " << height << " ";
            last = height;
        }
    }
    cout << end << " 0\n";
    return 0;
}
