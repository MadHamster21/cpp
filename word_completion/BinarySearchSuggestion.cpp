#include "BinarySearchSuggestion.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

BinarySearchSuggestion::BinarySearchSuggestion() { }

BinarySearchSuggestion::BinarySearchSuggestion(std::string path, ulong c)
{
    pathToDict = path;

    std::ifstream in(pathToDict);

    if (!in)
    {
        std::cerr << "Cannot open the File : " << pathToDict << std::endl;
        return;
    }

    std::string str;
    while (std::getline(in, str))
    {
        if (str.size() > 0)
        {
            dictionary.push_back(str);
        }
    }
    in.close();

    count = c;
}

std::vector<std::string> BinarySearchSuggestion::getSuggestions(std::string input)
{
    std::vector<std::string> result;
    ulong low = 0;
    ulong high = dictionary.size() - 1;
    
    ulong pos = BinarySearchSuggestion::binarySearch(input, low, low + (high - low) / 2, high);
    if (pos < 0)
    {
        return result;
    }

    ulong upIdx = pos - 1;
    while (upIdx >= 0 && result.size() < count)
    {
        std::string word = dictionary[upIdx];
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word.rfind(input, 0) != 0)
        {
            break;
        }
        result.push_back(word);
        upIdx--;
    }

    while (pos < dictionary.size() && result.size() < count)
    {
        std::string word = dictionary[pos];
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word.rfind(input, 0) != 0)
        {
            break;
        }
        result.push_back(word);
        pos++;
    }
    
    return result;
}

ulong BinarySearchSuggestion::binarySearch(std::string input, ulong low, ulong mid, ulong high)
{
    if (low >= high)
    {
        return -1;
    }

    std::string word = dictionary[mid];
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    if (word.rfind(input, 0) == 0)
    {
        return mid;
    }
    else if (word > input)
    {
        return BinarySearchSuggestion::binarySearch(input, low, low + (mid - low) / 2, mid);
    }
    else
    {
        return BinarySearchSuggestion::binarySearch(input, mid, mid + (high - mid) / 2, high);
    }
}
