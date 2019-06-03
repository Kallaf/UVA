#include <stdio.h>

typedef struct Computer{
   int printed_year;
   int a;
   int b;
}Computer;

int main()
{
   int tc = 1;
   while(1)
   {
      int n,i,actual_year=0;
      scanf("%d",&n);
      if(!n)break;
      Computer computers[23];
      for(i=0;i<n;i++)
      {
         scanf("%d%d%d",&computers[i].printed_year,&computers[i].a,&computers[i].b);
         if(actual_year<computers[i].printed_year)actual_year = computers[i].printed_year;
      }

      for(;actual_year<10000;actual_year++)
      {
         int count = 0;
         for(i=0;i<n;i++)
         {
            int printed_year = (actual_year - computers[i].a) % (computers[i].b - computers[i].a) + computers[i].a;
            if(printed_year == computers[i].printed_year)
               count++;
         }
         if(count == n)
            break;
      }
      printf("Case #%d:\n",tc++);
      if(actual_year < 10000)
         printf("The actual year is %d.\n\n", actual_year);
      else
         printf("Unknown bugs detected.\n\n");
      
   }
   return 0;
}
