#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "merkletree.h"

using namespace std;

class Block {
public:
    int index;
    string previousHash;
    string timestamp;
    vector<string> data; // Transactions or file contents
    string merkleRoot;
    string hash;
    int nonce;

    Block(int idx, const string& prevHash, const string& time, const vector<string>& data);

    string calculateHash() const;
    void mineBlock(int difficulty);
};

#endif
