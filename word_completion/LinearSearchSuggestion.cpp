#include "LinearSearchSuggestion.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

LinearSearchSuggestion::LinearSearchSuggestion() { }

LinearSearchSuggestion::LinearSearchSuggestion(std::string path, ulong c)
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

std::vector<std::string> LinearSearchSuggestion::getSuggestions(std::string input)
{
    std::vector<std::string> result;
    for (std::string word : dictionary)
    {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word.rfind(input, 0) == 0)
        {
            result.push_back(word);
            if (result.size() >= count)
            {
                return result;
            }
        }
    }

    return result;
}
