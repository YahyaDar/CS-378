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

    if (candidates.empty()) {
        return pruned_candidates;
    }

    auto LambdaCompare = [](const Itemset& a, const Itemset& b) {
        return a.items < b.items;
    };

    for(size_t i = 0; i < candidates.size(); ++i) {
        bool is_valid = true;
        for(size_t j = 0; j < candidates[i].items.size(); ++j) {
            Itemset subset;
            for(size_t k = 0; k < candidates[i].items.size(); ++k) {
                if(k != j) {
                    subset.items.push_back(candidates[i].items[k]);
                }
            }
            if (std::binary_search(freq_itemsets.begin(), freq_itemsets.end(), subset, LambdaCompare) == false) {
                    is_valid = false;
                    break;
                }

        }
        if(is_valid) {
            pruned_candidates.push_back(candidates[i]);
        }
    }
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
