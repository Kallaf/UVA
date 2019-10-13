#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int groupsContains[80] = {0};
    groupsContains[1] = groupsContains[2] = 1;
    for(n=3;n<=76;n++)
        groupsContains[n] = groupsContains[n-2] + groupsContains[n-3];
    while(cin >> n)cout << (groupsContains[n] + groupsContains[n-1]) << endl;
    return 0;
}
