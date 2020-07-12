#pragma once
#include "Graph.h"
#include <queue>
#include <stack>
#include <set>

class JustGraph :
    public Graph
{
public:
    struct Node {
        Node() {}
        Node(int v) : vertex_number(v) {}
        Node(int v, std::set<Node*> a) : vertex_number(v), adjacents(a) {}
        int vertex_number;
        std::set<Node*> adjacents;

        bool operator < (const Node& other) const { return vertex_number < other.vertex_number; }
    };

    JustGraph(Node* root) : root_(root) {}
    bool isEulerWalkable();
    void printGraphBfs(int startV);
    void printGraphDfs(int startV);

private:
    Node* root_;

    void printGraphBfs(Node* startNode);
    void printGraphDfs(Node* startNode);
};

