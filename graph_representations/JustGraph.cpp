#include "JustGraph.h"
#include <vector>
#include <iostream>

bool JustGraph::isEulerWalkable() {
    std::vector<ulong> degrees;

    std::stack<Node*> nextNodes;
    std::set<Node*> visited;
    nextNodes.push(root_);
    while (!nextNodes.empty()) {
        Node* nextNode = nextNodes.top();
        visited.insert(nextNode);
        nextNodes.pop();

        degrees.push_back(nextNode->adjacents.size());

        for (auto n : nextNode->adjacents) {
            if (visited.find(n) == visited.end()) {
                nextNodes.push(n);
                visited.insert(n);
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

void JustGraph::printGraphBfs(int startV) {
    Node* startNode;

    std::stack<Node*> nextNodes;
    std::set<Node*> visited;
    nextNodes.push(root_);
    while (!nextNodes.empty()) {
        Node* nextNode = nextNodes.top();
        visited.insert(nextNode);
        nextNodes.pop();

        if (nextNode->vertex_number == startV) {
            startNode = nextNode;
            break;
        }

        for (auto n : nextNode->adjacents) {
            if (visited.find(n) == visited.end()) {
                nextNodes.push(n);
                visited.insert(n);
            }
        }
    }

    printGraphBfs(startNode);

    std::cout << std::endl;
}

void JustGraph::printGraphBfs(Node* startNode) {
    std::queue<Node*> nextNodes;
    std::set<Node*> visited;
    nextNodes.push(startNode);
    while (!nextNodes.empty()) {
        Node* nextNode = nextNodes.front();
        visited.insert(nextNode);
        nextNodes.pop();

        std::cout << nextNode->vertex_number << ' ';

        for (auto const& n : nextNode->adjacents) {
            if (visited.find(n) == visited.end()) {
                nextNodes.push(n);
                visited.insert(n);
            }
        }
    }
}

void JustGraph::printGraphDfs(int startV) {
    Node* startNode;

    std::stack<Node*> nextNodes;
    std::set<Node*> visited;
    nextNodes.push(root_);
    while (!nextNodes.empty()) {
        Node* nextNode = nextNodes.top();
        visited.insert(nextNode);
        nextNodes.pop();

        if (nextNode->vertex_number == startV) {
            startNode = nextNode;
            break;
        }

        for (auto const& n : nextNode->adjacents) {
            if (visited.find(n) == visited.end()) {
                nextNodes.push(n);
                visited.insert(n);
            }
        }
    }

    printGraphDfs(startNode);

    std::cout << std::endl;
}

void JustGraph::printGraphDfs(Node* startNode) {
    std::stack<Node*> nextNodes;
    std::set<Node*> visited;
    nextNodes.push(startNode);
    while (!nextNodes.empty()) {
        Node* nextNode = nextNodes.top();
        visited.insert(nextNode);
        nextNodes.pop();

        std::cout << nextNode->vertex_number << ' ';

        for (auto const& n : nextNode->adjacents) {
            if (visited.find(n) == visited.end()) {
                nextNodes.push(n);
                visited.insert(n);
            }
        }
    }
}
