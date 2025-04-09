#include "block.h"
#include "sha256.h"
#include <sstream>
#include <iostream>

Block::Block(int idx, const string& prevHash, const string& time, const vector<string>& data)
    : index(idx), previousHash(prevHash), timestamp(time), data(data), nonce(0)
{
    MerkleTree mt(data);
    merkleRoot = mt.getRoot();
    hash = calculateHash();
}

string Block::calculateHash() const {
    stringstream ss;
    ss << index << previousHash << timestamp << merkleRoot << nonce;
    return sha256(ss.str());
}

void Block::mineBlock(int difficulty) {
    string target(difficulty, '0');
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
    cout << "Block mined: " << hash << endl;
}
