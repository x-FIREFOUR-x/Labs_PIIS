#include "FileWorkerGraph.h"

DirectedGraph FileWorkerGraph::read_directedgraph(string filename)
{
	ifstream file(filepath + filename);
	int amount_vertices;
	file >> amount_vertices;

	DirectedGraph graph(amount_vertices);

	string data_edge;
	bool is_end = false;

	while (!is_end)
	{
		file >> data_edge;
		int vertices1 = stoi(data_edge.substr(0, 1)) - 1;
		int vertices2 = stoi(data_edge.substr(1, 2)) - 1;
		int weight = stoi(data_edge.substr(3, data_edge.size()-1));
		graph.set_weight_edges(vertices1, vertices2, weight);

		if (data_edge[data_edge.size() - 1] == '.')
			is_end = true;
	}

	file.close();

	return graph;
}

UndirectedGraph FileWorkerGraph::read_undirectedgraph(string filename)
{
	ifstream file(filepath + filename);
	int amount_vertices;
	file >> amount_vertices;

	UndirectedGraph graph(amount_vertices);

	string data_edge;
	bool is_end = false;

	while (!is_end)
	{
		file >> data_edge;
		int vertices1 = stoi(data_edge.substr(0, 1)) - 1;
		int vertices2 = stoi(data_edge.substr(1, 2)) - 1;
		int weight = stoi(data_edge.substr(3, data_edge.size() - 1));

		if (!graph.is_edge(vertices1, vertices2))
		{
			graph.set_weight_edges(vertices1, vertices2, weight);
		}
		else
		{
			if (weight < graph.get_weight_edges(vertices1, vertices2))
			{
				graph.set_weight_edges(vertices1, vertices2, weight);
			}
		}

		if (data_edge[data_edge.size() - 1] == '.')
			is_end = true;
	}

	file.close();

	return graph;
}
