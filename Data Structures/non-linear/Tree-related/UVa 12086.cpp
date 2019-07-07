#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi; 

class FenwickTree {
private: vi ft;
vi old_val;

int LSOne(int i){return i&(-i);}
// recall that vi is: typedef vector<int> vi;
public: FenwickTree(int n) { ft.assign(n + 1, 0);old_val.assign(n+1,0);}
// init n + 1 zeroes
int rsq(int b) {
// returns RSQ(1, b)
int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
return sum; }
// note: LSOne(S) (S & (-S))
int rsq(int a, int b) {
// returns RSQ(a, b)
return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
void adjust(int k, int v) {
// note: n = ft.size() - 1
int old_v = old_val[k];old_val[k] = v;
for (; k < (int)ft.size(); k += LSOne(k)) {ft[k] += v;ft[k]-=old_v; }
}
};

int main() {

    int tcase = 1;
    while(1)
    {
        int n;
        cin >> n;
        if(!n)break;
        if(tcase!=1)cout<<endl;
        printf("Case %d:\n", tcase++);
        FenwickTree tree(n);
        for (int i = 1; i <= n; i++) 
        {
            int input;
            cin >> input;
            tree.adjust(i, input);
        }
        while(1)
        {
            string action;
            cin >> action;
            if(action == "END")break;
            int a,b;
            cin >> a >> b;
            if(action == "M")
                cout << tree.rsq(a,b) << endl;
            else
                tree.adjust(a,b);

        }
    }

    return 0;
}
