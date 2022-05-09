\\ combine the following into one c program

X(f) = ∫x(t)e^-j2πftdt
H(f) = 1/(1 + (f/fc)^2)
x(t) = ∫X(f)e^j2πftdf


#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

int main()
{
    double x[1000], f[1000], X[1000], t, ft, fc, H[1000];
    int i, n, k;

    // Sampling rate
    fs = 1000;

    // Cutoff frequency
    fc = fs/2;

    // Number of samples
    n = 1000;

    // Sampling interval
    T = 1/fs;

    // Generating the signal
    for(i=0;i<n;i++)
    {
        t = i*T;
        x[i] = cos(2*PI*50*t) + cos(2*PI*120*t);
    }

    // Calculating the Fourier transform
    for(k=0;k<n;k++)
    {
        ft = 0;
        for(i=0;i<n;i++)
        {
            t = i*T;
            ft = ft + x[i]*exp(-j*2*PI*k*t/n);
        }
        X[k] = ft;
    }

    // Calculating the frequency response
    for(k=0;k<n;k++)
    {
        f[k] = k*fs/n;
        H[k] = 1/(1 + pow(f[k]/fc, 2));
    }

    // Converting the signal back to the time domain
    for(k=0;k<n;k++)
    {
        ft = 0;
        for(i=0;i<n;i++)
        {
            t = i*T;
            ft = ft + X[i]*H[i]*exp(j*2*PI*k*t/n);
        }
        x[k] = ft;
    }

    return 0;
}
