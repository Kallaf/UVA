#include<iostream>
#include<string.h>
using namespace std;


class SegmetTree
{
    private:
        int mx[300000];
        int mn[300000];
        int lazy[300000];

        int left(int p){return p << 1;}
        int right(int p){return (p << 1) + 1;}

        void propgate(int p)
        {
           if(lazy[p])
            {
                mx[left(p)]= mn[left(p)] = lazy[left(p)] = lazy[p];
                mx[right(p)]= mn[right(p)] = lazy[right(p)] = lazy[p];
                lazy[p] = 0;
            } 
        }

        int update(int p,int l,int r,int i,int j,int h)
        {
            if(l > r)
                return 0;
            if(l != r)
                propgate(p);

            if(h < mn[p])return 0;
            
            if(i<=l && r<=j)
                if(mx[p] <= h)
                {
                    mx[p]= mn[p] = lazy[p] = h;
                    return r-l+1;
                }
            int result;
            if((l+r)/2 < i)
                result = update(right(p),(l+r)/2+1,r,i,j,h);
            else if(j <= (l+r)/2)
                result = update(left(p),l,(l+r)/2,i,j,h);
            else
            {
                result = update(left(p),l,(l+r)/2,i,(l+r)/2,h);
                result += update(right(p),(l+r)/2+1,r,(l+r)/2+1,j,h);
            }
            mx[p] = max(mx[left(p)],mx[right(p)]);
            mn[p] = min(mn[left(p)],mn[right(p)]);
            return result;
        }

    public:
        SegmetTree()
        {
            memset(mx,0,sizeof(mx));
            memset(mn,0,sizeof(mn));
            memset(lazy,0,sizeof(lazy));
        }
        int update(int i,int j,int h){return update(1,1,100000,i,j,h);}
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        SegmetTree buildings;
        while(n--)
        {
            int i,j,h;
            cin >> i >> j >> h;
            ans += buildings.update(i,j-1,h);
        }
        cout << ans << endl;
    }
    return 0;
}

