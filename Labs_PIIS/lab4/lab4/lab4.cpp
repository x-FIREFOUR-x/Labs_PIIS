#include <iostream>

#include "FileWorkerGraph.h"
#include "Prima.h"
#include "Dijkstra.h"
#include "KarpRabin.h"

int main()
{
    bool is_run = true;
    while (is_run)
    {
        int chosen_algo;
        cout << "Choose algorithm (1-Karp-Rabin, 2-Dijkstra, 3-Prima, other-exit): ";
        cin >> chosen_algo;

        string namefile;
        FileWorkerGraph fileWorker;

        DirectedGraph dirGraph;
        UndirectedGraph undirGraph;

        KarpRabin karp_rabin;
        Dijkstra dijkstra;
        Prima prima;

        int start;

        string str;
        string substr;
        int pos;

        switch (chosen_algo)
        {
        case 1:
            cout << "Input string: ";
            cin >> str;
            cout << "Input substr: ";
            cin >> substr;
            pos = karp_rabin.position_substr(str, substr);
            cout << pos << endl;
            break;

        case 2:
            cout << "Input namefile with graph: ";
            cin >> namefile;
            dirGraph = fileWorker.read_directedgraph(namefile);
            dirGraph.print_graph();
            cout << "Input start: ";
            cin >> start;
            dijkstra.search_paths(dirGraph, start - 1);
            break;
            
        case 3:
            cout << "Input namefile with graph: ";
            cin >> namefile;
            undirGraph = fileWorker.read_undirectedgraph(namefile);
            undirGraph.print_graph();
            prima.search_minimum_spanning_tree(undirGraph);
            prima.print_result();
            break;

        default:
            is_run = false;
            break;
        }
    }
}
