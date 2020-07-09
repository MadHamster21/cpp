#pragma once
class Graph
{
public:
	virtual bool isEulerWalkable() = 0;
	virtual void printGraphBfs(int startV) = 0;
	virtual void printGraphDfs(int startV) = 0;
};
