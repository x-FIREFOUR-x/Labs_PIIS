#include "Matrix.h"

Matrix::Matrix(vector<vector<float>> matrix)
{
	this->matrix = matrix;
}

vector<int> Matrix::get_free_variables(int amount_free_variables)
{
	vector<int> free_variables;

	priority_queue<pair<int, int>> index_variables;

	for (int i = 0; i < matrix[0].size(); i++)
	{
		int amount_not_zero = 0;
		for (int j = 0; j < matrix.size(); j++)
		{
			if (matrix[j][i] != 0)
				amount_not_zero++;
		}
		index_variables.push(pair<int, int>(amount_not_zero, i));
	}

	for (int i = 0; i < amount_free_variables; i++)
	{
		free_variables.push_back(index_variables.top().second);
		index_variables.pop();
	}
	return free_variables;
}

void Matrix::print()
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << setw(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
