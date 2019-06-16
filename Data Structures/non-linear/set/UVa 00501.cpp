#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=0;tc<t;tc++)
    {
        if(tc)printf("\n");
        int m,n,input;
        scanf("%d%d",&m,&n);
        vector<int> database;
        while(m--)
        {
            scanf("%d",&input);
            database.push_back(input);
        }
        multiset<int> sorted;
        scanf("%d",&input);
        for(int i=0;i<input;i++)
            sorted.insert(database[i]);
        multiset<int> ::iterator it = sorted.begin();
        printf("%d\n",*it);
        int previous = input;
        for(int x=1;x<n;x++)
        {

            scanf("%d",&input);
            for(int i=previous;i<input;i++)
            {
                sorted.insert(database[i]);
                if(database[i]<*it)it--;
            }
            printf("%d\n",*(++it));
            previous = input; 
        }
    }
	return 0;
}
