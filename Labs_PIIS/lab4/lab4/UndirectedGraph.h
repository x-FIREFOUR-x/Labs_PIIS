#pragma once

#include "Graph.h"

using namespace std;
class UndirectedGraph : public Graph
{
public:
	UndirectedGraph(int amount_vertices);

	void set_weight_edges(int vertice1, int vertice2, float weight_edge);
	float get_weight_edges(int vertice1, int vertice2);
};

