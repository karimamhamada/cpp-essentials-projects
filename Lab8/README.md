# CSE3150_Lab8 – Minting non-fungible tokens and xfer

## Description (from class pdf)
#### The purpose of this lab is to
1. Leverage a the C++ unique_ptr to represent a non-fungible token class
2. This non-fungible token class has several digital wallets to hold non-fungible tokens
To do this we will review non-fungible blockchain tokens.

#### Definitions
- A digital token is a representation of a physical or virtual asset.
- Minting a token is the creation of a digital token given a unique string representing its asset. Of course, having a human-readable name will also be helpful. The minting process uses a
message digest hash function. In C++, in Lab we will use the
- #include <openssl/sha.h>
- Library, where we must then compile with the –lcrypto flag to link the library.
- Linux> g++ myMessageDigestFile.cpp -lcrypto
- A digital wallet for non-fungible tokens NfToken is:vector<unique_ptr<NfToken>> wallet1;


#### Define a C++ class ManageTokens that has the functionality
1. Mint Nfoken – generates a unique number (with extremely high probability) and sets
a digital token’s hash value to this unique number.
2. WalletTransfer tokens – a function to move digital tokens from one wallet to another


## How to run 
1. Compile
```g++ tests.cpp ManageTokens.cpp -lcrypto -o nft_tests```
2. Run the program ```./nft_lab```
3. Run unittests ```./nft_tests```