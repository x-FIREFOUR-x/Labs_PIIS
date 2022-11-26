#include "Prima.h"

#include <algorithm>

float Prima::search_minimum_spanning_tree(const UndirectedGraph& graph)
{
	init_variables(graph);
	int amount_vertices_in_mst = 0;

	included_vertices[0] = true;
	amount_vertices_in_mst++;

	while (amount_vertices_in_mst != graph.amount_vertices())
	{
		
		for (int i = 0; i < edges.size(); i++)
		{
			int vertices1 = edges[i].vertices1;
			int vertices2 = edges[i].vertices2;
			if ((included_vertices[vertices1] == false || included_vertices[vertices2] == false) && !(included_vertices[vertices1] == false && included_vertices[vertices2] == false))
			{
				included_vertices[vertices1] = true;
				included_vertices[vertices2] = true;
				amount_vertices_in_mst++;

				weight_mst += edges[i].weight;
				min_spanning_tree.set_weight_edges(vertices1, vertices2, edges[i].weight);
				included_edges.push_back(edges[i]);
				
				break;
			}
		}
	}

	return weight_mst;
}

void Prima::print_result()
{
	cout << endl << "Weight minimum spanning tree: " << weight_mst << endl;

	for (int i = 0; i < included_edges.size(); i++)
	{
		if (i != included_edges.size()-1)
			cout << included_edges[i].vertices1 + 1 << "-" << included_edges[i].vertices2 + 1 << ", ";
		else
			cout << included_edges[i].vertices1 + 1 << "-" << included_edges[i].vertices2 + 1 << endl;
	}
}

UndirectedGraph Prima::get_minimum_spanning_tree() const
{
	return min_spanning_tree;
}

vector<Edge> Prima::get_included_edges()
{
	return included_edges;
}


void Prima::init_variables(const UndirectedGraph& graph)
{
	weight_mst = 0;
	included_vertices.resize(graph.amount_vertices(), false);
	min_spanning_tree = UndirectedGraph(graph.amount_vertices());

	for (int i = 0; i < graph.amount_vertices(); i++)
	{
		for (int j = i + 1; j < graph.amount_vertices(); j++)
		{
			if (graph.is_edge(i, j))
			{
				Edge edge(i, j, graph.get_weight_edges(i, j));
				edges.push_back(edge);
			}
		}
	}

	sort(edges.begin(), edges.end(), [](Edge edge1, Edge edge2) { return edge1.weight < edge2.weight; });
}
