#include<bits/stdc++.h>
using namespace std;

vector<int> getDivisors(int num)
{
    vector<int> v;
    int i=1;
    for(;i*i<num;i++)
    if(num%i == 0)
    {
            v.push_back(i);
            v.push_back(num/i);
    }
    if(i*i == num)
        v.push_back(i);
    return v;
}

int n,cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(scanf("%d",&n),n)
    {
        cnt = 0;
        vector<int> divisors = getDivisors(n);
        for(int i=0;i<divisors.size();i++)
            for(int j=i;j<divisors.size();j++)
                if(__gcd(divisors[i],divisors[j]) == 1)
                    cnt++;
        printf("%d %d\n",n,cnt);
    }
    return 0;
}
