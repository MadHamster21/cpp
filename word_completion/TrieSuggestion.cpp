#include "TrieSuggestion.h"
#include <iostream>
#include <fstream>
#include <map>
#include <bits/stdc++.h>

TrieSuggestion::TrieSuggestion() { }

TrieSuggestion::TrieSuggestion(std::string path, ulong c)
{
    pathToDict = path;

    std::ifstream in(pathToDict);

    if (!in)
    {
        std::cerr << "Cannot open the File : " << pathToDict << std::endl;
        return;
    }

    trie rootNode;

    std::string str;
    while (std::getline(in, str))
    {
        trie* curNode = &rootNode;
        for (char const& ch : str) {
            trie tmpNode;
            auto node = curNode->nodes.find(ch);
            if (node != curNode->nodes.end()) {
                tmpNode = node->second;
            }
            else {
                tmpNode = trie();
                curNode->nodes.insert({ch, tmpNode});
            }
            curNode = &tmpNode;
        }
        curNode->isWord = true;
    }
    in.close();

    root = rootNode;

    count = c;
}

std::vector<std::string> TrieSuggestion::getSuggestions(std::string input)
{
    std::vector<std::string> result;
    trie* inputNode = &root;
    for (char const& ch : input) {
        trie tmpNode;
        auto node = inputNode->nodes.find(ch);
        if (node != inputNode->nodes.end()) {
            inputNode = &node->second;
        }
        else {
            return result;
        }
    }

    return result;
}
