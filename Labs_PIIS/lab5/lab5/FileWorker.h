#pragma once

#include <string>
#include <fstream>

#include "Matrix.h"

using namespace std;
class FileWorker
{
	string filepath = "Files//";
public:
	void read_matrix(string filename, Matrix& A, Matrix& B, Matrix& C);
};

