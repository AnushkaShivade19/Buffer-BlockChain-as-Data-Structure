#ifndef MERKLETREE_H
#define MERKLETREE_H

#include <vector>
#include <string>
using namespace std;

class MerkleTree {
public:
    // Constructor that takes a list of transactions
    MerkleTree(const vector<string>& transactions);

    // Function to get the Merkle root
    string getRoot();

private:
    vector<string> hashLeaves(const vector<string>& transactions);
    string buildMerkleRoot(vector<string> hashes);
    string sha256(const string& data); // We'll call your existing sha256 function
    vector<string> transactions;
};

#endif // MERKLETREE_H
