#include "vector"
#include <iostream>
#include <iomanip>

#pragma once
using namespace std;
class Matrix
{
	vector<vector<float>> matrix;

public:
	Matrix() {};
	Matrix(vector<vector<float>> matrix);

	void print();
};

