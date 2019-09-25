#include <iostream>

using namespace std;

int n,m;

int main()
{
    
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n),n)
    {
        m = 0;
        for(int i=1;i<=n/2;i++)
            if(!(n%i))m+=i;
        printf("%5d  %s\n",n,m == n?"PERFECT":m<n?"DEFICIENT":"ABUNDANT");
    }
    printf("END OF OUTPUT\n");

    return 0;
}
