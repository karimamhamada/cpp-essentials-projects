#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tokenizer.h"
#include <fstream>

TEST_CASE("Basic Tokenizer Functionality") {

    std::ofstream out("test_input.txt");
    out << "wassup uconn wassup stamford";
    out.close();

    Tokenizer tokenizer;
    tokenizer.readFromFile("test_input.txt");

    CHECK(tokenizer.getToken("wassup") != -1);
    CHECK(tokenizer.getToken("uconn") != -1);
    CHECK(tokenizer.getToken("stamford") != -1);
    CHECK(tokenizer.getToken("missing") == -1);

    int token = tokenizer.getToken("uconn");
    CHECK(tokenizer.getWord(token) == "uconn");
}
