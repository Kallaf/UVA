#include <bits/stdc++.h>
#define SIZE 300005
using namespace std;

int tc=1,n, m, u,arr[SIZE],len,l, r , v , p;

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    scanf("%d%d%d",&n, &m, &u);
    for(int i=1;i<=n;i++)
        scanf("%d",arr+i);
}

void solve()
{       
    len = (int) sqrt (n + 1.0) + 1;
    vector<vector<int>> b (len);
    int curr = 0;
    for (int i=1; i<=n; ++i)
    {
        if(i/len != curr)
        {
            sort(b[curr].begin(),b[curr].end());
            curr = i/len;
        }
        b[curr].push_back(arr[i]);
    }
    sort(b[curr].begin(),b[curr].end());
    while(m--)
    {
        scanf("%d%d%d%d",&l,&r ,&v ,&p);

        int k = 0;
        int c_l = l / len,   c_r = r / len;
        if (c_l == c_r)
            for (int i=l; i<=r; ++i)
            {
                if(arr[i] < v)k++;
            }
        else {
            for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
                if(arr[i] < v)k++;
            for (int i=c_l+1; i<=c_r-1; ++i)
                k += (lower_bound(b[i].begin(),b[i].end(),v) - b[i].begin());
            for (int i=c_r*len; i<=r; ++i)
                if(arr[i] < v)k++;
        }
        curr = p/len;
        vector<int>::iterator it = find(b[curr].begin(),b[curr].end(),arr[p]); 
        arr[p] = (int)(u * (long long int)k/(r - l + 1));
        *it = arr[p];
        sort(b[curr].begin(),b[curr].end());
    }
    for(int i=1;i<=n;i++)printf("%d\n",arr[i]);
}

int main()
{
    preprocess();
    while(tc--){
        input();
        solve();
    }
    return 0;
}
