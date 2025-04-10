#include "blockchain.h"
#include <iostream>

Blockchain::Blockchain(int diff) : difficulty(diff) {
    std::vector<std::string> genesisData = { "Genesis Block" };
    chain.emplace_back(Block(0, genesisData, "0"));
    chain[0].mineBlock(difficulty);
}

void Blockchain::addBlock(const std::vector<std::string>& transactions) {
    int index = chain.size();
    std::string prevHash = chain.back().getHash();
    Block newBlock(index, transactions, prevHash);
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid() const {
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& curr = chain[i];
        const Block& prev = chain[i - 1];

        if (curr.getPrevHash() != prev.getHash() || !curr.verifyBlock()) {
            return false;
        }
    }
    return true;
}

void Blockchain::printChain() const {
    for (const Block& block : chain) {
        std::cout << "Block #" << block.getIndex() << "\n";
        std::cout << "Timestamp: " << block.getTimestamp() << "\n";
        std::cout << "Hash: " << block.getHash() << "\n";
        std::cout << "Previous Hash: " << block.getPrevHash() << "\n";
        std::cout << "Merkle Root: " << block.getMerkleRoot() << "\n";
        std::cout << "Transactions:\n";
        for (const std::string& tx : block.getTransactions()) {
            std::cout << "  - " << tx << "\n";
        }
        std::cout << "-------------------------\n";
    }
}
