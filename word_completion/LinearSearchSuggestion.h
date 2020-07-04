#include "BaseSuggestion.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

class LinearSearchSuggestion :
    public BaseSuggestion
{
public:
    LinearSearchSuggestion();
    LinearSearchSuggestion(std::string path, ulong c);
    std::vector<std::string> getSuggestions(std::string input);

private:
    std::vector<std::string> dictionary;
};
