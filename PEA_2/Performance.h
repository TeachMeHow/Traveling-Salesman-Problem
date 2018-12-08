// This file contains declaration of functions that are used to measure 
// time it takes to execute given number of operations, depending on the type of data structure
// All performance measurements are made using my data structure implementations with
// varying sizes of arguments and number of elements
//
// int is the default type of argument, as specified in project instruction
//
// Author: Szymon Cichy 235093
// Date: March 2018
//

#pragma once
#include <functional>
#include <string>
#include <vector>
// Sample number can be changed depending on how good the machine is
// decrease if tests are taking too long
// increase for better confidence
#define SAMPLE_NUM 1000

// calling this starts time measurements
// add, remove, comment or uncomment functions inside the definition
// to change what's being measured
void measure_all();

void time_measurement();
// for each structure, pass operation name (will appear in output and file
// structure sizes for each population and run wrapped function that measures time
//
// op_name - name of the method/operation
// N - array of 10 sizes for a structure to be measured each time
// method - wrapped class method to measure
//void da_operation_time(std::string op_name, int* N, std::function<double(DynamicArray<int>&, int, int)> method);

// both parameters are enough to fully describe normal distribution
// average, m
double mean(std::vector<double> data);
// standard deviation of the population
double sdev_p(std::vector<double> data);
// corrected standard deviation
double sdev_u(std::vector<double> data);
// standard error
double serr(std::vector<double> data);
double _min(std::vector<double> data);
double _max(std::vector<double> data);
double quantile(std::vector<double> data, double p);

// SORTING ALGORITHMS

// use if low on memory
void bubble_sort(std::vector<double> data);
// use if doesn't throw exception
void merge(double*data, int l, int m, int r);
void merge_sort(double* data, int l, int r);

// outputs all samples in data to file
void all_to_file(std::string filename, double* data);
