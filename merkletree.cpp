#include "merkletree.h"
#include "sha256.h" // Include your SHA256 implementation
#include <iostream>

MerkleTree::MerkleTree(const vector<string>& transactions) : transactions(transactions) {}

vector<string> MerkleTree::hashLeaves(const vector<string>& transactions) {
    vector<string> hashes;
    for (const string& tx : transactions) {
        hashes.push_back(sha256(tx));
    }
    return hashes;
}

string MerkleTree::buildMerkleRoot(vector<string> hashes) {
    if (hashes.empty()) return "";

    while (hashes.size() > 1) {
        vector<string> newLevel;

        for (size_t i = 0; i < hashes.size(); i += 2) {
            if (i + 1 < hashes.size()) {
                newLevel.push_back(sha256(hashes[i] + hashes[i + 1]));
            } else {
                // If odd number of nodes, duplicate last
                newLevel.push_back(sha256(hashes[i] + hashes[i]));
            }
        }

        hashes = newLevel;
    }

    return hashes[0]; // Merkle Root
}

string MerkleTree::getRoot() {
    return buildMerkleRoot(hashLeaves(transactions));
}
