#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>

class Tokenizer {
private:
    std::unordered_map<std::string, int> word_to_token;
    std::vector<std::string> token_to_word;
    int next_token;

public:
    Tokenizer();

    void readFromFile(const std::string& filename);
    void printTokens() const;
    int getToken(const std::string& word) const;
    std::string getWord(int token) const;
};

#endif
