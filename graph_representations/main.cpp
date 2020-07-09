#include <cstdio>
#include <vector>
#include <iostream>
#include "DirectTranslationGraph.h"

int main()
{
    std::vector<int> v = { 0, 1, 2, 3 };
    std::vector<std::pair<int, int>> e = { {1, 3}, {3, 0}, {0, 2}, {2, 1}, {2, 3} };
    DirectTranslationGraph g(v, e);

    g.printGraphBfs(0);
    g.printGraphDfs(0);
    
    std::cout << "Is Euler walkable: " << g.isEulerWalkable() << std::endl;
    return 0;
}
