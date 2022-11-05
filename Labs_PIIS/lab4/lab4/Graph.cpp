#include "Graph.h"

Graph::Graph(const int amount_vertices)
{
	for (int i = 0; i < amount_vertices; i++)
	{
		vector<float> edges_vertice;
		for (int j = 0; j < amount_vertices; j++)
		{
			edges_vertice.push_back(Edge::EdgeUnexist);
		}
		matrix.push_back(edges_vertice);
	}
}

void Graph::set_weight_edges(const int vertice1, const int vertice2, const float weight_edge)
{
	matrix[vertice1][vertice2] = weight_edge;
}

float Graph::get_weight_edges(const int vertice1, const int vertice2) const
{
	return matrix[vertice1][vertice2];
}

bool Graph::is_edge(const int vertice1, const int vertice2) const
{
	if (matrix[vertice1][vertice2] == Edge::EdgeUnexist)
		return false;
	else
		return true;
}

void Graph::print_graph() const
{
	cout << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << setw(3) << matrix[i][j] << " " ;
		}
		cout << endl;
	}
}

