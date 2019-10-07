#include <bits/stdc++.h>
using namespace std;

int x;
set<int> nums;
map<int,int> previous;
map<int,int> indexes;
vector<int> arr;
set<int>::iterator mx;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//---------------------------
	for(int i=0;cin >> x;i++)
	{
		set<int>::iterator it = nums.lower_bound(x);
		set<int>::iterator pre = it;

		if(it != nums.end())
		{
			if(nums.size() > 1)
				previous[i] = indexes[*(--pre)];
			else
				previous[i] = -1;
			nums.erase(it);
			
		}else
		{
			if(nums.empty())
				previous[i] = -1;
			else
			{
				mx = nums.end();
				previous[i] = indexes[*(--mx)];
			}
		}

		
		nums.insert(x);
		arr.push_back(x);
		indexes[x] = i;
	}
	cout << nums.size() << endl;
	cout << '-' << endl;
	vector<int> ans;
	mx = nums.end();
	for(int i = indexes[*(--mx)];i!=-1;i=previous[i])ans.push_back(arr[i]);
	for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << endl;
	return 0;
}
