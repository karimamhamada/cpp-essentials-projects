#ifndef MANAGETOKENS_H
#define MANAGETOKENS_H

#include "NfToken.h"
#include <vector>
#include <memory>
#include <openssl/sha.h>

class ManageTokens {
public:
    std::vector<std::unique_ptr<NfToken>> wallet1;
    std::vector<std::unique_ptr<NfToken>> wallet2;

    std::string hashAsset(const std::string& data);
    void mintToken(const std::string& name, const std::string& asset);
    void walletTransfer(std::vector<std::unique_ptr<NfToken>>& from, std::vector<std::unique_ptr<NfToken>>& to);
};

#endif // MANAGETOKENS_H
