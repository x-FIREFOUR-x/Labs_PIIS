#include "FileWorker.h"

void FileWorker::read_matrix(string filename, Matrix& A, Matrix& B, Matrix& C)
{
	ifstream file(filepath + filename);
	int amount_function;
	file >> amount_function;
	int amount_variables;
	file >> amount_variables;

	vector<vector<float>> matrix_A;
	for (int i = 0; i < amount_function; i++)
	{
		vector<float> line;
		for (int i = 0; i < amount_variables; i++)
		{
			float element;
			file >> element;
			line.push_back(element);
		}
		matrix_A.push_back(line);
	}
	A = Matrix(matrix_A);

	vector<float> line_B;
	for (int i = 0; i < amount_function; i++)
	{
		float element;
		file >> element;
		line_B.push_back(element);
	}
	vector<vector<float>> matrix_B; 
	matrix_B.push_back(line_B);
	B = Matrix(matrix_B);

	vector<float> line_Ñ;
	for (int i = 0; i < amount_variables; i++)
	{
		float element;
		file >> element;
		line_Ñ.push_back(element);
	}
	vector<vector<float>> matrix_Ñ;
	matrix_Ñ.push_back(line_Ñ);
	C = Matrix(matrix_Ñ);

	file.close();
}
