#include "UndirectedGraph.h"

UndirectedGraph::UndirectedGraph(const int amount_vertices)
	:Graph(amount_vertices)
{
}

void UndirectedGraph::set_weight_edges(const int vertice1, const int vertice2, const float weight_edge)
{
	Graph::set_weight_edges(vertice1, vertice2, weight_edge);
	Graph::set_weight_edges(vertice2, vertice1, weight_edge);
}


float UndirectedGraph::get_weight_edges(const int vertice1, const int vertice2) const
{
	return Graph::get_weight_edges(vertice1, vertice2);
}

