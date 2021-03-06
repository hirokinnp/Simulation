// これは メイン DLL ファイルです。

#include "stdafx.h"
#include <math.h>
#include "cuWaveOptics.h"
#include <cuda_runtime.h>

__global__ void kernelProp1D(const double _k,const int _dir,
	const int _n1, const double* _x1, const double* _y1, const double* _u1re, const double* _u1im,
	const int _n2, const double* _x2, const double* _y2, double* _u2re, double* _u2im);

__global__ void kernelProp1D_f(const float _k,const int _dir,
	const int _n1, const float* _x1, const float* _y1, const float* _u1re, const float* _u1im,
	const int _n2, const float* _x2, const float* _y2, float* _u2re, float* _u2im);

dim3 calcBlock(dim3 thread, int x, int y)
{
	return dim3(
		static_cast<int>(ceil(1.0*x / thread.x)),
		static_cast<int>(ceil(1.0*y / thread.y)));
}

dim3 calcBlock(dim3 thread, int x)
{
	return dim3(
		static_cast<int>(ceil(1.0*x / thread.x)));
}



void ClsNac::cuWaveOptics::Propagate1D(
	int _dir,
	int _n1,array<double>^ _x1, array<double>^ _y1, array<double>^_u1r, array<double>^_u1i,
	int _n2,array<double>^ _x2, array<double>^ _y2, array<double>^ _u2r, array<double>^ _u2i)
{
	dim3 gridDim;
	dim3 blockDim;

	pin_ptr<double> p_k = &k;
	pin_ptr<double> p_x1 = &_x1[0];
	pin_ptr<double> p_y1 = &_y1[0];
	pin_ptr<double> p_u1r = &_u1r[0];
	pin_ptr<double> p_u1i = &_u1i[0];
	pin_ptr<double> p_x2 = &_x2[0];
	pin_ptr<double> p_y2 = &_y2[0];
	pin_ptr<double> p_u2r = &_u2r[0];
	pin_ptr<double> p_u2i = &_u2i[0];

	void* args[12];
	args[0] = p_k;
	args[1] = &_dir;
	args[2] = &_n1;
	args[3] = p_x1;
	args[4] = p_y1;
	args[5] = p_u1r;
	args[6] = p_u1i;
	args[7] = &_n2;
	args[8] = p_x2;
	args[9] = p_y2;
	args[10] = p_u2r;
	args[11] = p_u2i;

	cudaSetDevice(0);
	cudaLaunchKernel((const void*)&kernelProp1D, gridDim, blockDim, args);
}

void ClsNac::cuWaveOptics::Propagate1D(
	int _dir,
	int _n1, array<float>^ _x1, array<float>^ _y1, array<float>^_u1r, array<float>^_u1i,
	int _n2, array<float>^ _x2, array<float>^ _y2, array<float>^ _u2r, array<float>^ _u2i)
{
	dim3 gridDim;
	dim3 blockDim;

	pin_ptr<float> p_k = &k_f;
	pin_ptr<float> p_x1 = &_x1[0];
	pin_ptr<float> p_y1 = &_y1[0];
	pin_ptr<float> p_u1r = &_u1r[0];
	pin_ptr<float> p_u1i = &_u1i[0];
	pin_ptr<float> p_x2 = &_x2[0];
	pin_ptr<float> p_y2 = &_y2[0];
	pin_ptr<float> p_u2r = &_u2r[0];
	pin_ptr<float> p_u2i = &_u2i[0];

	void* args[12];
	args[0] = p_k;
	args[1] = &_dir;
	args[2] = &_n1;
	args[3] = p_x1;
	args[4] = p_y1;
	args[5] = p_u1r;
	args[6] = p_u1i;
	args[7] = &_n2;
	args[8] = p_x2;
	args[9] = p_y2;
	args[10] = p_u2r;
	args[11] = p_u2i;

	cudaSetDevice(0);
	cudaLaunchKernel((const void*)&kernelProp1D, gridDim, blockDim, args);
}

