#include "BaseSuggestion.h"
#include <cstdio>
#include <chrono>
#include <unistd.h>
#include "LinearSearchSuggestion.h"
#include "BinarySearchSuggestion.h"
#include "TrieSuggestion.h"

void printUsage()
{
    std::cout << "This application helps to find list of words based on prefix." << std::endl << std::endl;
    std::cout << "\t-d,--dict\t\tRequired. Path to a file with dictionary with one word per line." << std::endl;
    std::cout << "\t-i,--input\t\tRequired. Beginning of the words to search for." << std::endl;
    std::cout << "\t-c,--count\t\tDefines how many words to seach for at max. Default value is 10." << std::endl;
    std::cout << "\t-l,--use_linear\t\tIf used the application will use linear search. Default value if no method chosen." << std::endl;
    std::cout << "\t-b,--use_binary\t\tIf used the application will use binary search. Takes precedence over linear." << std::endl;
    std::cout << "\t-t,--use_trie\t\tIf used the application will use Trie instead of linear search. Takes precedence over others." << std::endl;
}

void parseArgs(int argc, char** argv, std::string& pathToDict, std::string& input, ulong& count, bool& useLinear, bool& useBinary, bool& useTrie)
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
        if ((arg == "-l") || (arg == "--use_linear"))
        {
            useLinear = true;
            useBinary = false;
            useTrie = false;
        }
        if ((arg == "-b") || (arg == "--use_binary"))
        {
            useLinear = false;
            useBinary = true;
            useTrie = false;
        }
        if ((arg == "-t") || (arg == "--use_trie"))
        {
            useLinear = false;
            useBinary = false;
            useTrie = true;
        }
    }
}

int main(int argc, char** argv)
{
    std::string pathToDict;
    std::string input;
    ulong count = 10;
    bool useLinear = true;
    bool useBinary = false;
    bool useTrie = false;

    parseArgs(argc, argv, pathToDict, input, count, useLinear, useBinary, useTrie);

    if (pathToDict.size() == 0 || input.size() == 0)
    {
        std::cout << "Path to the dictionary (param '--dict') and input (param '--input') must be specified." << std::endl;
        printUsage();
        return 1;
    }

    LinearSearchSuggestion linearSearchEngine;
    BinarySearchSuggestion binarySearchEngine;
    TrieSuggestion trieEngine;

    BaseSuggestion* engine;

    if (useLinear)
    {
        linearSearchEngine = LinearSearchSuggestion(pathToDict, count);
        engine = &linearSearchEngine;
    }
    else if (useBinary)
    {
        binarySearchEngine = BinarySearchSuggestion(pathToDict, count);
        engine = &binarySearchEngine;
    }
    else
    {
        trieEngine = TrieSuggestion(pathToDict, count);
        engine = &trieEngine;
    }

    auto start = std::chrono::steady_clock::now();
    std::vector<std::string> suggestions = engine->getSuggestions(input);
    auto end = std::chrono::steady_clock::now();

    for (std::string word : suggestions)
    {
        std::cout << word << std::endl;
    }

    std::cout << "Elapsed time in nanoseconds : "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
        << " ns" << std::endl;
    
    return 0;
}