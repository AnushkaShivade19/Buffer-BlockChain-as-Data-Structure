#include "merkletree.h"
#include "sha256.h"

MerkleTree::MerkleTree(const std::vector<std::string>& txs) : transactions(txs) {
    std::vector<std::string> hashedTxs;
    for (auto& tx : transactions) {
        hashedTxs.push_back(sha256(tx));
    }
    root = buildTree(hashedTxs);
}

std::string MerkleTree::buildTree(std::vector<std::string> hashes) {
    if (hashes.empty()) return "";
    while (hashes.size() > 1) {
        std::vector<std::string> newLevel;
        for (size_t i = 0; i < hashes.size(); i += 2) {
            std::string left = hashes[i];
            std::string right = (i + 1 < hashes.size()) ? hashes[i + 1] : left;
            newLevel.push_back(sha256(left + right));
        }
        hashes = newLevel;
    }
    return hashes[0];
}

std::string MerkleTree::getRoot() const {
    return root;
}
