#ifndef MERKLETREE_H
#define MERKLETREE_H

#include <string>
#include <vector>

class MerkleTree {
private:
    std::vector<std::string> transactions;
    std::string root;
    std::string buildTree(std::vector<std::string> hashes);

public:
    MerkleTree(const std::vector<std::string>& transactions);
    std::string getRoot() const;
};

#endif
