; This code produces a sine wave.

#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    double x, y;
    
    for (i=0; i<360; i++) {
        x = sin(i*3.14159/180);
        y = sin(i*2*3.14159/180);
        printf("%f %f\n", x, y);
    }
    
    return 0;
}
