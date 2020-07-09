#pragma once
#include "Graph.h"
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

class DirectTranslationGraph :
    public Graph
{
public:
    DirectTranslationGraph(std::vector<int>& v, std::vector<std::pair<int, int>>& e)
        : v_(v), e_(e) {}
    bool isEulerWalkable();
    void printGraphBfs(int startV);
    void printGraphDfs(int startV);

private:
    std::vector<int> v_;
    std::vector<std::pair<int, int>> e_;

    void printGraphBfs(std::unordered_set<int>* visited, std::queue<int>* next);
    void printGraphDfs(std::unordered_set<int>* visited, std::stack<int>* next);
};
