#include <iostream>
#include <queue>

using namespace std;

int main()
{
    string reg;
    priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>> > queries;
    int ID[3005];
    while(1)
    {
        cin >> reg;
        if(reg == "#")break;
        int id,period;
        cin >> id >> period;
        queries.push({period,id});
        ID[id] = period;
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        pair<int,int> temp = queries.top();
        cout << temp.second << endl;
        queries.pop();
        temp.first += ID[temp.second];
        queries.push(temp);
    }
	return 0;
}
