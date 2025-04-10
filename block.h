#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>

class Block {
private:
    int index;
    std::string timestamp;
    std::vector<std::string> transactions;
    std::string merkleRoot;
    std::string prevHash;
    std::string hash;
    int nonce;

    std::string calculateHash() const;

public:
    Block(int idx, const std::vector<std::string>& transactions, const std::string& prevHash);

    void mineBlock(int difficulty);
    bool verifyBlock() const;

    std::string getHash() const;
    std::string getPrevHash() const;
    std::string getMerkleRoot() const;
    std::vector<std::string> getTransactions() const;
    std::string getTimestamp() const;
    int getIndex() const;
};

#endif
