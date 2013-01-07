// Montecarlo.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
#include <math.h>
#include "../gaps/pkgs/R3Graphics/R3Graphics.h"
#include "Vector.h"
using namespace CDLib;
#include <vector>
#include <string>
using std::string;
#include "Noise.h"
// Be careful to the postion of the "stdafx.h" 
// If I put the "stdafx.h" header file at the top
// The R3Graphics.h could include all it's dependecy header files
#include "stdafx.h"

double globalstate = 0;
double globali = 0;
double globalj = 0;

static char *scenename = NULL;
static char *imagename = NULL;
static const int imagewidth = 512;
static const int imageheight = imagewidth/4*3;
static const int actualwidth = 512;
static const int actualheight = 512;
//static RNBoolean print_verbose = FALSE;



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

