#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <tuple>
using namespace std;

int main()
{
    string input;
    vector<vector<string>> titles;
	vector<tuple<string,int,int>> potential;
    vector<string> words_to_ignore;
    while(1)
    {
        cin >> input;
        if(input == "::")
            break;
        words_to_ignore.push_back(input);
    }
    std::cin.get();
    int title_count = 0;
    while(getline (cin, input))
    {
        char copy[200];
        strcpy(copy, input.c_str());
        char *token = strtok(copy, " ");
        int i = 0;
        vector<string> temp; 
        while (token != NULL) 
        { 
            string ttt = token;
            transform(ttt.begin(), ttt.end(), ttt.begin(), ::tolower); 
            temp.push_back(ttt);
            if(std::find(words_to_ignore.begin(), words_to_ignore.end(), ttt) == words_to_ignore.end())
                potential.push_back({ttt,title_count,i});
            token = strtok(NULL, " "); 
            i++;
        }   
        title_count++;
        titles.push_back(temp);
      }
    sort(potential.begin(),potential.end());
    for(auto tt:potential)
    {
        string ttt = titles[std::get<1>(tt)][0];
        if(0 == std::get<2>(tt))
            transform(ttt.begin(), ttt.end(), ttt.begin(), ::toupper);
        else
            transform(ttt.begin(), ttt.end(), ttt.begin(), ::tolower); 
        cout << ttt; 
        for(int i=1;i<titles[std::get<1>(tt)].size();i++)
        {
            string ttt = titles[std::get<1>(tt)][i];
            if(i == std::get<2>(tt))
                transform(ttt.begin(), ttt.end(), ttt.begin(), ::toupper);
            else
                transform(ttt.begin(), ttt.end(), ttt.begin(), ::tolower); 
            cout << " " << ttt; 
        }
        cout << endl;
    }
	return 0;
}

