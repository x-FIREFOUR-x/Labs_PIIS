#pragma once
#include <vector>

using namespace std;
class Graph
{
	vector<vector<float>> matrix;

protected:
	Graph(int amount_vertices);

	void set_weight_edges(int vertice1, int vertice2, float weight_edge);
	float get_weight_edges(int vertice1, int vertice2);

};

