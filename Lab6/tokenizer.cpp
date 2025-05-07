#include "tokenizer.h"

Tokenizer::Tokenizer() : next_token(0) {}

void Tokenizer::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string word;

    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    while (file >> word) {
        if (word_to_token.find(word) == word_to_token.end()) {
            word_to_token[word] = next_token;
            token_to_word.push_back(word);
            next_token++;
        }
    }
    file.close();
}

void Tokenizer::printTokens() const {
    for (const auto& pair : word_to_token) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}

int Tokenizer::getToken(const std::string& word) const {
    auto it = word_to_token.find(word);
    if (it != word_to_token.end()) {
        return it->second;
    }
    return -1; // Invalid token
}

std::string Tokenizer::getWord(int token) const {
    if (token >= 0 && token < static_cast<int>(token_to_word.size())) {
        return token_to_word[token];
    }
    return ""; // Invalid word
}
