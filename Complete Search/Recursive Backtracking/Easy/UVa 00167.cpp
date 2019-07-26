#include<iostream>
#include<bitset>
using namespace std;

bitset<30> rw, ld, rd;
int weights[70][70],cols[10];
int maxScore;

void  backtrack(int c) {
    if (c == 8) 
    {
        int score = 0;
        for(int i=0;i<8;i++)score += weights[i][cols[i]];
        maxScore = max(maxScore,score);
        return; 
    }
    for (int r = 0; r < 8; r++)
    if (!rw[r] && !ld[r - c + 8 - 1] && !rd[r + c]) {
        rw[r] = ld[r - c + 8 - 1] = rd[r + c] = true;
        cols[c] = r;
        backtrack(c + 1);
        rw[r] = ld[r - c + 8 - 1] = rd[r + c] = false;
    }
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        for(int i=0;i<8;i++)for (int j = 0; j < 8; j++)scanf("%d",&weights[i][j]);
        maxScore = 0;
        backtrack(0);
        printf("%5d\n",maxScore);
    } 
    return 0;
}
