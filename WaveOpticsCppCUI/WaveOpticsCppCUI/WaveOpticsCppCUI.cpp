﻿// WaveOpticsCppCUI.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "WaveOpticsCpp.h"

int main()
{
	const int SOURCE_N = 1;
	const int MIRROR_N = 100;
	const int FOCUS_N = 100;

    //std::cout << "Hello World!\n"; 
	//座標読込
	//source
	double* source_x = new double[SOURCE_N];
	double* source_y = new double[SOURCE_N];
	double* source_z = new double[SOURCE_N];
	double* source_re = new double[SOURCE_N];
	double* source_im = new double[SOURCE_N];
	printf("source\r");
	read("\sourcex.txt", SOURCE_N, source_x);
	//read("", SOURCE_N, source_y);
	//read("", SOURCE_N, source_z);
	//read("", SOURCE_N, source_re);
	//read("", SOURCE_N, source_im);
	//mirror
	double* mirror_x = new double[MIRROR_N];
	double* mirror_y = new double[MIRROR_N];
	double* mirror_z = new double[MIRROR_N];
	double* mirror_re = new double[MIRROR_N];
	double* mirror_im = new double[MIRROR_N];
	printf("mirror\r");
	//read("", MIRROR_N, mirror_x);
	//read("", MIRROR_N, mirror_y);
	//read("", MIRROR_N, mirror_z);
	//read("", MIRROR_N, mirror_re);
	//read("", MIRROR_N, mirror_im);

	//focus
	double* focus_x;
	double* focus_y;
	double* focus_z;
	double* focus_re;
	double* focus_im;

	//Propagation
	WaveOpticsCpp::Prop2D(1.25e-10, -1,
		100, source_x, source_y, source_z, source_re, source_im,
		100, mirror_x, mirror_y, mirror_z, mirror_re, mirror_im);
}

static void read(std::string _fileName,int _nData,double* _data)
{
	std::ifstream ifs(_fileName);
	double a;
	int i = 0;
	while (ifs >> a)
	{
		_data[i] = a;
		i++;
	}
	ifs.close();

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
