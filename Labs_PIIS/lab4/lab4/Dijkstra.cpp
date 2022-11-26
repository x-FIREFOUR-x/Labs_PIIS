#include "Dijkstra.h"

void Dijkstra::search_paths(const DirectedGraph& graph, int start_vertices)
{
	start = start_vertices;

	init_variables(graph);
	int amount_used_vertices = 0;

	int select_vertices = start;
	paths[start] = 0;
	
	while (amount_used_vertices != graph.amount_vertices())
	{
			// вибір найближчої не поміченої вершини 
		int min_path = UNEXIST_PATH;
		for (int i = 0; i < graph.amount_vertices(); i++)
		{
			if (used_vertices[i] == false && paths[i] < min_path)
			{
				min_path = paths[i];
				select_vertices = i;
			}
		}
		
			//Перераховуєм шляхи до вершин
		for (int i = 0; i < graph.amount_vertices(); i++)
		{
			if (graph.is_edge(select_vertices, i) &&
				(paths[i] > paths[select_vertices] + graph.get_weight_edges(select_vertices, i)))
			{
				paths[i] = paths[select_vertices] + graph.get_weight_edges(select_vertices, i);
			}
		}
		used_vertices[select_vertices] = true;
		amount_used_vertices++;
	}

	cout << endl;
	for (int i = 0; i < paths.size(); i++)
	{
		
		cout << "from " << start + 1 << " to " << i + 1 << " = ";
		if (paths[i] != UNEXIST_PATH)
			cout << paths[i] << endl;
		else
			cout << "unexist path" << endl;
	}

}

void Dijkstra::init_variables(const DirectedGraph& graph)
{
	paths.resize(graph.amount_vertices(), UNEXIST_PATH);
	used_vertices.resize(graph.amount_vertices(), false);
}
