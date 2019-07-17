#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<char,int> colors;
    colors['r'] = 0;colors['o'] = 1;
    colors['y'] = 2;colors['g'] = 3;
    colors['b'] = 4;
    while(1)
    {
        char block[106][5];int nBlocks = 1;
        while(1)
        {
            string str; 
            getline (cin, str);
            if(str[0] == '#')return 0;
            if(str[0] == 'e')break;

            for(int i=0;i<str.length();i+=4)
                block[nBlocks][colors[str[i]]] = str[i+2];
            nBlocks++;
        }
        int mn = INT32_MAX,mn_i;
        for(int i=1;i<=nBlocks;i++)
        {
            int changes = 0;
            for(int j=1;j<=nBlocks;j++)
                for(int k=0;k<5;k++)
                    if(block[i][k] != block[j][k])
                        changes++;
            if(changes<mn)
            {
                mn = changes;
                mn_i = i;
            }
        }
        cout << mn_i << endl;
    }
    return 0;
}
