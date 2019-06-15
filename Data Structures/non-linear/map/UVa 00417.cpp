#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

map<string, int> dictionary;

void bulid()
{
    queue<string> dict;
    for(char i='a';i<='z';i++)dict.push(string(1,i));
    int current = 1;
    while(!dict.empty())
    {
        string temp = dict.front();dict.pop();
        dictionary[temp] = current++;
        if(temp.size()<5)
            for(char i=temp[temp.size()-1]+1;i<='z';i++)dict.push(string(temp+i));
    }
}

int main()
{
    bulid();
    char input[10];
    while(scanf("%s",input) != EOF)
    {
        std::map<string,int>::iterator it;
        it = dictionary.find(input);
        if (it != dictionary.end())
            printf("%d\n",it->second);
        else
            printf("0\n");
    }

	return 0;
}
