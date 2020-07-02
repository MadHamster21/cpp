#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

std::vector<std::string> getSuggestions(std::vector<std::string> dictionary, std::string input, ulong count)
{
    std::vector<std::string> result;
    for (std::string word : dictionary)
    {
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

int main()
{
    std::vector<std::string> dict;
    std::ifstream in("dictionary.txt");
    
    if (!in)
    {
        std::cout << "Cannot open the File : dictionary.txt" << std::endl;
        return 0;
    }

    std::string str;
    while (std::getline(in, str))
    {
        if (str.size() > 0)
        {
            dict.push_back(str);
        }
    }
    in.close();

    std::vector<std::string> suggestions = getSuggestions(dict, "pol", 10);
    for (std::string word : suggestions)
    {
        std::cout << word << std::endl;
    }
    
    return 0;
}