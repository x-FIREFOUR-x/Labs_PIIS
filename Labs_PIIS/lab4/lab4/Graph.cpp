#include "Graph.h"

Graph::Graph(int amount_vertices)
{
	for (int i = 0; i < amount_vertices; i++)
	{
		vector<float> edges_vertice;
		for (int j = 0; j < amount_vertices; j++)
		{
			edges_vertice.push_back(-1);
		}
		matrix.push_back(edges_vertice);
	}
}

void Graph::set_weight_edges(int vertice1, int vertice2, float weight_edge)
{
	matrix[vertice1][vertice2] = weight_edge;
}

float Graph::get_weight_edges(int vertice1, int vertice2)
{
	return matrix[vertice1][vertice2];
}

