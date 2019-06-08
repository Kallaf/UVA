#include <iostream>
using namespace std;

int main()
{
    while(1)
    {
    	int n,m;
    	cin >> n >> m;
    	if(!n && !m)break;
    	bool minutes[1000005] = {0};
    	bool conflict = 0;
    	while(n--)
    	{
    		int start,end;
    		cin >> start >> end;
			for(int i=start+1;i<=end && !conflict;i++)
			{
				if(minutes[i])conflict = 1;
				minutes[i] = 1;
			}
    	}

    	while(m--)
    	{
    		int start,end,interval;
    		cin >> start >> end >> interval;
    		end = end - start;
    		for(int j = start;j<=1000000 && !conflict;j+=interval)
    		{
    			if(j+end>1000000)end = 1000000 -j;
				for(int i=j+1;i<=j+end && !conflict;i++)
				{
					if(minutes[i])conflict = 1;
					minutes[i] = 1;
				}
    		}
    	}

    	cout << (conflict?"CONFLICT":"NO CONFLICT") << endl;

    }
	return 0;
}
