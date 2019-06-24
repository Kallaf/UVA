#include <iostream>
#include <vector>
#include <string>
using namespace std;

class UnionFind {
    private: 
        vector<int> p, rank;
    public:
        UnionFind(int N)
        {
            rank.assign(N+3, 0);
            p.assign(N+3, 0);
            for (int i = 1; i <= N; i++)
                p[i] = i;
        }
        int findSet(int i)
        {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j)
        {
            return findSet(i) == findSet(j);
        }
        void unionSet(int i, int j)
        {
            if (!isSameSet(i, j)){
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y])
                    p[y] = x;
                else {
                    p[x] = y;
                    if (rank[x] == rank[y]) 
                        rank[y]++; 
                }
            } 
        } 
};


int main()
{
    int t;
    cin >> t;
    for(int tc=0;tc<t;tc++)
    {
        int N;
        scanf("%d\n",&N);
        UnionFind network = UnionFind(N);
        int yes=0,no=0;
        while(1)
        {
            string str;
            getline(cin,str);
            if(str == "")break;
            string delimiter = " ";

            vector<string> splitted;
            size_t pos = 0;
            string token;
            while ((pos = str.find(delimiter)) != string::npos) {
                token = str.substr(0, pos);
                splitted.push_back(token);
                str.erase(0, pos + delimiter.length());
            }
            splitted.push_back(str);
            int comp1 = stoi(splitted[1]),comp2 = stoi(splitted[2]);
            if(splitted[0] == "c")
            {
                network.unionSet(comp1,comp2);
            }else{
                if(network.isSameSet(comp1,comp2))
                    yes++;
                else
                    no++;
            }
        }
        if(tc)printf("\n");
        printf("%d,%d\n",yes,no);
    }
    return 0;
}
