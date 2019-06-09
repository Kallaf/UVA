#include <stdio.h>

int main()
{
   
   int n;
   while(scanf("%d",&n),n)
   {
      int a=0,b=0,i,curr=1;
      for(i=0;i<32;i++)
      {
         if(n&(1<<i))
         {
            if(curr%2)
               a += (1<<i);
            else
               b += (1<<i);
            curr++;
         }
      }
      printf("%d %d\n",a,b);
   }
   return 0;
}
