// blockchain.h
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#include <vector>
#include <string>

class Blockchain {
private:
    vector<Block> chain;    // The actual blockchain
    int difficulty;         // PoW difficulty (number of leading 0s)

    Block createGenesisBlock();  // The first block in the chain

public:
    Blockchain(int difficulty = 4);           // Constructor
    void addBlock(const string& data);        // Add a block with data
    Block getLastBlock() const;               // Return latest block
    bool isChainValid() const;                // Validate the entire chain
    void printChain() const;                  // Display all blocks
};

#endif
