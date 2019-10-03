#include<iostream>
#include <map>
#include <algorithm>
#define ll long long int

using namespace std;

map<char,ll> cton = {{'V',0},{'U',1},{'C',2},{'D',3}};
const char ntoc[] = {'V','U','C','D'};

int t;
ll num1,num2;
string s,res;

ll ston()
{
	ll num = 0;
	for(int i=0;i<s.length();i++)
	{
		num *= 4;
		num += cton[s[i]];
	}
	return num;
}

string ntos()
{
	s = "";int i=0;
	for(;num2;i++)
	{
		s += ntoc[num2%4];
		num2/=4;
	}
	string zeros = "";
	for(;i<8;i++)
		zeros += "V";
	reverse(s.begin(),s.end());
	return zeros+s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << "COWCULATIONS OUTPUT\n";
	cin >> t;
	while(t--)
	{
		cin >> s;
		num1 = ston();
		cin >> s;
		num2 = ston();
		for(int i=0;i<3;i++)
		{
			cin >> s;
			if(s == "A")num2 += num1;
			else if(s == "L")num2 *= 4;
			else if(s == "R")num2 /= 4;
		}
		cin >> res;
		cout << (res == ntos()?"YES":"NO") << endl;
	}
	cout << "END OF OUTPUT\n";
	
	return 0;
}
