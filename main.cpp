#include <iostream>
#include "blockchain.h"

int main() {
    Blockchain supplyChain(2);

    supplyChain.addBlock({
        "Farmer harvested tomatoes in Nashik",
        "Transported to Pune Cold Storage"
    });

    supplyChain.addBlock({
        "Warehouse A packed tomatoes",
        "Shipped to Mumbai Retail Hub"
    });

    supplyChain.printChain();

    std::cout << "Chain valid? " << (supplyChain.isChainValid() ? "Yes ✅" : "No ❌") << std::endl;
    return 0;
}
