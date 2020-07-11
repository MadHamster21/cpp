#include <cstdio>
#include <vector>
#include <iostream>
#include "DirectTranslationGraph.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"

int main()
{
    std::cout << "DirectTranslationGraph" << std::endl;
    std::vector<int> v = { 0, 1, 2, 3 };
    std::vector<std::pair<int, int>> e = { {1, 3}, {3, 0}, {0, 2}, {2, 1}, {2, 3} };
    DirectTranslationGraph dtg(v, e);

    dtg.printGraphBfs(0);
    dtg.printGraphDfs(0);
    
    std::cout << "Is Euler walkable: " << dtg.isEulerWalkable() << std::endl;


    std::cout << "AdjacencyListGraph" << std::endl;
    AdjacencyListGraph alg({
        AdjacencyListGraph::Vertex(0, {1, 2}),
        AdjacencyListGraph::Vertex(1, {0, 2, 3, 4}),
        AdjacencyListGraph::Vertex(2, {0, 1, 3}),
        AdjacencyListGraph::Vertex(3, {1, 2, 4}),
        AdjacencyListGraph::Vertex(4, {1, 3}) });

    alg.printGraphBfs(0);
    alg.printGraphDfs(0);

    std::cout << "Is Euler walkable: " << alg.isEulerWalkable() << std::endl;


    std::cout << "AdjacencyMatrixGraph" << std::endl;
    AdjacencyMatrixGraph amg({{0, 1, 1, 0, 0},
                              {1, 0, 1, 1, 1},
                              {1, 1, 0, 1, 0},
                              {0, 1, 1, 0, 1},
                              {0, 1, 0, 1, 0}});

    amg.printGraphBfs(0);
    amg.printGraphDfs(0);

    std::cout << "Is Euler walkable: " << amg.isEulerWalkable() << std::endl;

    return 0;
}
