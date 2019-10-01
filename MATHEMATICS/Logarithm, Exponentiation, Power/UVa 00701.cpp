#include <iostream>
#include <math.h>

using namespace std;

long long int n,m,i;
string str;

int main()
{
	while(cin >> str)
	{
		n = stoi(str);
		for(i=str.length()+1;(m=ceil(i*log2(10)+log2(n)))>i*log2(10)+log2(n+1);i++);
		cout << m << endl;
	}
	return 0;
}
