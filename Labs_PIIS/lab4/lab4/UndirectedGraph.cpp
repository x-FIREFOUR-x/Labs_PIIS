#include "UndirectedGraph.h"

UndirectedGraph::UndirectedGraph(int amount_vertices)
	:Graph(amount_vertices)
{
}

void UndirectedGraph::set_weight_edges(int vertice1, int vertice2, float weight_edge)
{
	Graph::set_weight_edges(vertice1, vertice2, weight_edge);
	Graph::set_weight_edges(vertice2, vertice1, weight_edge);
}

float UndirectedGraph::get_weight_edges(int vertice1, int vertice2)
{
	return Graph::get_weight_edges(vertice1, vertice2);
}
