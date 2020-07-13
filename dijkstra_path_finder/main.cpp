#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <bits/stdc++.h>

int main()
{
    ulong source = 0;
    ulong dest = 8;

    std::vector<std::vector<ulong>> graph =
                      { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    std::vector<ulong> dist(graph.size());
    std::vector<ulong> prev(graph.size());
    std::vector<ulong> q;

    for (ulong i = 0; i < graph.size(); i++) {
        dist[i] = ULONG_MAX;
        prev[i] = -1;
        q.push_back(i);
    }
    dist[source] = 0;

    while (!q.empty()) {
        ulong min = ULONG_MAX;
        ulong idx;
        for (ulong i = 0; i < q.size(); i++) {
            if (dist[q[i]] < min) {
                min = dist[q[i]];
                idx = i;
            }
        }
        ulong u = q[idx];
        if (u == dest) {
            break;
        }
        q.erase(q.begin() + idx);

        for (ulong v = 0; v < graph.size(); v++) {
            if (graph[u][v] > 0) {
                ulong alt = dist[u] + graph[u][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                }
            }
        }
    }

    std::cout << "Shortest path between " << source << " and " << dest << " is " << dist[dest] << std::endl;
    std::stack<ulong> path;
    ulong u = dest;
    if (prev[u] != -1 || u == source) {
        while (u > 0) {
            u = prev[u];
            path.push(u);
        }
    }
    std::cout << "Path taken: ";
    while (!path.empty()) {
        std::cout << path.top() << "->";
        path.pop();
    }
    std::cout << dest << std::endl;
    return 0;
}