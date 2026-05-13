#include "../include/apriori.hpp"
#include <iostream>
#include <algorithm>

std::vector<Itemset> Apriori::GenerateCandidates(const std::vector<Itemset>& freq_itemsets) {
    std::vector<Itemset> candidates;
    // TODO: Implement Candidate Generation (k -> k+1)
    // Use std::vector methods and iterators to join itemsets.
    return candidates;
}

std::vector<Itemset> Apriori::Prune(const std::vector<Itemset>& candidates, const std::vector<Itemset>& freq_itemsets) {
    std::vector<Itemset> pruned_candidates;
    // TODO: Implement anti-monotonicity pruning.
    // std::binary_search is highly recommended here if freq_itemsets are sorted.
    return pruned_candidates;
}

void Apriori::CalculateSupport(const TransactionDB& db, std::vector<Itemset>& candidates) {
    // TODO: Implement Support Counting (The I/O Bottleneck)
    // Iterate over transactions and candidates. Consider std::includes.
}

std::vector<Itemset> Apriori::Mine(const TransactionDB& db, float min_sup) {
    size_t min_sup_absolute = static_cast<size_t>(min_sup * db.num_transactions());
    std::vector<Itemset> all_frequent_itemsets;
    
    // TODO: Implement iterative BFS generate-and-test loop.
    return all_frequent_itemsets;
}
