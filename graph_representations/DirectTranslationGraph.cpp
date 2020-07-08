#include "DirectTranslationGraph.h"
#include <cstdio>
#include <iostream>

bool DirectTranslationGraph::isEulerWalkable() {
    std::vector<int> degrees(v_.size());

    for (auto e : e_) {
        degrees[e.first]++;
        degrees[e.second]++;
    }
    int countOdds = 0;

    for (auto d : degrees) {
        if (d % 2 == 1) {
            countOdds++;
        }
    }
    return (countOdds == 0 || countOdds == 2);
}

void DirectTranslationGraph::printGraph() {
    std::cout << "Vertices: ";
    for (auto const& v : v_) {
        std::cout << v << " ";
    }
    std::cout<< std::endl << "Edges: ";
    for (auto const& e : e_) {
        std::cout << "{" << e.first << "," << e.second << "} ";
    }
    std::cout << std::endl;
}
