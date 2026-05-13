#include "../include/declat.hpp"
#include <iostream>

DiffsetNode DEclat::ComputeDiffset(const DiffsetNode& node_A, const DiffsetNode& node_B) {
    DiffsetNode result;
    // TODO: Implement Diffset intersection.
    // Perform bitwise operations on node_B.diffset_bitset and node_A.diffset_bitset.
    return result;
}

void DEclat::DFSMine(const std::vector<DiffsetNode>& current_level, size_t min_sup_absolute, std::vector<Itemset>& results) {
    // TODO: Implement depth-first recursion.
    // 1. Iterate through current_level pairs (A, B).
    // 2. Compute new DiffsetNode.
    // 3. If support >= min_sup_absolute, add to next_level vector and results.
    // 4. Recurse with next_level.
}

std::vector<Itemset> DEclat::Mine(const TransactionDB& db, float min_sup) {
    size_t min_sup_absolute = static_cast<size_t>(min_sup * db.num_transactions());
    std::vector<Itemset> all_frequent_itemsets;

    // TODO: Pivot horizontal DB to vertical format, compute initial diffsets, 
    // and kick off DFSMine().
    
    return all_frequent_itemsets;
}
