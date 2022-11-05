// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "FileWorkerGraph.h"
#include "Prima.h"
#include "Dijkstra.h"
#include "KarpRabin.h"

int main()
{
    FileWorkerGraph f;

    DirectedGraph g1 = f.read_directedgraph("fileDir.txt");
    g1.print_graph();

    UndirectedGraph g2 = f.read_undirectedgraph("fileUndir.txt");
    g2.print_graph();

    //Prima algo;
    //algo.search_minimum_spanning_tree(g2);
    //algo.print_result();

    //Dijkstra dijkstra;
    //dijkstra.search_paths(g1, 1);

    KarpRabin karp_rabin;
    //int pos = karp_rabin.position_substr("KPI FIOT 121 IPI IP-0j", "IP1"); //13
    int pos = karp_rabin.position_substr("0123456789", "2344"); //13
    cout << pos << endl;
    
}
