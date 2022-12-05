#pragma once

#include <string>
#include <fstream>
#include <vector>

using namespace std;
class FileWorker
{
	string filepath = "Files//";
public:
	void read_matrix(string filename, vector<vector<float>>& A, vector<float>& B, vector<float>& C);
};

