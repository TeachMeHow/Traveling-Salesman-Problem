// This file contains definitions of functions from header under the
// same name
//
// Author: Szymon Cichy 235093
// Date: March 2018
//
#include "Performance.h"
#include "ATSP.h"
#include <chrono>
#include <fstream>
#include <random> // for random number generation
#include <iostream>

typedef std::chrono::high_resolution_clock Clock;
// Define in what time unit time will be measured
typedef std::chrono::milliseconds time_unit;
using namespace std;



void measure_all()
{
	using namespace std;
	// depending on op time, some size sets
	vector<int> N = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int N_S[10] = { 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000 };
	//int N_B[10] = { 10000, 20000, 50000, 100000, 200000, 500000, 1000000, 2000000, 5000000, 10000000 };
	ofstream file;

	string folder = "measurement_data/";
	file.open(folder.append("measurement.csv"), ios::out | ios::trunc);
	file.close();


}

void time_measurement()
{

	std::ofstream bf_file;
	bf_file.open("measurement.csv", std::ios::out | std::ios::app);
	bf_file << "N,Mean" << endl;

	std::ofstream bb_file;
	bb_file.open("measurement.csv", std::ios::out | std::ios::app);
	bb_file << "N,Mean" << endl;

	vector<int> N = { 2, 3, 4, 5, 6, 7, 8 };
	// 1.1 for each size N
	vector<double> bf_measurements;
	vector<double> bb_measurements;
	ATSP problem;
	for (int size : N)
	{
		// 1.2 100 random instances of ATSP
		for (size_t i = 0; i < 100; i++)
		{
			problem.generate_random(size);

			auto start = Clock::now();
			//START
			//END
			auto end = Clock::now();
			double duration = std::chrono::duration_cast<time_unit>(end - start).count();
			bf_measurements.push_back(duration);

			start = Clock::now();
			//START
			//END
			end = Clock::now();
			duration = std::chrono::duration_cast<time_unit>(end - start).count();
			bb_measurements.push_back(duration);
		}
		double avg = mean(bf_measurements);
		bf_file << size << ',' << avg << endl;
		avg = mean(bb_measurements);
		bb_file << size << ',' << avg << endl;

	}

	bf_file.close();
	bb_file.close();
}

//
//// method wrappers with object reference
//double da_push_back(DynamicArray<int>& dt, int v_1, int v_2)
//{
//	auto start = Clock::now();
//	//START
//	dt.push_back(v_1);
//	//END
//	auto end = Clock::now();
//	dt.pop_back();
//	double duration = std::chrono::duration_cast<time_unit>(end - start).count();
//	return duration;
//}
//void da_operation_time(std::string op_name, int* N, std::function<double(DynamicArray<int>&, int, int)> method)
//{
//	using namespace std;
//	// initialize seed and generator
//	random_device seed;
//	mt19937 gen(seed());
//
//	// open file
//	ofstream file;
//	cout << "Testing DynamicArray::" << op_name << endl;
//	file.open("dynamic_array.csv", ios::out | ios::app);
//
//	// for all 3 value ranges, make measurements
//	for (int e = 0; e < 3; e++)
//	{
//		//value ranges, initialize rng
//		// 255, 65535, 2147483647
//		int R[3] = { 0xFF, 0xFFFF, 0x7FFFFFFF };
//		uniform_int_distribution<int> dist(-R[e], R[e]);
//		// update user on measurement progress
//		cout << "Range: " << R[e] << " (" << e + 1 << "/3)" << endl;
//
//		// output measurement info to file
//		file << "Dynamic Array: " << op_name << endl;
//		file << "Range: +- " << R[e] << endl;
//		file << "N,Mean,q(0.025),q(0.975),Min,Max" << endl;
//
//		// all operations are tested with the following number of arguments, SAMPLE_NUM times each
//		for (size_t j = 0; j < 10; j++)
//		{
//			// update user on measurement progress
//			cout << "Size: " << N[j] << " (" << j + 1 << "/10)" << endl;
//
//			// SAMPLE_NUM element array for storing duration measurements
//			double* data = new double[SAMPLE_NUM];
//			// create test array and fill it with values
//			DynamicArray<int> base = DynamicArray<int>();
//			fill(base, N[j], R[e]);
//			uniform_int_distribution<int> dist2(1, N[j] - 1);
//
//			// SAMPLE_NUM measurements, output to array
//			for (size_t i = 0; i < SAMPLE_NUM; i++)
//			{
//				int val = dist(gen);
//				int index = dist2(gen);
//				data[i] = method(base, val, index);
//			}
//
//			// create table columns, fill them with excel values laters
//			file << N[j] << ',' << mean(data) << ',' << quantile(data, 0.025) << \
//				',' << quantile(data, 0.975) << ',' << _min(data) << ',' << _max(data) << endl;
//			// print all results to file
//			all_to_file("dynamic_array_" + op_name + '_' + to_string(R[e]) + '_' + to_string(N[j]), data);
//			delete[] data;
//		}
//		file << endl << endl;
//	}
//
//	//update user on progress, close file
//	cout << "Finished DynamicArray::" << op_name << endl << \
//		"-----------------------------------------------------" << endl;
//	file.close();
//}


