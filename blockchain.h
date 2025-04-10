#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "block.h"

class Blockchain {
private:
    std::vector<Block> chain;
    int difficulty;

public:
    Blockchain(int difficulty = 2);
    void addBlock(const std::vector<std::string>& transactions);
    bool isChainValid() const;
    void printChain() const;
};

#endif
