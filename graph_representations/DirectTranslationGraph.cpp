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

void DirectTranslationGraph::printGraphBfs(int startV) {
    std::unordered_set<int> visited;
    visited.insert(startV);
    std::queue<int> next;
    next.push(startV);

    printGraphBfs(&visited, &next);

    std::cout << std::endl;
}

void DirectTranslationGraph::printGraphBfs(std::unordered_set<int>* visited, std::queue<int>* next) {
    if (next->empty()) {
        return;
    }

    int nextV = next->front();
    next->pop();
    std::cout << nextV << ' ';
    
    for (auto const& e : e_) {
        if (e.first == nextV && visited->find(e.second) == visited->end()) {
            next->push(e.second);
            visited->insert(e.second);
        }
        else if (e.second == nextV && visited->find(e.first) == visited->end()) {
            next->push(e.first);
            visited->insert(e.first);
        }
    }
    printGraphBfs(visited, next);
}

void DirectTranslationGraph::printGraphDfs(int startV) {
    std::unordered_set<int> visited;
    visited.insert(startV);
    std::stack<int> next;
    next.push(startV);

    printGraphDfs(&visited, &next);

    std::cout << std::endl;
}

void DirectTranslationGraph::printGraphDfs(std::unordered_set<int>* visited, std::stack<int>* next) {
    if (next->empty()) {
        return;
    }

    int nextV = next->top();
    next->pop();
    std::cout << nextV << ' ';

    for (auto const& e : e_) {
        if (e.first == nextV && visited->find(e.second) == visited->end()) {
            next->push(e.second);
            visited->insert(e.second);
        }
        else if (e.second == nextV && visited->find(e.first) == visited->end()) {
            next->push(e.first);
            visited->insert(e.first);
        }
    }
    printGraphDfs(visited, next);
}
