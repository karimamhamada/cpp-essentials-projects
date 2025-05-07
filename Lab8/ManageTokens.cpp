#include "ManageTokens.h"
#include <sstream>
#include <iomanip>

std::string ManageTokens::hashAsset(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);

    std::stringstream ss;
    for (unsigned char c : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    return ss.str();
}

void ManageTokens::mintToken(const std::string& name, const std::string& asset) {
    std::string hashValue = hashAsset(asset);
    wallet1.emplace_back(std::make_unique<NfToken>(name, asset, hashValue));
}

void ManageTokens::walletTransfer(std::vector<std::unique_ptr<NfToken>>& from, std::vector<std::unique_ptr<NfToken>>& to) {
    while (!from.empty()) {
        to.emplace_back(std::move(from.back()));
        from.pop_back();
    }
}
