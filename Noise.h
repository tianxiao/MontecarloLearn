//Noise.h
#include "stdafx.h"
#ifndef _NOISE_H
#define _HOISE_H

void NoiseInit();
double Noise(double x, double y, double z);
double Noise(double x, double y, double z, double freq, double amplitude);
double NoiseSum(double x, double y, double z, int iter);
double NoiseAbsSum(double x, double y, double z, int iter);

#endif
