// Montecarlo.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include <math.h>
#include "../gaps/pkgs/R3Graphics/R3Graphics.h"
#include "../gaps/pkgs/R2Shapes/R2Image.h"
#include "../gaps/pkgs/R3Graphics/R3Scene.h"
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
using namespace std;

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
static bool print_verbose = false;
int grid_dimension = 3;
int render_passes = 1;

int linesrendered = 0;
int linesdrawn = 0;

#define CDVECTOR(x) (*(Vector3f*)&x)
#define R3VECTOR(x) (*(R3Vector*)&x)

float pixelsums[imagewidth][imageheight][4] = {0};
float pixelvalues[actualwidth][actualheight][4] = {0};
int pixelcounts[imagewidth][imageheight]={0};

int win;

bool changed = true;
R2Image *image ;
R3Scene *scene ;

unsigned int texId = 0;



int _tmain(int argc, _TCHAR* argv[])
{
	NoiseInit();

	return 0;
}

