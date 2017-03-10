#include "cuWaveOptics.h"



void Propagate1D(double _lambda, int _dir,
	int _n1, double * _x1, double * _y1, double * _u1re, double * _u1im,
	int _n2, double * _x2, double * _y2, double *& _u2re, double *& _u2im)
{
	double k = 2.0*PI / _lambda;

}

void Propagate1Df(float _lambda, int _dir, 
	int _n1, float * _x1, float * _y1, float * _u1re, float * _u1im,
	int _n2, float * _x2, float * _y2, float *& _u2re, float *& _u2im)
{
	float k = 2.0*PI / _lambda;

}

void Propagate2D(double _lambda, int _dir, int _n1, double * _x1, double * _y1, double * _z1, double * _u1re, double * _u1im, int _n2, double * _x2, double * _y2, double * _z2, double *& _u2re, double *& _u2im)
{
}

void Propagate2Df(float _lambda, int _dir, int _n1, float * _x1, float * _y1, float * _z1, float * _u1re, float * _u1im, int _n2, float * _x2, float * _y2, float * _z2, float *& _u2re, float *& _u2im)
{
}