#include "SimplexMethod.h"

#include <iomanip>
#include <iostream>
#include <exception>

SimplexMethod::SimplexMethod()
{
}

SimplexMethod::SimplexMethod(vector<vector<float>> A, vector<float> B, vector<float> C)
{
	this->A = A;
	this->B = B;
	this->C = C;

	amount_function = B.size();
	amount_variables = C.size();
}

float SimplexMethod::get_value_function()
{
	return f;
}

vector<float> SimplexMethod::calculate_min()
{
	print_start();

	create_start_simplex_table();
	cout << "------Start Simplex table--------" << endl;
	print();

	cout << "----------Next steps------------" << endl;
	while (!is_optimal())
	{
		int index_column = choose_pivot_column();
		int index_row = choose_pivot_row(index_column);

		swap_variables(index_row, index_column);

		print();
	}

	return get_basis();
}

bool SimplexMethod::is_optimal()
{
	bool is_optimal = true;
	for (auto item: C)
	{
		if (item > 0)
		{
			is_optimal = false;
			break;
		}
			
	}
	return is_optimal;
}

int SimplexMethod::choose_pivot_column()
{
	int index = 0;
	int max_value = C[index];
	for (int i = 1; i < amount_variables; i++)
	{
		if (C[i] > max_value)
		{
			max_value = C[i];
			index = i;
		}
	}
	return index;
}

int SimplexMethod::choose_pivot_row(int index_column)
{
	int index = 0;
	float min_value = 100000;

	for (int i = 0; i < amount_function; i++)
	{
		if (A[i][index_column] > 0)
		{
			float value = B[i] / A[i][index_column];
			if (value < min_value)
			{
				min_value = value;
				index = i;
			}
		}
	}

	return index;
}

void SimplexMethod::swap_variables(int index_row, int index_column)
{
	float pivot_value = A[index_row][index_column];
	for (int i = 0; i < amount_variables; i++)
	{
		A[index_row][i] = A[index_row][i] / pivot_value;
	}
	B[index_row] = B[index_row] / pivot_value;

	f = f - (C[index_column] * B[index_row]);
	for (int i = 0; i < amount_variables; i++)
	{
		C[i] = C[i] - C[index_column] * A[index_row][i];
	}
	
		//повертаєм властивість одиничної матриці
	for (int i = 0; i < amount_function; i++)
	{
		if (i != index_row && A[i][index_column] != 0)
		{
			float coef = A[i][index_column];
			for (int j = 0; j < amount_variables; j++)
			{
				A[i][j] = A[i][j] - (coef * A[index_row][j]);
			}
			B[i] = B[i] - (coef * B[index_row]);
		}
	}
}

vector<float> SimplexMethod::get_basis()
{
	vector<float> basis;
	for (int i = 0; i < amount_variables; i++)
	{
		if (C[i] != 0)
		{
			basis.push_back(0);
		}
		else
		{
			for (int j = 0; j < amount_function; j++)
			{
				if (A[j][i] == 1)
				{
					basis.push_back(B[j]);
				}
			}
		}
	}
	return basis;
}



void SimplexMethod::print()
{
	int amount_symbol = 7;
	int after_point = 3;
	cout << "===================================================" << endl;
	for (int i = 0; i < amount_variables; i++)
	{
		cout << std::fixed << std::setprecision(after_point) << " " << setw(amount_symbol) << C[i];
	}
	cout << std::fixed << std::setprecision(after_point)  << "|" << setw(amount_symbol) << f << endl;

	cout << "---------------------------------------------------" << endl;
	for (int i = 0; i < amount_function; i++)
	{
		for (int j = 0; j < amount_variables; j++)
		{
			cout << std::fixed << std::setprecision(after_point) << " " << setw(amount_symbol) << A[i][j];
		}
		cout << std::fixed << std::setprecision(after_point) << "|" << setw(amount_symbol) << B[i] << endl;
	}
	cout << "===================================================" << endl << endl;
}

void SimplexMethod::print_start()
{
	cout << "============Input data==========" << endl;
	cout << "A:" << endl;
	for (auto line : A)
	{
		for (auto elem : line)
		{
			cout << setw(3) << elem << " ";
		}
		cout << endl;
	}

	cout << "B:" << endl;
	for (auto elem : B)
	{
		cout << setw(3) << elem << " ";
	}
	cout << endl;

	cout << "c:" << endl;
	for (auto elem : C)
	{
		cout << setw(3) << elem << " ";
	}
	cout << endl << endl;
}



void SimplexMethod::create_start_simplex_table()
{
	vector<vector<float>> table;
	for (int i = 0; i < amount_function; i++)
	{
		vector<float> line;
		for (int j = 0; j < amount_variables; j++)
		{
			line.push_back(A[i][j]);
		}
		line.push_back(B[i]);
		table.push_back(line);
	}
	vector<float> line;
	for (int i = 0; i < amount_variables; i++)
	{
		line.push_back(-C[i]);
	}
	line.push_back(f);
	table.push_back(line);

	for (int i = 0; i < amount_function; i++)
	{
		if (table[i][i] == 0)
		{
			int j = i;
			while (j < amount_variables + 1 && table[i][j] == 0)
				j += 1;
			if (j == amount_variables + 1)
				throw exception("Zero!");
			table = swap_rows(table, i, j);
		}

		float ratio = 1 / table[i][i];
		for (int k = 0; k < amount_variables + 1; k++)
			table[i][k] = ratio * table[i][k];

		for (int j = i + 1; j < amount_function + 1; j++)
		{
			ratio = table[j][i];
			for (int k = 0; k < amount_variables + 1; k++)
				table[j][k] = table[j][k] - ratio * table[i][k];
		}
	}

	for (int i = amount_function - 1; i > -1; i--)
	{
		for (int j = i - 1; j > -1; j--)
		{
			float ratio = table[j][i];
			for (int k = 0; k < amount_variables + 1; k++)
			{
				table[j][k] = table[j][k] - ratio * table[i][k];
			}

		}

	}


	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			A[i][j] = table[i][j];
		}
	}
	for (int i = 0; i < B.size(); i++)
	{
		B[i] = table[i][table[0].size() - 1];
	}
	for (int i = 0; i < C.size(); i++)
	{
		C[i] = table[table.size() - 1][i];
	}
	f = table[table.size() - 1][table[0].size() - 1];
}

vector<vector<float>> SimplexMethod::swap_rows(vector<vector<float>>& table, int index1, int index2)
{
	vector<float> buf = table[index1];
	table[index1] = table[index2];
	table[index2] = buf;

	return table;
}


