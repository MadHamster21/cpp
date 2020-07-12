#pragma once
#include "Graph.h"
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

class AdjacencyMatrixGraph :
    public Graph
{
public:
    AdjacencyMatrixGraph(std::vector<std::vector<int>> adjacency) : adjacency_(adjacency) {}
    bool isEulerWalkable();
    void printGraphBfs(int startV);
    void printGraphDfs(int startV);

private:
    std::vector<std::vector<int>> adjacency_;

    void printGraphBfs(std::unordered_set<int>*, std::queue<int>*);
    void printGraphDfs(std::unordered_set<int>* visited, std::stack<int>* next);
};
