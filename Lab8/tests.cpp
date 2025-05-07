#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ManageTokens.h"

// Helper to mint and return wallet content
std::vector<std::unique_ptr<NfToken>> cloneWallet(const std::vector<std::unique_ptr<NfToken>>& original) {
    std::vector<std::unique_ptr<NfToken>> copy;
    for (const auto& token : original) {
        copy.emplace_back(std::make_unique<NfToken>(token->name, token->asset, token->hash));
    }
    return copy;
}

TEST_CASE("Minting produces a token with a valid hash") {
    ManageTokens manager;
    manager.mintToken("Alpha", "asset123");

    REQUIRE(manager.wallet1.size() == 1);
    const auto& token = manager.wallet1[0];
    CHECK(token->name == "Alpha");
    CHECK(token->asset == "asset123");
    CHECK(!token->hash.empty());
}

TEST_CASE("Minting two different assets produces different hashes") {
    ManageTokens manager;
    manager.mintToken("Alpha", "asset123");
    manager.mintToken("Beta", "asset456");

    REQUIRE(manager.wallet1.size() == 2);
    CHECK(manager.wallet1[0]->hash != manager.wallet1[1]->hash);
}

TEST_CASE("Transferring tokens moves them correctly between wallets") {
    ManageTokens manager;
    manager.mintToken("A", "x");
    manager.mintToken("B", "y");

    CHECK(manager.wallet1.size() == 2);
    CHECK(manager.wallet2.size() == 0);

    manager.walletTransfer(manager.wallet1, manager.wallet2);

    CHECK(manager.wallet1.empty());
    CHECK(manager.wallet2.size() == 2);
    CHECK(manager.wallet2[0]->name == "B");
    CHECK(manager.wallet2[1]->name == "A");
}