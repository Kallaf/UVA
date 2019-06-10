#include <iostream>
#include <string.h>
#include <list> 
#include <iterator>
using namespace std;

int main()
{
    char buffer[100005];
    while(scanf("%s",buffer) != EOF)
    {
        list <char> monitor;
        list <char> :: iterator it = monitor.end();
        int length = strlen(buffer);
        for (int i = 0; i < length; ++i) 
        { 
            if(buffer[i] == '[')
                it = monitor.begin();
            else if(buffer[i] == ']')
                it = monitor.end();
            else
                monitor.insert(it,buffer[i]);
        }  
        for(it = monitor.begin(); it != monitor.end(); ++it) 
            cout << *it; 
        cout << '\n'; 
    }
	return 0;
}
