#include "BaseSuggestion.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

class BinarySearchSuggestion :
    public BaseSuggestion
{
public:
    BinarySearchSuggestion();
    BinarySearchSuggestion(std::string path, ulong c);
    std::vector<std::string> getSuggestions(std::string input);
    ulong binarySearch(std::string input, ulong low, ulong mid, ulong high);

private:
    std::vector<std::string> dictionary;
};