double mean(vector<double> data)
{
	double sum = 0.0;
	double avg = 0.0;
	for (double i : data)
	{
		sum += i;
	}
	avg = sum / data.size();
	return avg;
}

double sdev_p(vector<double> data)
{
	// accumulator
	double acc = 0.0;
	double m = mean(data);
	// add all durations
	for (int i : data)
	{
		acc += (i - m) * (i - m);
	}
	return sqrt(acc / data.size());
}

double sdev_u(vector<double> data)
{
	double sdev = sdev_p(data);
	int sample_num = data.size();
	double sdev_u = sdev * sample_num / (sample_num - 1);
	return sdev_u;
}

double serr(vector<double> data)
{
	double s = sdev_u(data);
	return s / sqrt(data.size());
}

double _min(vector<double> data)
{
	double buf = data[0];
	for (int i : data)
	{
		if (i < buf) buf = i;
	}
	return buf;
}

double _max(vector<double> data)
{
	double buf = data[0];
	for (int i : data)
	{
		if (data[i] > buf) buf = data[i];
	}
	return buf;
}

double quantile(vector<double> data, double p)
{
	vector<double> a(data);

	bubble_sort(a);
	int i = (SAMPLE_NUM - 1) * p;
	double ret = a[i];
	return ret;
}

void merge_sort(double * data, int l, int r)
{
	int m = l + (r - l) / 2;
	if (l < r)
	{
		merge_sort(data, l, m);
		merge_sort(data, m + 1, r);
		merge(data, l, m, r);
	}
}

void bubble_sort(vector<double> data)
{
	for (int i = 0; i < data.size() - 1; i++)
		// Last i elements are already in place   
		for (int j = 0; j < data.size()- i - 1; j++)
			if (data[j] > data[j + 1])
			{
				double temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
}

void merge(double* data, int l, int m, int r)
{

	int i, j, k;
	int n_1 = m - l + 1;
	int n_2 = r - m;

	/* create temp arrays */
	double* L = new double[n_1];
	double* R = new double[n_2];
	for (i = 0; i < n_1; i++)
	{
		L[i] = data[l + i];
	}
	for (j = 0; j < n_2; j++)
	{
		R[j] = data[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n_1 && j < n_2)
	{
		if (L[i] <= R[j])
		{
			data[k] = L[i];
			i++;
		}
		else
		{
			data[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n_1)
	{
		data[k] = L[i];
		i++;
		k++;
	}
	while (j < n_2)
	{
		data[k] = R[j];
		j++;
		k++;
	}
}
void all_to_file(std::string filename, vector<double> data)
{
	std::ofstream file;
	file.open(filename + ".csv", std::ios::out | std::ios::app);
	for (double i : data)
	{
		file << i << std::endl;
	}
	file.close();
}
