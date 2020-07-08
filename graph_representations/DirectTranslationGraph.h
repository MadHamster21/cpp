#pragma once
#include "Graph.h"
#include <vector>

class DirectTranslationGraph :
    public Graph
{
public:
    DirectTranslationGraph(std::vector<int>& v, std::vector<std::pair<int, int>>& e)
        : v_(v), e_(e) {}
    bool isEulerWalkable();
    void printGraph();

private:
    std::vector<int> v_;
    std::vector<std::pair<int, int>> e_;
};
