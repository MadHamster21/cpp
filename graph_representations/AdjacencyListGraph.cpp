#include "AdjacencyListGraph.h"
#include <iostream>

bool AdjacencyListGraph::isEulerWalkable() {
    std::vector<ulong> degrees(v_.size());

    for (auto v : v_) {
        degrees[v.vertex_number] = v.adjacents.size();
    }

    int countOdds = 0;
    for (auto d : degrees) {
        if (d % 2 == 1) {
            countOdds++;
        }
    }

    return (countOdds == 0 || countOdds == 2);
}

void AdjacencyListGraph::printGraphBfs(int startV) {
    std::unordered_set<int> visited;
    visited.insert(startV);
    std::queue<int> next;
    next.push(startV);

    printGraphBfs(&visited, &next);

    std::cout << std::endl;
}

void AdjacencyListGraph::printGraphBfs(std::unordered_set<int>* visited, std::queue<int>* next) {
    if (next->empty()) {
        return;
    }

    int nextV = next->front();
    next->pop();
    std::cout << nextV << ' ';

    for (auto const& v : v_) {
        if (v.vertex_number == nextV) {
            for (auto const& child : v.adjacents) {
                if (visited->find(child) == visited->end()) {
                    next->push(child);
                    visited->insert(child);
                }
            }
            break;
        }
    }
    printGraphBfs(visited, next);
}

void AdjacencyListGraph::printGraphDfs(int startV) {
    std::unordered_set<int> visited;
    visited.insert(startV);
    std::stack<int> next;
    next.push(startV);

    printGraphDfs(&visited, &next);

    std::cout << std::endl;
}

void AdjacencyListGraph::printGraphDfs(std::unordered_set<int>* visited, std::stack<int>* next) {
    if (next->empty()) {
        return;
    }

    int nextV = next->top();
    next->pop();
    std::cout << nextV << ' ';

    for (auto const& v : v_) {
        if (v.vertex_number == nextV) {
            for (auto const& child : v.adjacents) {
                if (visited->find(child) == visited->end()) {
                    next->push(child);
                    visited->insert(child);
                }
            }
            break;
        }
    }
    printGraphDfs(visited, next);
}
