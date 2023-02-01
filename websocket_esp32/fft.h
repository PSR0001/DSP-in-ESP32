#ifndef _FFT_H
#define _FFT_H
#include <arduinoFFT.h>

#define SAMPLES 1024        // Must be a power of 2
#define SAMPLING_FREQ 40000 // Hz, must be 40000 nyquiest Criteria
#define AMPLITUDE 1000      // roun
#define AUDIO_IN_PIN 25
#define NUM_BANDS 16
#define NOISE 500 // Noise
#define TOP 500   // set the Top Value

//Global variable
char buffer_analogread[20];
char buffer_fft[100];
unsigned long previousMillis = 0;
int interval = 100;

unsigned int sampling_period_us;
byte peak[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // The length of these arrays must be >= NUM_BANDS
int oldBarHeights[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int bandValues[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
double vReal[SAMPLES];
double vImag[SAMPLES];
unsigned long newTime;
arduinoFFT FFT = arduinoFFT(vReal, vImag, SAMPLES, SAMPLING_FREQ);





#endif




