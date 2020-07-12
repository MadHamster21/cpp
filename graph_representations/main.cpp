#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include "DirectTranslationGraph.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "JustGraph.h"

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


    std::cout << "JustGraph" << std::endl;
    JustGraph::Node node0_(0);
    JustGraph::Node* node0 = &node0_;
    JustGraph::Node node1_(1);
    JustGraph::Node* node1 = &node1_;
    JustGraph::Node node2_(2);
    JustGraph::Node* node2 = &node2_;
    JustGraph::Node node3_(3);
    JustGraph::Node* node3 = &node3_;
    JustGraph::Node node4_(4);
    JustGraph::Node* node4 = &node4_;
    std::set<JustGraph::Node*> set0 = { node1, node3 };
    node0->adjacents = set0;
    std::set<JustGraph::Node*> set1 = { node0, node2, node3 };
    node1->adjacents = set1;
    std::set<JustGraph::Node*> set2 = { node1, node3 };
    node2->adjacents = set2;
    std::set<JustGraph::Node*> set3 = { node0, node1, node2, node4 };
    node3->adjacents = set3;
    std::set<JustGraph::Node*> set4 = { node3 };
    node4->adjacents = set4;

    JustGraph jg(node0);

    jg.printGraphBfs(0);
    jg.printGraphDfs(0);

    std::cout << "Is Euler walkable: " << jg.isEulerWalkable() << std::endl;

    return 0;
}
