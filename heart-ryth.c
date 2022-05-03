//  using Lissajous curves to visualize heart rhythms. 
//  use a signal input from heart as variable H. the code should display the heart pulses.
  


   #include <stdio.h>
   #include <math.h>
 
   int main()
   {
     int i;
     double t, H;
     for (t=0; t<10; t+=0.1)
       {
         H=0.5*(1+sin(2*M_PI*t));
         for (i=0; i<H; i++)
           printf("*");
         printf("\n");
       }
     return 0;
   }
