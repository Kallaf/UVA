#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Quadnode {
    public:
        char t;
        int pixels;
        vector<Quadnode*> childs;
        Quadnode(char _t,int _pixels) {
            t = _t;
            pixels = _pixels;
        }
};

int getPixels(Quadnode* head1,Quadnode* head2)
{
    if(head1->t == 'f')
        return head1->pixels;

    if(head2->t == 'f')
        return head2->pixels;


    Quadnode* temp = new Quadnode('e',0);
    if(head1->t == 'e')
    {
        if(head2->t == 'e')
            return 0;
        return getPixels(temp,head2->childs[0]) + getPixels(temp,head2->childs[1]) + getPixels(temp,head2->childs[2]) + getPixels(temp,head2->childs[3]);
    }
    if(head2->t == 'e')
        return getPixels(head1->childs[0],temp) + getPixels(head1->childs[1],temp) + getPixels(head1->childs[2],temp) + getPixels(head1->childs[3],temp);
    return getPixels(head1->childs[0],head2->childs[0]) + getPixels(head1->childs[1],head2->childs[1]) + getPixels(head1->childs[2],head2->childs[2]) + getPixels(head1->childs[3],head2->childs[3]);
    
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        Quadnode* head1 = new Quadnode(s1.at(0),1024);
        Quadnode* head2 = new Quadnode(s2.at(0),1024);
        stack<Quadnode*> parents;
        if(s1.at(0) == 'p')
            parents.push(head1);
        for(int i=1;i<s1.length();i++)
        {
            Quadnode* temp = new Quadnode(s1.at(i),parents.top()->pixels >> 2);
            parents.top()->childs.push_back(temp);
            if(parents.top()->childs.size() == 4)
                parents.pop();
            if(s1.at(i) == 'p')
                parents.push(temp);
        }
        if(s2.at(0) == 'p')
            parents.push(head2);
        for(int i=1;i<s2.length();i++)
        {
            Quadnode* temp = new Quadnode(s2.at(i),parents.top()->pixels >> 2);
            parents.top()->childs.push_back(temp);
            if(parents.top()->childs.size() == 4)
                parents.pop();
            if(s2.at(i) == 'p')
                parents.push(temp);
        }

        printf("There are %d black pixels.\n", getPixels(head1,head2));
    }
    return 0;
}
