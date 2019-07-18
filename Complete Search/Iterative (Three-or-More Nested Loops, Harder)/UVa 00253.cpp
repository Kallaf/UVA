#include<iostream>

using namespace std;

//"HARD" problem ==== "HARD" code 😂

//face[0] left rotations:  {1,4,2,5,3,6},{1,5,4,3,2,6},{1,3,5,2,4,6}

int faces[6][6] = {
    {1,2,3,4,5,6},
    {2,6,3,4,1,5},
    {3,2,6,1,5,4},
    {4,2,1,6,5,3},
    {5,1,3,4,6,2},
    {6,5,3,4,2,1}
};

int left_rotation(int rotation,int i,int j)
{
    if(j == 0 || j == 5 || rotation == 0)return faces[i][j];

    if(rotation == 1)
    {
        if(j == 1)return faces[i][3];
        if(j == 2)return faces[i][1];
        if(j == 3)return faces[i][4];
        if(j == 4)return faces[i][2];
    }

    if(rotation == 2)
    {
        if(j == 1)return faces[i][4];
        if(j == 2)return faces[i][3];
        if(j == 3)return faces[i][2];
        if(j == 4)return faces[i][1];   
    }

    if(rotation == 3)
    {
        if(j == 1)return faces[i][2];
        if(j == 2)return faces[i][4];
        if(j == 3)return faces[i][1];
        if(j == 4)return faces[i][3];   
    }
    return faces[i][j];
}

string ans(char* cube1,char* cube2)
{
    for(int i=0;i<6;i++)
    {
        for(int rotation = 0;rotation<4;rotation++)
        {
            for(int j=0;j<6;j++)
            {
                if(cube1[left_rotation(rotation,i,j)-1] != cube2[j])break;
                if(j == 5)return "TRUE";
            }
        }
    }
    return "FALSE";
}

int main()
{
    char line[20];
    while(scanf("%s",line) != EOF)
    {
        char cube1[10],cube2[10];
        for(int i=0;i<6;i++)cube1[i]=line[i];cube1[6]='\0';
        for(int i=0;i<6;i++)cube2[i]=line[i+6];cube2[6]='\0';
        cout << ans(cube1,cube2) << endl;
    }
    return 0;
}
