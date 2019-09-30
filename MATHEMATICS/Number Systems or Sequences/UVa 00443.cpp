#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

long n,cnt=0,unit;
vector<long> arr;
string suffix;
long factors[]={2,3,5,7};

int main()
{
    priority_queue <long, vector<long>, greater<long>> pq;
    pq.push(1l);
    set<long> s;
    while (arr.size()<5843) {
        long x=pq.top();
        pq.pop();
        if (!s.count(x)) {
            s.insert(x);
            arr.push_back(x);
            for (long f : factors) pq.push(x*f);
        }
    }
    while(scanf("%ld",&n),n)
    {
        if(n%100 == 11 || n%100 == 12 || n%100 == 13)suffix = "th";
        else{
            unit = n%10;
            switch(unit)
            {
                case 1:
                    suffix = "st";
                    break;
                case 2:
                    suffix = "nd";
                    break;
                case 3:
                    suffix = "rd";
                    break;
                default:
                    suffix = "th";
            }
        }
        cout << "The " << n << suffix << " humble number is "<< arr[n-1] << ".\n";
    }
    return 0;
}
