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
	SimplexMethod(vector<vector<float>> A, vector<float> B, vector<float> C);

	vector<float> calculate_min();
	float get_value_function();

private:
	bool is_optimal();
	int choose_pivot_column();									//choose a free variable that will do the basis
	int choose_pivot_row(int index_column);						//choose a basis variable that will do the free
	void swap_variables(int index_row, int index_column);		//swap chosen free and basis variable

	vector<float> get_basis();

	void create_start_simplex_table();
	vector<vector<float>> swap_rows(vector<vector<float>>& table, int index1, int index2);

	void print();
	void print_start();
};

