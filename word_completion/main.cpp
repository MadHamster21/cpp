#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include<bits/stdc++.h>

void printUsage()
{
    std::cout << "This application helps to find list of words based on prefix." << std::endl << std::endl;
    std::cout << "\t-d,--dict\t\tRequired. Path to a file with dictionary with one word per line." << std::endl;
    std::cout << "\t-i,--input\t\tRequired. Beginning of the words to search for." << std::endl;
    std::cout << "\t-c,--count\t\tDefines how many words to seach for at max. Default value is 10." << std::endl;
    std::cout << "\t-t,--use_trie\t\tIf used the application will use Trie instead of linear search." << std::endl;
}

void parseArgs(int argc, char** argv, std::string& pathToDict, std::string& input, ulong& count, bool& useTrie)
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if ((arg == "-d") || (arg == "--dict"))
        {
            if (i + 1 < argc) {
                pathToDict = argv[++i];
            }
            else {
                std::cerr << "--dict option requires the value." << std::endl;
            }
        }
        if ((arg == "-i") || (arg == "--input"))
        {
            if (i + 1 < argc) {
                input = argv[++i];
                std::transform(input.begin(), input.end(), input.begin(), ::tolower);
            }
            else {
                std::cerr << "--input option requires the value." << std::endl;
            }
        }
        if ((arg == "-c") || (arg == "--count"))
        {
            if (i + 1 < argc) {
                count = std::stoul(argv[++i]);
            }
            else {
                std::cerr << "--count option requires integer value." << std::endl;
            }
        }
        if ((arg == "-t") || (arg == "--use_trie"))
        {
            useTrie = true;
        }
    }
}

std::vector<std::string> getSuggestions(std::vector<std::string> dictionary, std::string input, ulong count)
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

int main(int argc, char** argv)
{
    std::string pathToDict;
    std::string input;
    ulong count;
    bool useTrie = false;

    parseArgs(argc, argv, pathToDict, input, count, useTrie);

    if (pathToDict.size() == 0 || input.size() == 0)
    {
        std::cout << "Path to the dictionary (param '--dict') and input (param '--input') must be specified." << std::endl;
        printUsage();
        return 1;
    }

    std::vector<std::string> dict;
    std::ifstream in(pathToDict);
    
    if (!in)
    {
        std::cout << "Cannot open the File : " << pathToDict << std::endl;
        return 1;
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

    std::vector<std::string> suggestions = getSuggestions(dict, input, 10);
    for (std::string word : suggestions)
    {
        std::cout << word << std::endl;
    }
    
    return 0;
}