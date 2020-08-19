#pragma once
#define __STDC_WANT_LIB_EXT1__ 1
#define  _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <varargs.h>
#include <stdarg.h>
#include <vector>
#include <ctime>
#include <deque>
#include <fstream>
#include <string> 
#include <fstream>
#include <filesystem>
#include <thread>

#pragma comment(lib,"libpng.lib")

#include <boost/gil.hpp>
#include <boost/container/vector.hpp>
#include <boost/gil/extension/io/png.hpp>
#include <boost/filesystem.hpp>

namespace fs = std::experimental::filesystem;
using namespace std;
using namespace boost::gil;

class MNN
{
private:
	int I_inputs = 0, I_layers = 0, I_outputs = 0, I_weights = 0, I_bias = 0;
	double E = 0.2;//0.2
	double A = 0.1;//0.1
	string path;
	vector <thread> main_threads;
	vector<vector<long double>> inputset;
	vector<vector<long double>> outputset;
	vector<vector<long double>> PREinputset;
	vector<vector<long double>> PREoutputset;
	vector<vector<long double>> hiden_neirons;
	vector<vector<long double>> na_hiden_neirons;
	vector<long double> out_neirons;
	vector<long double> na_out_neirons;
	vector<vector<long double>> weights;
	vector<vector<long double>> delta_weights;
	vector<long double> delta_out;
	vector<vector<long double>> delta_neirons;
	vector<vector<long double>> bias;
	vector<vector<long double>> delta_bias;
	vector<string> activation;
        void random_insert(vector<long double> &tmp)//рандомизаия вектора
	{
		for (auto &el : tmp)
		{
			//el = rand() % 3-1;
			el = (double)(rand()) / RAND_MAX * (0.5 - -0.5) + -0.5;
		}
	}
	void xavier_insert(vector<long double>& v, double n_in, double n_out);
	void calculate_hiden_neirons(vector<long double> input);
	void calculate_output();
	void calculate_d_output(vector<long double> ideal_out);
	void calculate_d_neirons();
	void calculate_d_weights(int n_set);
	void calculate_d_bias();
	void activating(int n_layer);
	vector<long double> sq_mse;
	long double derivate(int n_layer, int neirons);
	long double mse(vector<long double> ideal_out);
	long double SCCE(vector<long double> ideal_out);
	long double d_mse(int out,vector<long double> ideal_out);
	long double d_SCCE(int out,vector<long double> ideal_out);

public:
	MNN(int inputs, int outputs, int layers, ...);
	~MNN();
	long double sigmoid(long double x);
	long double derivate_sigmoid(long double x);
	void softmax(vector<long double>&x);
	long double derivate_softmax(int n_out);
	long double derivate_softmax(vector<long double> out, int n_out);
//	void read_from_directory(string path);
	void SetDataDirectory(string Path);
	void loadDataSet();
	void loadpngthread(size_t, size_t, vector<long double> &, rgb8_image_t &);//многопоточная загрузка png
	void start(int iter);
	void start(double acc);
	void set_activasion(int n_layer, string name_function);
	void shuffle();
	void save_weight();
};

