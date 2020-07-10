#pragma once
#include "Graph.h"
#include <set>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

class AdjacencyListGraph :
    public Graph
{
public:
    struct Vertex {
        Vertex(int v, std::set<int> a) : vertex_number(v), adjacents(a) {}
        int vertex_number;
        std::set<int> adjacents;
    };

    AdjacencyListGraph(std::vector<Vertex> v) : v_(v) {}
    bool isEulerWalkable();
    void printGraphBfs(int startV);
    void printGraphDfs(int startV);

private:
    std::vector<Vertex> v_;

    void printGraphBfs(std::unordered_set<int>*, std::queue<int>*);
    void printGraphDfs(std::unordered_set<int>* visited, std::stack<int>* next);
};

