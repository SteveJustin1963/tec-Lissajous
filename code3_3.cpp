// code3_3
// This program applies a low-pass filter to an input signal in order to remove distortion-causing frequencies.

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    double x[n], y[n];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        cin >> y[i];
    double X[n], Y[n];
    for(int i = 0; i < n; i++)
    {
        X[i] = 0;
        Y[i] = 0;
        for(int j = 0; j < n; j++)
        {
            X[i] += x[j] * cos(2 * M_PI * i * j / n);
            Y[i] += y[j] * sin(2 * M_PI * i * j / n);
        }
    }
    double P[n], Q[n];
    for(int i = 0; i < n; i++)
    {
        P[i] = (1 / n) * X[i];
        Q[i] = (1 / n) * Y[i];
    }
    double R[n];
    for(int i = 0; i < n; i++)
        R[i] = sqrt(pow(P[i], 2) + pow(Q[i], 2));
    int m = *max_element(R, R + n);
    int T = m * k;
    for(int i = 0; i < n; i++)
    {
        if(R[i] < T)
        {
            P[i] = 0;
            Q[i] = 0;
        }
    }
    double S[n];
    for(int i = 0; i < n; i++)
        S[i] = atan2(Q[i], P[i]);
    double a[n], b[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = 0;
        b[i] = 0;
        for(int j = 0; j < n; j++)
        {
            a[i] += P[j] * cos(2 * M_PI * i * j / n) + Q[j] * sin(2 * M_PI * i * j / n);
            b[i] += -P[j] * sin(2 * M_PI * i * j / n) + Q[j] * cos(2 * M_PI * i * j / n);
        }
    }
    for(int i = 0; i < n; i++)
        cout << a[i] / n << " ";
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << b[i] / n << " ";
    cout << endl;
    return 0;
}
