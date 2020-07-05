#include "BaseSuggestion.h"
#include <iostream>
#include <fstream>
#include <map>
#include <bits/stdc++.h>

struct trie
{
    bool isWord;
    std::map<char, trie> nodes;
};

class TrieSuggestion :
    public BaseSuggestion
{
public:
    TrieSuggestion();
    TrieSuggestion(std::string path, ulong c);
    virtual std::vector<std::string> getSuggestions(std::string input);

private:
    trie root;
    void findWords(trie* node, std::string curLine, std::vector<std::string>* result);
};
