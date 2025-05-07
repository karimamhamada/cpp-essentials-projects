#include "tokenizer.h"

int main() {
    Tokenizer tokenizer;
    tokenizer.readFromFile("input.txt");
    tokenizer.printTokens();
    return 0;
}
