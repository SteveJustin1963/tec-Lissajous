
#include <iostream>
#include <complex>
#include <valarray>
 
const double PI = 3.141592653589793238460;
 
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
// Cooley–Tukey FFT (in-place, divide-and-conquer)
// Higher memory requirements and redundancy although more intuitive
void fft(CArray& x)
{
    const size_t N = x.size();
    if (N <= 1) return;
 
    // divide
    CArray even = x[std::slice(0, N/2, 2)];
    CArray  odd = x[std::slice(1, N/2, 2)];
 
    // conquer
    fft(even);
    fft(odd);
 
    // combine
    for (size_t k = 0; k < N/2; ++k)
    {
        Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k    ] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
}
 
// Cooley–Tukey FFT (in-place, brute-force)
// Better optimized but less intuitive
// !!! Warning : in some cases can give incorrect results !!!
// The bug is specially conspicuous for size = 16
void fft_optimized(CArray& x)
{
    // DFT
    const size_t N = x.size();
    const size_t N2 = N/2;
    for (size_t k = 0; k < N; k++)
    {
        Complex sum(0, 0);
        for (size_t n = 0; n < N; n++)
        {
            sum += x[n] * std::polar(1.0, -2 * PI * k * n / N);
        }
        x[k] = sum;
    }
 
    // FFT
    for (size_t stride = 1; stride < N; stride *= 2)
    {
        for (size_t i = 0; i < N; i += 2 * stride)
        {
            for (size_t j = 0; j < stride; j++)
            {
                Complex even = x[i + j];
                Complex odd  = x[i + j + stride];
                Complex exp = std::polar(1.0, -2 * PI * j / (2 * stride)) * odd;
                x[i + j    ] = even + exp;
                x[i + j + stride] = even - exp;
            }
        }
        stride *= 2;
    }
 
    // scaling (because this FFT implementation omits it)
    for (size_t i = 0; i < N; i++)
    {
        x[i] /= N;
    }
}

