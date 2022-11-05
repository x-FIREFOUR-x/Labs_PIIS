#pragma once

#include <vector>
#include <iostream>
#include "DirectedGraph.h"

using namespace std;
class Dijkstra
{
	float UNEXIST_PATH = 100000;
	int start;

	vector<bool> used_vertices;
	vector<float> paths;

public:
	void search_paths(const DirectedGraph& graph, int start_vertices);

private:
	void init_variables(const DirectedGraph& graph);
};

