#pragma once

#include <vector>

using namespace std;
class SimplexMethod
{
	vector<vector<float>> A;
	vector<float> B;
	vector<float> C;

public:
	SimplexMethod(vector<vector<float>>& A, vector<float> B, vector<float> C);
};

