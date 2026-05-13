#pragma once

#include "common.hpp"
#include <vector>

class Apriori {
public:
    // Generate size k+1 candidates from size k frequent itemsets
    static std::vector<Itemset> GenerateCandidates(const std::vector<Itemset>& freq_itemsets);

    // Prune candidates using the anti-monotonicity property
    static std::vector<Itemset> Prune(const std::vector<Itemset>& candidates, const std::vector<Itemset>& freq_itemsets);

    // Scan DB and update support counts
    static void CalculateSupport(const TransactionDB& db, std::vector<Itemset>& candidates);

    // Main Entrypoint
    static std::vector<Itemset> Mine(const TransactionDB& db, float min_sup);
};
