#pragma once

#include <string>
#include <fstream>

#include "DirectedGraph.h"
#include "UndirectedGraph.h"

using namespace std;
class FileWorkerGraph
{
	string filepath = "FilesGraph//";
public:
	DirectedGraph read_directedgraph(string filename);
	UndirectedGraph read_undirectedgraph(string filename);
};

