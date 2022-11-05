#pragma once

#include <vector>
#include <iostream>
#include "UndirectedGraph.h"
#include "Edge.h"

using namespace std;
class Prima
{
	float weight_mst;
	vector<bool> included_vertices;
	UndirectedGraph min_spanning_tree;
	vector<Edge> included_edges;
	vector<Edge> edges;

public:
	float search_minimum_spanning_tree(const UndirectedGraph& graph);
	void print_result();

	UndirectedGraph get_minimum_spanning_tree() const;
	vector<Edge> get_included_edges();

private:
	void init_variables(const UndirectedGraph& graph);
};

