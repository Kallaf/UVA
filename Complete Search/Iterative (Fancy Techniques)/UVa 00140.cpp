#include<iostream>
#include <bits/stdc++.h> 
#include<algorithm>

using namespace std;

int main()
{
    while(1)
    {
        string line;
        cin >> line;
        if(line == "#")break;
        bitset<32> bset;
        bool graph[32][32] = {0};
        for(int i=0;i<line.length();i++)
        {
            char curr = line[i];i+=2;
            bset[curr-'A']=1;
            for(;i<line.length() && line[i]!=';';i++)
            {
                bset[line[i]-'A']=1;
                graph[curr-'A'][line[i]-'A']=true;
                graph[line[i]-'A'][curr-'A']=true;
            }
        }
        int min_bandwidth = INT32_MAX;
        string s = "",min_s;
        for(char i='A';i<='Z';i++)
            if(bset[i-'A'])
                s += i;
        do{
            int bandwidth = 0;
            for(int i=0;i<s.length();i++)
                for(int j=0;j<s.length();j++)
                    if(graph[s[i]-'A'][s[j]-'A'])
                        bandwidth = max(bandwidth,abs(i-j));
            if(bandwidth < min_bandwidth)
            {
                min_bandwidth = bandwidth;
                min_s = s;
            }
        }while(next_permutation(s.begin(), s.end()));
        for(int i=0;i<min_s.length();i++)
            cout << min_s[i] << " ";
        cout << "-> " << min_bandwidth << endl;
    }
    return 0;
}
