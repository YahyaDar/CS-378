#pragma once

#include "common.hpp"
#include <vector>
#include <memory>

struct DiffsetNode {
    Itemset itemset;
    std::vector<uint8_t> diffset_bitset; 
    size_t diffset_size = 0;
};

class DEclat {
public:
    // Compute diffset for a new itemset (Node B \ Node A)
    static DiffsetNode ComputeDiffset(const DiffsetNode& node_A, const DiffsetNode& node_B);

    // Recursive depth-first execution
    static void DFSMine(const std::vector<DiffsetNode>& current_level, size_t min_sup_absolute, std::vector<Itemset>& results);

    // Main Entrypoint
    static std::vector<Itemset> Mine(const TransactionDB& db, float min_sup);
};
