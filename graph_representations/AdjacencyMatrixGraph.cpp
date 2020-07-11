#include "AdjacencyMatrixGraph.h"
#include <iostream>

bool AdjacencyMatrixGraph::isEulerWalkable() {
    std::vector<int> degrees(adjacency_.size());

    for (int i = 0; (ulong) i < adjacency_.size(); i++) {
        for (int j = 0; (ulong) j < adjacency_.size(); j++) {
            if (adjacency_[i][j] == 1) {
                degrees[i]++;
            }
        }
    }

    int countOdds = 0;

    for (auto d : degrees) {
        if (d % 2 == 1) {
            countOdds++;
        }
    }
    return (countOdds == 0 || countOdds == 2);
}

void AdjacencyMatrixGraph::printGraphBfs(int startV) {
    std::unordered_set<int> visited;
    visited.insert(startV);
    std::queue<int> next;
    next.push(startV);

    printGraphBfs(&visited, &next);

    std::cout << std::endl;
}

void AdjacencyMatrixGraph::printGraphBfs(std::unordered_set<int>* visited, std::queue<int>* next) {
    if (next->empty()) {
        return;
    }

    int nextV = next->front();
    next->pop();
    std::cout << nextV << ' ';

    for (int i = 0; (ulong) i < adjacency_.size(); i++) {
        if (adjacency_[i][nextV] != 0 || adjacency_[nextV][i] != 0) {
            if (visited->find(i) == visited->end()) {
                next->push(i);
                visited->insert(i);
            }
        }
    }
    printGraphBfs(visited, next);
}

void AdjacencyMatrixGraph::printGraphDfs(int startV) {
    std::unordered_set<int> visited;
    visited.insert(startV);
    std::stack<int> next;
    next.push(startV);

    printGraphDfs(&visited, &next);

    std::cout << std::endl;
}

void AdjacencyMatrixGraph::printGraphDfs(std::unordered_set<int>* visited, std::stack<int>* next) {
    if (next->empty()) {
        return;
    }

    int nextV = next->top();
    next->pop();
    std::cout << nextV << ' ';

    for (int i = 0; (ulong) i < adjacency_.size(); i++) {
        if (adjacency_[i][nextV] != 0 || adjacency_[nextV][i] != 0) {
            if (visited->find(i) == visited->end()) {
                next->push(i);
                visited->insert(i);
            }
        }
    }
    printGraphDfs(visited, next);
}
