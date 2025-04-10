#include "block.h"
#include "sha256.h"
#include "merkletree.h"
#include <ctime>
#include <sstream>

Block::Block(int idx, const std::vector<std::string>& transactions, const std::string& prevHash)
    : index(idx), transactions(transactions), prevHash(prevHash), nonce(0) {
    time_t now = time(0);
    timestamp = ctime(&now);
    timestamp.pop_back(); // remove newline
    MerkleTree tree(transactions);
    merkleRoot = tree.getRoot();
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << timestamp << merkleRoot << prevHash << nonce;
    return sha256(ss.str());
}

void Block::mineBlock(int difficulty) {
    std::string prefix(difficulty, '0');
    while (hash.substr(0, difficulty) != prefix) {
        nonce++;
        hash = calculateHash();
    }
}

bool Block::verifyBlock() const {
    MerkleTree tree(transactions);
    return (tree.getRoot() == merkleRoot) && (calculateHash() == hash);
}

std::string Block::getHash() const { return hash; }
std::string Block::getPrevHash() const { return prevHash; }
std::string Block::getMerkleRoot() const { return merkleRoot; }
std::vector<std::string> Block::getTransactions() const { return transactions; }
std::string Block::getTimestamp() const { return timestamp; }
int Block::getIndex() const { return index; }
