// WaveOpticsCpp_Wrapper.h

#pragma once

using namespace System;

namespace ClsNac {

	public ref class WaveOpticsCpp_Wrapper
	{
		// TODO: このクラスの、ユーザーのメソッドをここに追加してください。

	public:
		static void Prop1D(double _lambda, int _dir,
			int _n1, array<double>^ _x1, array<double>^ _y1, array<double>^ _u1re, array<double>^_u1im,
			int _n2, array<double>^ _x2, array<double>^ _y2, array<double>^ _u2re, array<double>^_u2im);


		static void Prop2D(double _lambda, int _dir,
			int _n1, array<double>^_x1, array<double>^_y1, array<double>^_z1, array<double>^_u1re, array<double>^_u1im,
			int _n2, array<double>^_x2, array<double>^_y2, array<double>^_z2, array<double>^_u2re, array<double>^_u2im);

		static void Prop2D(double _lambda, int _dir,
			int _n1, array<double>^_x1, array<double>^_y1, array<double>^_z1, array<double>^_u1re, array<double>^_u1im, array<double>^_ds1,
			int _n2, array<double>^_x2, array<double>^_y2, array<double>^_z2, array<double>^_u2re, array<double>^_u2im);

		static void Prop2D(double _lambda, int _dir,
			int _n1, array<double, 2>^_x1, array<double, 2>^_y1, array<double, 2>^_z1, array<double, 2>^_u1re, array<double, 2>^_u1im,
			int _n2, array<double, 2>^_x2, array<double, 2>^_y2, array<double, 2>^_z2, array<double, 2>^_u2re, array<double, 2>^_u2im);

		static void Prop2D(double _lambda, int _dir,
			int _n1, array<double, 2>^_x1, array<double, 2>^_y1, array<double, 2>^_z1, array<double, 2>^_u1re, array<double, 2>^_u1im, array<double, 2>^_ds1,
			int _n2, array<double, 2>^_x2, array<double, 2>^_y2, array<double, 2>^_z2, array<double, 2>^_u2re, array<double, 2>^_u2im);

	};
}
