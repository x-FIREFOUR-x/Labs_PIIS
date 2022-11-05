#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
class Graph
{
	vector<vector<float>> matrix;

protected:

	enum Edge {
		EdgeUnexist = -1
	};

	Graph(int amount_vertices);

	void set_weight_edges(const int vertice1, const int vertice2, const float weight_edge);
	float get_weight_edges(const int vertice1, const int vertice2) const;

public:
	bool is_edge(const int vertice1, const int vertice2) const;

	void print_graph() const;
};

