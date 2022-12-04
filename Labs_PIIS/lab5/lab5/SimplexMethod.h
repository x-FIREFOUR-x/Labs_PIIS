#pragma once
#include <vector>

using namespace std;
class SimplexMethod
{
	int amount_function;
	int amount_variables;

	vector<vector<float>> A;	//matrix coef
	vector<float> B;
	vector<float> C;
	
	float f;

public:
	SimplexMethod();

	vector<float> calculate_min();
	float get_value_function();

	void print();

private:
	bool is_optimal();
	int choose_pivot_column();									//choose a free variable that will do the basis
	int choose_pivot_row(int index_column);						//choose a basis variable that will do the free
	void swap_variables(int index_row, int index_column);		//swap chosen free and basis variable

	vector<float> get_basis();
};

