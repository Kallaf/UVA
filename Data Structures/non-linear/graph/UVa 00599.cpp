#include<iostream>
#include<string.h>
#include<vector>
#include<bitset>
using namespace std;

void dfs(vector<vector<char>> graph,bitset<32> &visited,char vertix)
{
    if(visited[vertix])return;
    visited[vertix] = 1;
    for(vector<char>::iterator neighbor = graph[vertix].begin(); neighbor != graph[vertix].end();++neighbor)
        dfs(graph,visited,*neighbor);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<vector<char>> graph(32);
        while(1)
        {
            string line;
            cin >> line;
            if(line.at(0) == '*')break;
            graph[line.at(1)-'A'].push_back(line.at(3)-'A');
            graph[line.at(3)-'A'].push_back(line.at(1)-'A');
        }
        vector<char> verticies;
        bitset<32> visited;
        char line[30];
        scanf("%s",line);
        int len = strlen(line);

        for(int i=0;i<len;i+=2)
            verticies.push_back(line[i]-'A');

        int trees = 0,acorns = 0;
        for(int i=0;i<verticies.size();i++)
        {
            if(!visited[verticies[i]])
            {
                if(!graph[verticies[i]].empty())
                {
                    dfs(graph,visited,verticies[i]);
                    trees++;
                }else
                    acorns++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n",trees,acorns);
    }
}
