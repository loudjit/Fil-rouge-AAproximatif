#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(void)
{
   long clk_tck = CLOCKS_PER_SEC; //déclarations diverses
   clock_t t1, t2;
   int i;
   int y;
   int j;
   int a = 0;

   
   t1 = clock(); /* Recuperation du temps initial en "clock ticks" */

   /* construction des arbres */
    for (y = 0; y < 1000000000; y++);
        j += 36*5*9 ;
    
   
   
   t2 = clock(); /* Recuperation du temps final en "clock ticks" */

   printf("Durée de construction : %lf \n",
                (double)(t2-t1)/(double)clk_tck *1000);
      
   return EXIT_SUCCESS;
}