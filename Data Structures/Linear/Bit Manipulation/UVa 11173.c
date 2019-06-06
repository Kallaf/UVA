#include <stdio.h>

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n,k;
      scanf("%d%d",&n,&k);
      int ans = 0,pow2 = 1<<n;
      while(pow2>1)
      {
         pow2 >>=1;
         if(k >= pow2)
         {
            ans += pow2;
            k = (pow2<<1) - k - 1;
         }
      }
      printf("%d\n",ans);
   }
   return 0;
}
