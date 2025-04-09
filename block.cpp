// block.cpp
#include "block.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

// Constructor initializes block fields
Block::Block(int idx, const string& data, const string& prevHash)
    : index(idx), data(data), previousHash(prevHash), nonce(0) {
    
    // Get current time as string
    time_t now = time(0);
    timestamp = ctime(&now);
    timestamp.pop_back(); // remove newline at end

    // Calculate the initial hash
    hash = calculateHash();
}

// Hash calculation includes index, timestamp, data, prevHash, and nonce
string Block::calculateHash() const {
    stringstream ss;
    ss << index << timestamp << data << previousHash << nonce;
    return SHA256::hash(ss.str());
}

// Perform Proof of Work by finding a hash with leading `difficulty` zeros
void Block::mineBlock(int difficulty) {
    string target(difficulty, '0');  // E.g., difficulty = 4 → target = "0000"

    cout << "Mining block with difficulty " << difficulty << "...\n";

    while (true) {
        hash = calculateHash();
        if (hash.substr(0, difficulty) == target) {
            cout << "✅ Block mined successfully! Hash: " << hash << "\n";
            break;
        }
        nonce++;
    }
}

// Return final block hash
string Block::getHash() const {
    return hash;
}

// Return previous block's hash
string Block::getPreviousHash() const {
    return previousHash;
}

// Return nonce used for mining
int Block::getNonce() const {
    return nonce;
}