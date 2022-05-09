MATHS AND CODE IN DRAFT STAGE, NOT CHECK

# tec-Lissajous
tec1 experiments with Lissajous curves

### 20 uses of Lissajous curves 

1. To visualize periodic signals
2. To analyze the waveform of a signal
3. To optimize the sound quality of recordings or live performances
4. To visualize heart rhythms
5. To diagnose heart conditions
6. To plan heart treatment
7. To study mechanical vibrations
8. To identify resonant frequencies
9. To analyze electromagnetic waveforms
10. To design electronic filters
11. To troubleshoot electronic circuits
12. To study wave propagation in fluids
13. To visualize sound waves
14. To analyze data from accelerometers
15. To study the motion of particles in a fluid
16. To investigate the dynamics of mechanical systems
17. To study the behavior of coupled oscillators
18. To design optical communication systems
19. To study the interference of light waves
20. To investigate the properties of waveguides

## 3 use FAST FOURIER TRANSFORM to make a audio more clear and free from distortion 
mathematical steps
1. Convert the signal from the time domain to the frequency domain using the Fourier transform. The Fourier transform of a signal x(t) is given by:
```
X(f) = ∫x(t)e^-j2πftdt
```
where f is the frequency in Hz and t is time in seconds.

2. Identify the frequencies that are causing distortion.  The frequencies that are causing distortion are the frequencies that are not integer multiples of the fundamental frequency. These are called harmonic frequencies. If the fundamental frequency is f, then the harmonic frequencies are 2f, 3f, 4f, 5f, etc.


3. Apply a filter to remove the distortion-causing frequencies.  The way to remove the harmonic frequencies is to filter the signal. This can be done using a low pass filter, which allows frequencies below a certain cutoff frequency to pass through and blocks frequencies above the cutoff frequency. The cutoff frequency is usually chosen to be the Nyquist frequency, which is half the sampling rate. if the sampling rate is fs, then the Nyquist frequency is fs/2. This means that the cutoff frequency for the low pass filter is fs/2.  Thus, the frequencies that are removed by the low pass filter are the frequencies above fs/2.
The mathematical model for a low pass filter applied to frequency f is: 
```
H(f) = 1/(1 + (f/fc)^2)
```
where fc is the cutoff frequency.


4. Convert the signal back to the time domain using the inverse Fourier transform.  The inverse Fourier transform of a signal X(f) is given by:
```
x(t) = ∫X(f)e^j2πftdf
```
where f is the frequency in Hz and t is time in seconds.

