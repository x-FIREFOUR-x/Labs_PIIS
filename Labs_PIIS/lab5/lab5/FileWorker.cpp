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

	vector<float> line_�;
	for (int i = 0; i < amount_variables; i++)
	{
		float element;
		file >> element;
		line_�.push_back(element);
	}
	vector<vector<float>> matrix_�;
	matrix_�.push_back(line_�);
	C = Matrix(matrix_�);

	file.close();
}


void FileWorker::read_matrix(string filename, vector<vector<float>>& A, vector<float>& B, vector<float>& C)
{
	ifstream file(filepath + filename);

	if (!file.is_open())
		throw exception("Unexist file");

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
	A = matrix_A;

	vector<float> line_B;
	for (int i = 0; i < amount_function; i++)
	{
		float element;
		file >> element;
		line_B.push_back(element);
	}
	B = line_B;

	vector<float> line_�;
	for (int i = 0; i < amount_variables; i++)
	{
		float element;
		file >> element;
		line_�.push_back(element);
	}
	C = line_�;

	file.close();
}