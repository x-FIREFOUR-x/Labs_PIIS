#include "Matrix.h"

Matrix::Matrix(vector<vector<float>> matrix)
{
	this->matrix = matrix;
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
