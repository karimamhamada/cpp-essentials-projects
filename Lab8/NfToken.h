#ifndef NFTOKEN_H
#define NFTOKEN_H

#include <string>

class NfToken {
public:
    std::string name;
    std::string asset;
    std::string hash;

    NfToken(const std::string& name, const std::string& asset, const std::string& hash)
        : name(name), asset(asset), hash(hash) {}
};

#endif // NFTOKEN_H
