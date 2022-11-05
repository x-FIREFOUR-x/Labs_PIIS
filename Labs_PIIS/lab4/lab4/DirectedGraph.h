#pragma once

#include "Graph.h"

using namespace std;
class DirectedGraph : public Graph
{
public:
	DirectedGraph(const int amount_vertices);

	void set_weight_edges(const int vertice1, const int vertice2, const float weight_edge);
	float get_weight_edges(const int vertice1, const int vertice2) const;
};

