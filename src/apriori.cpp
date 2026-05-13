#include "../include/apriori.hpp"
#include <iostream>
#include <algorithm>

std::vector<Itemset> Apriori::GenerateCandidates(const std::vector<Itemset>& freq_itemsets) {
    std::vector<Itemset> candidates;

    if (freq_itemsets.empty()) {
        return candidates;
    }

    int k = freq_itemsets[0].items.size();

    for(size_t i = 0; i < freq_itemsets.size(); i++) {
        for(size_t j = i + 1; j < freq_itemsets.size(); j++) {
            // Check if the first k-1 items are the same
            if(std::equal(freq_itemsets[i].items.begin(), freq_itemsets[i].items.end() - 1, freq_itemsets[j].items.begin())) {
                Itemset candidate = freq_itemsets[i];
                candidate.items.push_back(freq_itemsets[j].items.back()); // Add the last item of the second itemset
                candidate.support_count = 0;
                candidates.push_back(candidate);
            }
        }
    }

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
