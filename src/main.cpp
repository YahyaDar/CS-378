#include <iostream>
#include <string>
#include "../include/common.hpp"
#include "../include/apriori.hpp"
#include "../include/declat.hpp"

int main(int argc, char **argv) {
    if (argc < 4) {
        std::cerr << "Usage: ./cs378_engine <dataset.txt> <min_sup> <algo: apriori|declat>\n";
        return 1;
    }

    std::string filepath = argv[1];
    float min_sup = std::stof(argv[2]);
    std::string algo = argv[3];

    std::cout << "Loading Database...\n";
    // TransactionDB db = TransactionDB::LoadDatabase(filepath);
    
    // TODO: Start high-resolution timer, route to selected algorithm, 
    // output the size of the returned vector, print time elapsed.

    return 0; // RAII will automatically destroy the database memory.
}
