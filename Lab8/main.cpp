#include "ManageTokens.h"
#include <iostream>
#include <chrono>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

void timeComparisons() {
    const int N = 1000000;

    // Timing for int
    auto start = std::chrono::high_resolution_clock::now();
    int x = 0;
    for (int i = 0; i < N; ++i) x += i;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "int time: " << std::chrono::duration<double>(end - start).count() << "s\n";

    // Timing for long
    start = std::chrono::high_resolution_clock::now();
    long y = 0;
    for (long i = 0; i < N; ++i) y += i;
    end = std::chrono::high_resolution_clock::now();
    std::cout << "long time: " << std::chrono::duration<double>(end - start).count() << "s\n";

    // Timing for bigint
    start = std::chrono::high_resolution_clock::now();
    cpp_int z = 0;
    for (int i = 0; i < N; ++i) z += i;
    end = std::chrono::high_resolution_clock::now();
    std::cout << "bigint time: " << std::chrono::duration<double>(end - start).count() << "s\n";
}

int main() {
    ManageTokens manager;

    // Mint NFTs
    manager.mintToken("TokenAlpha", "asset_data_1");
    manager.mintToken("TokenBeta", "asset_data_2");

    // Wallet sizes before transfer
    std::cout << "[Before Transfer] Wallet1: " << manager.wallet1.size()
              << " | Wallet2: " << manager.wallet2.size() << "\n";

    // Transfer NFTs
    manager.walletTransfer(manager.wallet1, manager.wallet2);

    // Wallet sizes after transfer
    std::cout << "[After Transfer] Wallet1: " << manager.wallet1.size()
              << " | Wallet2: " << manager.wallet2.size() << "\n";

    // Timing comparison
    timeComparisons();

    return 0;
}
