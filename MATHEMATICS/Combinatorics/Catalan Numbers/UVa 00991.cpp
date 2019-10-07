#include <bits/stdc++.h>
using namespace std;


int n;
int pascalTree[21][21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //---------------------------
    for(int i=0;i<=20;i++)
      pascalTree[i][0] = 1;
    for(int n=1;n<=20;n++)
      for(int r=1;r<=n;r++)
        pascalTree[n][r] = pascalTree[n-1][r-1] + pascalTree[n-1][r];
    for(int i=0;cin >> n;i++)
    {
      if(i)cout << endl;
      cout << (pascalTree[2*n][n]/(n+1)) << endl;
    }
    return 0;
}
