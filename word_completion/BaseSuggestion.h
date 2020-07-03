#pragma once
#include <string>
#include <vector>
class BaseSuggestion
{
public:
	virtual std::vector<std::string> getSuggestions(std::string input) = 0;

protected:
	std::string pathToDict;
	ulong count = 10;
};
