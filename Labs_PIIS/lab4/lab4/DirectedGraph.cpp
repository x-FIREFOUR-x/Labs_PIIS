#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(const int amount_vertices)
	:Graph(amount_vertices)
{
}

void DirectedGraph::set_weight_edges(const int vertice1, const int vertice2, const float weight_edge)
{
	Graph::set_weight_edges(vertice1, vertice2, weight_edge);
}

float DirectedGraph::get_weight_edges(const int vertice1, const int vertice2) const
{
	return Graph::get_weight_edges(vertice1, vertice2);
}
