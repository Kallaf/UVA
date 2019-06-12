#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool equals(string a,string b)
{
    if(a.at(0) == b.at(0))return true;
    if(a.at(1) == b.at(1))return true;
    return false;
}


void modify(int i,int end,vector<stack<string>> &piles)
{
    int k = i-1,l,flag1 = false,flag3 = false;
    while(k>=0 && piles[k].empty())k--;
    if(k>=0)
    {
        if(equals(piles[i].top(),piles[k].top()))
            flag1 = true;
        int counter = 0;
        l=k;
        for(l=k;l>=0;l--)
            if(!piles[l].empty())
            {
                counter++;
                if(counter == 3)break;
            }
        if(counter == 3 && (equals(piles[i].top(),piles[l].top())))
            flag3 = true;

    }

    if(flag3)
    {
        piles[l].push(piles[i].top());
        piles[i].pop();
        for(k=l;k<=end;k++)
            if(!piles[k].empty())modify(k,end,piles);
    }else if(flag1)
    {
        piles[k].push(piles[i].top());
        piles[i].pop();
        for(l=k;l<=end;l++)
            if(!piles[l].empty())modify(l,end,piles);
    }
}

int main()
{

    while(1)
    {
        vector<stack<string>> piles(60);
        string input;
        cin >> input;
        if(input == "#")break;
        for(int i=1;i<52;i++)
        {
            piles[i-1].push(input);
            cin >> input;
        }
        piles[51].push(input);

        for(int i=1;i<52;i++)
            modify(i,i,piles);
        int count = 0;
        vector<int> ans;
        for(int i=0;i<52;i++)
            if(!piles[i].empty())
            {
                count++;
                ans.push_back(piles[i].size());
            }
        if(count == 1)cout << "1 pile remaining: 52\n";
        else{
            cout << count << " piles remaining:";
            for(int i=0;i<count;i++)
                cout << " " << ans[i];
            cout << endl;
        }
    }
	return 0;
}
